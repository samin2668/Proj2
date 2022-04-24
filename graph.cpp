#include "header.h"

Graph::Graph(int v)
{
    this->vertices = v;
    adjMatrix = new bool*[vertices];
    for(int i = 0; i < vertices; i++){
        adjMatrix[i] = new bool[vertices];
        for(int j = 0; j < vertices; j++)
            adjMatrix[i][j] = false;
    }
}

Graph::~Graph(){
    for(int i = 0; i < vertices; i++)
        delete [] this->adjMatrix[i];
    delete [] this->adjMatrix;
    this->adjMatrix = NULL;
}