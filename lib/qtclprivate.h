#ifndef QTCLPRIVATE_H
#define QTCLPRIVATE_H

#include "qtcl.h"
#include <tcl.h>

class QTclPrivate {
public:
    explicit QTclPrivate(QTcl *parent);
    ~QTclPrivate();
    bool registerObject(QObject * o);
    int  execute(const QString & s);
signals:

public slots:

private:
    QTcl * const q_ptr;
    Q_DECLARE_PUBLIC(QTcl);

private:
    Tcl_Interp * interp;
    static int tcl_callback(ClientData d,Tcl_Interp * interp, int argc,const char * argv[]);
};

#endif // QTCLPRIVATE_H
