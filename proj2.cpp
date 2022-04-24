#include "header.h"

int main(int arc, char *argv[])
{
    int processNum, resourceNum;
    string input = parseFile(argv[1], processNum, resourceNum);
    cout << input;
    Graph G(processNum + resourceNum);
    return 0;
}
