#include "header.h"

int main(int arc, char *argv[])
{
    int processNum, resourceNum;
    string units;
    string input = parseFile(argv[1], processNum, resourceNum, units);
    Graph G(processNum, resourceNum, units);
    G.inputMatrix(input);
    G.print();
    cout << "\ndone\n";
    return 0;
}
