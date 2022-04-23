#include "header.h"

string parseFile(string fileName)
{
    ifstream ifs(fileName);
    string temp;
    stringstream ss;
    while(getline(ifs, temp))
    {
        if(!temp.empty())
        {
            if (temp.find("%") == std::string::npos)
                ss << temp << endl;
        }    
    }
    string input;
    while(ss >> temp)
    {
        input += temp + "\n";
    }
    return input;
}