#include "header.h"

//constructor
Graph::Graph(int p, int r, string units)
{
    //initializing matrix
    this->vertices = p + r;
    this->processes = p;
    this->resources = r;
    adjMatrix = new bool*[vertices];
    for(int i = 0; i < vertices; i++){
        adjMatrix[i] = new bool[vertices];
        for(int j = 0; j < vertices; j++)
            adjMatrix[i][j] = false;
    }

    //initializing available resource units
    resourceUnits = new int[r];
    stringstream ss(units);
    string temp;
    for(int i = 0; i < r; i++)
    {
        getline(ss, temp, ',');
        resourceUnits[i] = stoi(temp);
    }

    //default 
    this->isDeadlock = false;
}

//destructor 
Graph::~Graph(){
    for(int i = 0; i < vertices; i++)
        delete [] this->adjMatrix[i];
    delete [] this->adjMatrix;
    delete [] this->resourceUnits;
    this->adjMatrix = NULL;
    this->resourceUnits = NULL;
}

//reading in matrix string and setting edges in graph
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

//printing matrix for debugging
void Graph::printGraph(){
    cout << "Printing the adjacency matrix for the resource graph\n\n";
    cout << "  |";
    for(int i = 0; i < processes; i++)
        cout << "P" << i << "|";
    for(int i = 0; i < resources; i++)
        cout << "R" << i << "|";
    cout << endl;
    for(int i = 0; i < vertices*3+3; i++)
        cout << "-";
    cout << endl;
    for(int i = 0; i < processes; i++)
    {
        cout << "P" << i << "| ";
        for(int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    for(int i = processes; i < vertices; i++)
    {
        cout << "R" << i-resources << "| ";
        for(int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

//printing current available units for debugging
void Graph::printUnits(){
    cout << "Printing the number of units for each resource\n\n";
    for(int i = 0; i < resources; i++){
        cout << "R" << i << ": " << resourceUnits[i] << endl;
    }
}

//for finding deadlocks by walking matrix and removing units from resources 
void Graph::deadlockDetection(){
    //checking allocations
    int r = 0;
    for(int i = processes; i < vertices; i++){
        for(int j = 0; j < processes; j++){
            if(adjMatrix[i][j] == true){
                resourceUnits[r]--;
                if(resourceUnits[r] <= -1)
                    isDeadlock = true;
            }
        }
        r++;
    }
    //checking requests
    r = 0;
    for(int i = 0; i < processes; i++){
        for(int j = processes; j < vertices; j++){
            if(adjMatrix[i][j] == true){
                resourceUnits[r]--;
                if(resourceUnits[r] <= -1)
                    isDeadlock = true;
            }
        }
        r++;
    }
}

//print if the graph is in deadlock or not
string Graph::printState(){
    if(isDeadlock == true)
        return "\nDeadlock Found\n";
    else
        return "\nNo Deadlocks Found\n";
}