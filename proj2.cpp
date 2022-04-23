#include "header.h"

int main(int arc, char *argv[])
{
    string input = parseFile(argv[1]);
    cout << input;
    return 0;
}
