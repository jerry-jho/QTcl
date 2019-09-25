#include "qtcl.h"
#include "qtclprivate.h"

QTcl::QTcl(QObject *parent)
    : QObject(parent)
    , d_ptr(new QTclPrivate(this)) {

}


QTcl::~QTcl () {
    Q_D(QTcl);
    delete d;
}

bool QTcl::registerObject(QObject * o) {
    Q_D(QTcl);
    return d->registerObject(o);
}

int QTcl::execute(const QString & s) {
    Q_D(QTcl);
    return d->execute(s);
}
