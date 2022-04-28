#include "header.h"

int main(int arc, char *argv[])
{
    int processNum, resourceNum;
    string units;
    string input = parseFile(argv[1], processNum, resourceNum, units);
    Graph *G = new Graph(processNum, resourceNum, units);
    G->inputMatrix(input);
    //G->printGraph();
    G->deadlockDetection();
    //G->printUnits();
    cout << G->printState();
    //cout << "\ndone\n";
    delete G;
    G = NULL;
    return 0;
}
