#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

signals:

public slots:
    QString cmd0(QStringList args);
    QString cmd1(QStringList args);
};

#endif // MYCLASS_H
