#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//function to parse input file
string parseFile(string fileName, int &p, int &r, string &units);

//class for resource allocation graph
class Graph {
    private:
        bool **adjMatrix;   //RAG as adjacency matrix - true = edge, false = no edge
        int vertices;   //number of vertices
        int processes;  //number of processes
        int resources;  //number of resources
        int *resourceUnits; //array to hold available units for each resource
    public:
        Graph(int p, int r, string units);  //constructor
        ~Graph();   //destructor
        bool isDeadlock;    //true = deadlock present, false = no deadlock present
        void printGraph();  //function to print graph for debugging
        void printUnits();  //function to print resource array for debugging
        void inputMatrix(string matrix);    //function to set adjacency matrix from a string parsed from the input file
        void deadlockDetection();   //finding deadlocks
        string printState();    //printing current state -> deadlock/no deadlock
};