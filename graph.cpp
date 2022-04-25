#include "header.h"

Graph::Graph(int p, int r, string units)
{
    this->vertices = p + r;
    this->processes = p;
    this->resources = r;
    adjMatrix = new bool*[vertices];
    for(int i = 0; i < vertices; i++){
        adjMatrix[i] = new bool[vertices];
        for(int j = 0; j < vertices; j++)
            adjMatrix[i][j] = false;
    }

    resourceUnits = new int[r];
    stringstream ss(units);
    string temp;
    for(int i = 0; i < r; i++)
    {
        getline(ss, temp, ',');
        resourceUnits[i] = stoi(temp);
    }

}

Graph::~Graph(){
    for(int i = 0; i < vertices; i++)
        delete [] this->adjMatrix[i];
    delete [] this->adjMatrix;
    delete [] this->resourceUnits;
    this->adjMatrix = NULL;
    this->resourceUnits = NULL;
}

void Graph::inputMatrix(string matrix){
    stringstream input(matrix);
    string temp;
    string token;
    bool edge;
    int row = 0;
    while(input >> temp)
    {
        stringstream ss(temp);
        for(int col = 0; col < vertices; col++){
            getline(ss, token, ',');
            if(token == "1")
                adjMatrix[row][col] = 1;
        }
        row++;
    }
}

void Graph::print(){
    cout << " | ";
    for(int i = 0; i < vertices; i++)
        cout << i << " ";
    cout << endl;
    for(int i = 0; i < vertices*2+2; i++)
        cout << "-";
    cout << endl;
    for(int i = 0; i < vertices; i++)
    {
        cout << i << "| ";
        for(int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}