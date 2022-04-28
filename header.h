#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string parseFile(string fileName, int &p, int &r, string &units);
class Graph {
    private:
        bool **adjMatrix;
        int vertices;
        int processes;
        int resources;
        int *resourceUnits;
    public:
        Graph(int p, int r, string units);
        ~Graph();
        bool isDeadlock;
        void printGraph();
        void printUnits();
        void inputMatrix(string matrix);
        void deadlockDetection();
        string printState();
};