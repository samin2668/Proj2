#include "header.h"

int main(int argc, char *argv[])
{
    //Error handling for wrong command-line arguments and for file i/o errors
    try{
        if(argc != 2)
            throw(argc);
        else{
            ifstream file(argv[1]);
            if(file.fail())
            {
                file.close();
                throw exception();
            }
            file.close();
        }
    }

    catch(int c){
        cerr << "ERROR: expected input file name as command-line argument.\n"
            << "Either there too few or too many command-line arguments.\n"
            << "Please refer to README for instructions on how to run program.\n";
            exit(1);
    }

    catch(const exception& e){
        cerr << "ERROR input file could not be opened or could not be found.\n";
        exit(1);
    }

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
