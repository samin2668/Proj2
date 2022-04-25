#include "header.h"

int main(int arc, char *argv[])
{
    int processNum, resourceNum;
    string input = parseFile(argv[1], processNum, resourceNum);
    Graph G(processNum + resourceNum);
    G.inputMatrix(input);
    G.print();
    return 0;
}
