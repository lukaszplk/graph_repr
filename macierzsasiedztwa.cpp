#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, m, v1, v2;
    char ans;
    int **A;
    bool flag, isundirected;
    cout<<"podaj liczbe wierzcholkow i krawedzi."<<endl;
    cin>> n >> m;
    cout<<"Czy graf jest niezorientowany?(y/n)"<<endl;
    cin>>ans;
    if(ans=='y'){
        isundirected=true;
    }else{
        isundirected=false;
    }
    

    A = new int* [n];

    for(int i=0;i<n;i++){
        A[i] = new int [n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        cin >> v1 >> v2;
        A[v1][v2] = 1;

        if(isundirected){
            A[v2][v1]=1;
        }
    }
    
    
    cout<<"\n ";
    for(int i=0;i<n;i++){
        cout<<setw(3)<<i;
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<n;j++){
            cout<<setw(3)<<A[i][j];
        }
        cout<<endl;
    }
    
    if(!isundirected){
        cout << "\nWierzcholki z petla: ";
        flag = false;
        for (int i = 0; i < n; i++) {
            if (A[i][i] == 1){
                flag = true;
                cout << i << " ";
            }     
        }

        if(!flag) cout<<"brak";
    }
    

    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout << "\nSasiedzi " << i << ": ";
        for (int j = 0; j < n; j++) {
            if (A[i][j]) {
                cout << j << " ";
            }
        }
    }

    
    cout<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout << i<<" jest sasiadem dla: ";
        for (int j = 0; j < n; j++) {
            if (A[j][i]) {
                cout << j << " ";
            }
        }
        cout<<endl;
    }
    


    if(isundirected){
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wierzcholka " << i << ": ";
            int counter = 0;
            for (int j = 0; j < n; j++) {
                counter += A[i][j];
            }
            cout << counter;
        }
    }else{
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wychodzacy wierzcholka " << i << ": ";
            int counter = 0;
            for (int j = 0; j < n; j++) {
                counter += A[i][j];
            }
            cout << counter;
        }

        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wchodzacy wierzcholka " << i << ": ";
            int counter = 0;
            for (int j = 0; j < n; j++) {
                counter += A[j][i];
            }
            cout << counter;
        }
    }

    

    
    cout << "\n\nWierzcholki izolowane: ";
    bool otherflag=true;
    for( int i=0;i<n;i++){
        
        flag = true;
        for (int j = 0; j < n; j++) {
            if(A[i][j] || A[j][i]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<i<<' ';
            otherflag=false;
        }

    }
    if(otherflag) cout<<"brak";


    if(!isundirected){
        cout << "\n\nKrawedzie dwukierunkowe: ";
        flag = true;
        for( int i=0;i<n;i++){
            for (int j = 0; j < n; j++) {
                if(A[i][j] && A[j][i] && i!=j){
                    cout<<"("<<i<<", "<<j<<") ";
                    flag=false;
                }
            }
        }
        if(flag) cout<<"brak";
    }
    


    for(int i=0;i<n;i++){
        delete [] A[i];
    }
    delete [] A;

}