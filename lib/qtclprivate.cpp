#include "qtclprivate.h"
#include <QtCore>

QTclPrivate::QTclPrivate(QTcl *parent) : q_ptr(parent) {
    interp = Tcl_CreateInterp();
}

QTclPrivate::~QTclPrivate() {
    Tcl_DeleteInterp(interp);
}

bool QTclPrivate::registerObject(QObject * o) {
    const QMetaObject * metaObject = o->metaObject();
    for(int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i) {
        const char * methodName = metaObject->method(i).name().constData();
        Tcl_CreateCommand(interp,methodName,QTclPrivate::tcl_callback,(ClientData)o,nullptr);
    }
    return true;
}

int QTclPrivate::execute(const QString & s) {
    return Tcl_Eval(interp,s.toUtf8().constData());
}

int QTclPrivate::tcl_callback(ClientData d,Tcl_Interp * interp, int argc,const char * argv[]) {
    QObject * o = (QObject *)d;
    QStringList args;
    for (int i=1;i<argc;++i) {
        args << QString::fromUtf8(argv[i]);
    }
    QString r;
    bool ok = QMetaObject::invokeMethod(
        o,
        argv[0],
        Qt::DirectConnection,
        Q_RETURN_ARG(QString,r),
        Q_ARG(QStringList,args)
    );
    if (ok) {
        Tcl_SetResult(interp,r.toUtf8().data(),nullptr);
    }
    return ok ? TCL_OK : TCL_ERROR;
}

