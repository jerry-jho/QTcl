#include "myclass.h"
#include "../lib/qtcl.h"
#include <readline/readline.h>

int main(int argc,char **argv) {
    MyClass cls;
    QTcl tcl;
    tcl.registerObject(&cls);
    tcl.execute(argv[1]);
    return 0;
}
