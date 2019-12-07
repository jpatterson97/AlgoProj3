#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

void addEdge(vector<vector<char>>adjMat,char v1, char v2) {
   adjMat[v1][v2]=1;
   adjMat[v2][v1]=1;
}
 
void traverseGraph(char s, char V){
     vector<bool> visited(V, false); 
  
    // Create a stack for DFS 
    stack<int> stack; 
  
    // Push the current source node. 
    stack.push(s); 
  
    while (!stack.empty()) 
    { 
        // Pop a vertex from stack and print it 
        s = stack.top(); 
        stack.pop(); 
  
        // Stack may contain same vertex twice. So 
        // we need to print the popped item only 
        // if it is not visited. 
        if (!visited[s]) 
        { 
            cout << s << " "; 
            visited[s] = true; 
        } 
  
        // Get all adjacent vertices of the popped vertex s 
        // If a adjacent has not been visited, then push it 
        // to the stack. 
        for (int i=0; i < visited.size(); i++) 
            if (!visited[i]) 
                stack.push(i); 
    
    }
}


int main() {
	ifstream file;
	ifstream outF;
	string inputFile = "input.txt";
	string binaryBit;
	file.open(inputFile);
	ofstream out;
	out.open("output.txt");
	int levels,rows,columns,startlevel,startrow,startcol,endlevel,endrow,endcol;
	bool north, east,south, west,up, down;

	vector<vector<char>>arrBinary;
	vector<char>temp;
	vector<char>path;
	file>>levels>>rows>>columns>>startlevel>>startrow>>startcol>>endlevel>>endrow>>endcol;
	cout<<levels<<rows<<columns<<startlevel<<startrow<<startcol<<endlevel<<endrow<<endcol<<endl;
	while (file >> binaryBit) {
	    for(int i = 0; i < binaryBit.size(); i++)
	    {
	        temp.push_back(binaryBit[i]);
	    }
	    arrBinary.push_back(temp);
	}
	
	cout<<"done";
	for(int i  = 0;  i  <  arrBinary.size(); i++)
	{
	    for(int j =  0;j <arrBinary[i].size(); j++)
	    {
	        traverseGraph(i,j);
	        	if(arrBinary[i][j]=='1'){
	                north=true;
	                addEdge(arrBinary,i,j);
	                path.push_back('N');
	                out<<"N ";
	            }
	            if(arrBinary[i][j]=='1'){
	               east=true;
	               addEdge(arrBinary,i,j);
	               path.push_back('E');
	               out<<"E ";
	            }
	            if(arrBinary[i][j]=='1'){
	               south=true;
	               addEdge(arrBinary,i,j);
	               path.push_back('S');
	               out<<"S ";
	            }
	            if(arrBinary[i][j]=='1'){
	                west=true;
	               addEdge(arrBinary,i,j);
	               path.push_back('W');
	               out<<"W ";
	            }
	            if(arrBinary[i][j]=='1'){
	                up=true;
	               addEdge(arrBinary,i,j);
	               path.push_back('U');
	               out<<"U ";
	            }
	           if(arrBinary[i][j]=='1'){
	                down=true;
	               addEdge(arrBinary,i,j);
	               path.push_back('D');
	               out<<"D ";
	           }
	    }
	}
	for(int z=0;z<path.size();z++){
	    out<<path.at(z);
	}
	cout<<"done";
	
return 0;
}
