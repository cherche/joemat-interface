#include <stdio.h>
#include "interface.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    const char* s = "[1 0 0 0;0 1 0 0;0 0 1 0;0 0 0 0]";

    int r = rank(s);
    cout << r << endl;

    return 0;
}
