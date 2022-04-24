#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
using namespace std;

string parseFile(string fileName, int &p, int &r);
class Graph {
    private:
        bool **adjMatrix;
        int vertices;

    public:
        Graph(int v);
        ~Graph();
};