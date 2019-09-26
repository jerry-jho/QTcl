#include "myclass.h"
#include <iostream>

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

QString MyClass::cmd0(QStringList args) {
    std::cout << "invoke cmd0, number of args = "<<args.size() <<std::endl;
    return QString("result_cmd0");
}

QString MyClass::cmd1(QStringList args) {
    std::cout << "invoke cmd1, number of args = "<<args.size() <<std::endl;
    return QString("result_cmd1");
}
