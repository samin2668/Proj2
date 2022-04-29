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
        bool **needMatrix;
        bool **requestMatrix;
        bool **allocationMatrix;
	bool **adjMatrix;   //RAG as adjacency matrix - true = edge, false = no edge
        int vertices;   //number of vertices
        int processes;  //number of processes
        int resources;  //number of resources
        int *resourceUnits;  //array to hold available units for each resource
        int *f;
        int *ans;
    public:
        Graph(int p, int r, string units);  //constructor
        ~Graph();   //destructor
        
        void printGraph();
        void printUnits();  //function to print resource array for debugging
        void inputMatrix(string matrix);    //function to set adjacency matrix from a string parsed from the input file
        void matrixPartitioning();   //finding allocation matrix and request matrix
	void bankersAlgorithm(); //finding safe sequence and deadlock
       // string printState();    printing current state -> deadlock/no deadlock
};
