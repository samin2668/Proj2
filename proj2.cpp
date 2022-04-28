#include "header.h"

int main(int arc, char *argv[])
{
    int processNum, resourceNum;
    string units;

    //parse the input file and extract data as stirngs
    string input = parseFile(argv[1], processNum, resourceNum, units);

    //initializing graph
    Graph *G = new Graph(processNum, resourceNum, units);

    //reading in matrix 
    G->inputMatrix(input);

    //G->printGraph();

    //determine if graph is in deadlock
    G->deadlockDetection();

    //G->printUnits();

    //printing the current state of graph
    cout << G->printState();

    //cout << "\ndone\n";

    //deallocating
    delete G;
    G = NULL;
    return 0;
}
