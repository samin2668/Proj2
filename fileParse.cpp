#include "header.h"

string parseFile(string fileName, int &p, int &r, string &units){
    
    //string variables for parsing
    string proc = "num_processes";
    string reso = "num_resources";
    string resourcesVal;
    string matrix = "";
    ifstream ifs(fileName);
    string temp;
    stringstream ss;

    //removing comments
    while(getline(ifs, temp)){
        if(!temp.empty())
        {
            if (temp.find("%") == string::npos)
                ss << temp << endl;
        }    
    }

    //geting resource and process count
    string input;
    while(ss >> temp){
        if (temp.find(proc) != std::string::npos){
            p = stoi(temp.substr(temp.find('=') + 1));
        }  
        else if (temp.find(reso) != std::string::npos){
            r = stoi(temp.substr(temp.find('=') + 1));
        }
        else
            input += temp + "\n";
    }

    //getting resource units as string
    ss.str("");
    ss.clear();
    ss << input;
    ss >> resourcesVal;
    units = resourcesVal;

    //getting matrix as string
    while(ss >> temp)
        matrix += temp + "\n";
    ss.str("");
    ss.clear();

    return matrix;
}