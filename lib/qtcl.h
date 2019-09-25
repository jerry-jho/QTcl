#ifndef QTCL_H
#define QTCL_H

#include <QObject>

class QTclPrivate;

class QTcl : public QObject
{
    Q_OBJECT
public:
    explicit QTcl(QObject *parent = nullptr);
    ~QTcl();
    bool registerObject(QObject * o);
    int  execute(const QString & s);
signals:

public slots:

private:
    QTclPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(QTcl);
};

#endif // QTCL_H
