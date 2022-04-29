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
    allocationMatrix = new bool*[p];
    for(int i = 0; i < p; i++){
        allocationMatrix[i] = new bool[r];
        for(int j = 0; j < r; j++)
            allocationMatrix[i][j] = false;
    }
    requestMatrix = new bool*[p];
    for(int i = 0; i < p; i++){
        requestMatrix[i] = new bool[r];
        for(int j = 0; j < r; j++)
            requestMatrix[i][j] = false;
    }
     needMatrix = new bool*[p];
    for(int i = 0; i < p; i++){
        needMatrix[i] = new bool[r];
        for(int j = 0; j < r; j++)
            needMatrix[i][j] = false;
    }

    //initializing available resource units
    f = new int[r];
    ans = new int[r];
    for (int k = 0; k < r; k++) {
        f[k] = 0;
        ans[k] = 0;
    }
    resourceUnits = new int[r];
    stringstream ss(units);
    string temp;
    for(int i = 0; i < r; i++)
    {
        getline(ss, temp, ',');
        resourceUnits[i] = stoi(temp);
    }

   
    
}

//destructor 
Graph::~Graph(){
    
    for(int i = 0; i < processes; i++){
        delete [] this->allocationMatrix[i];
        delete [] this->requestMatrix[i];
        delete [] this->needMatrix[i];
    }
    for(int i = 0; i < vertices; i++)
        delete [] this->adjMatrix[i];
    delete [] this->needMatrix;
    delete [] this->allocationMatrix;
    delete [] this->requestMatrix;
    delete [] this->adjMatrix;
    delete [] this->resourceUnits;
    delete [] this->f;
    delete [] this->ans;
    this->needMatrix = NULL;
    this->requestMatrix = NULL;
    this->allocationMatrix = NULL;
    this->adjMatrix = NULL;
    this->resourceUnits = NULL;
    this->f = NULL;
    this->ans = NULL;
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
    cout << " | ";
    for(int i = 0; i < vertices; i++)
        cout << i << " ";
    cout << endl;
    for(int i = 0; i < vertices*2+2; i++)
        cout << "-";
    cout << endl;
    for(int i = 0; i < vertices; i++)
    {
        cout << i << "| ";
        for(int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

//printing current available units for debugging
void Graph::printUnits(){
    for(int i = 0; i < resources; i++){
        cout << "R" << i+1 << ": " << resourceUnits[i] << endl;
    }
}

//breaking down the matrix to get allocation matrix and request allocation 
void Graph::matrixPartitioning(){
    //Getting Allocation Matrix
   
    for(int i = processes; i < vertices; i++){
        for(int j = 0; j < processes; j++){
           if(adjMatrix[i][j] == true){
         
              allocationMatrix[i - processes][j]=adjMatrix[i][j];
            }
        } 
       
    }
   
   //Getting Request Matrix
    for(int i = 0; i < processes; i++){
        for(int j = processes; j < vertices; j++){
            if(adjMatrix[i][j] == true){
           
		requestMatrix[i][j - processes]=adjMatrix[i][j];
            }
        }
       
    }
}

void Graph::bankersAlgorithm(){
     int ind=0, i, j, k;
     // Calculating the need Matrix by equation need = request - allocation
     for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++)
            needMatrix[i][j] = requestMatrix[i][j] - allocationMatrix[i][j];
     }
      // bankers Algorithm
     // check for uncompleted processes 
       for (k = 0; k < processes+1; k++) {
       //Iterate rows
        for (i = 0; i < processes; i++) {
            //checks if finish
              if (f[i] == 0) {
                //if not finish set flag to 0
                int flag = 0;
                //check through the coulumns if need > resource
                for (j = 0; j < resources; j++) {
                    if (needMatrix[i][j] > resourceUnits[j]){
                       // break if need exceeds what we have
                        flag = 1;
                         break;
                    }
                }
 
               if (flag == 0) {
                    //process finished add to  sequence array
                    ans[ind++] = i;
                   // recalculate reaource units
                    for (int y = 0; y < resources; y++)
                        resourceUnits[y] += allocationMatrix[i][y];
                    // i process finished  indicated in finished array 
                      f[i] = 1;
                }
            }
        }
    }
     //after checking for uncompleted process
      int flag = 1;
     
     for(int i=0;i<processes;i++)
    {
     //if any process is left unfinished then deadlock
      if(f[i]==0)
      {
        flag=0;
         printf("Deadlock detected!\n");
        break;
      }
    }
     // checking if it finished checking for uncompleted 
      if(flag==1)
    {
      printf("Following is the SAFE Sequence no deadlock\n");
      for (i = 0; i < processes - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[processes - 1]);
    }





}
