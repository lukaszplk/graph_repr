#include <iostream>
#include <iomanip>

using namespace std;

int n;                   
int ** A;               
bool * visited;          

void DFS(int v) {
  int i;

  visited[v] = true;     
  cout << v<<' ';

  
  for(i = 0; i < n; i++)
    if((A[v][i] == 1) && !visited[i]) DFS(i);
}

int main() {
  int m,v1,v2;

  cin >> n >> m;         

  A = new int * [n];    
  visited = new bool[n]; 

  for(int i = 0; i < n; i++){
    A[i] = new int[n];
  }
  
  for(int i = 0; i < n; i++) {
    visited[i] = false;  
    for(int j = 0; j < n; j++){
      A[i][j] = 0;
    }   
  }

  
  for(int i = 0; i < m; i++) {
    cin >> v1 >> v2;    
    A[v1][v2] = 1;      
  }
  cout << endl;
  cout<<"Odwiedzone wierzcholki: ";
  DFS(0);

  
  for(int i = 0; i < n; i++) delete A[i];
  delete [] A;
  delete [] visited;

  cout << endl;
  return 0;
}