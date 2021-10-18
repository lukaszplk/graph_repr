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
        A[i] = new int [m];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        cin >> v1 >> v2;
        if(v1==v2){
            A[v1][i] = 1;    
        }else{
            A[v1][i] = 1;
            A[v2][i] = -1;
        }

        if(isundirected){
            A[v1][i]=1;
            A[v2][i]=1;
        }
    }
    
    
    cout<<"\n ";
    for(int i=0;i<m;i++){
        cout<<setw(3)<<i;
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<m;j++){
            cout<<setw(3)<<A[i][j];
        }
        cout<<endl;
    }
    
    int counter = 0, indeks = -1;
    
    if(!isundirected){
        cout << "\nWierzcholki z petla: ";
        flag = false;
        for(int i=0;i<n;i++){
            for (int j = 0; j < m; j++) {
                if (A[j][i] == 1 || A[j][i] == -1){
                    counter++;
                    indeks = j;
                }     
            }
            if(counter==1){
                cout<<indeks<<' ';
                flag = true;
        }
        counter = 0;
        indeks = -1;
        }
            
        if(!flag) cout<<"brak";
    }
    
    
    

    cout<<endl;

    if(!isundirected){
        for (int i = 0; i < n; i++) {
            cout << "\nSasiedzi " << i << ": ";
            for (int j = 0; j < m; j++) {
                if (A[i][j]==1){
                    for(int a=0;a<n;a++){
                        if(A[a][j] == -1){
                            
                            cout << a << " ";
                        }
                    }
                }
            }
        }
    }else{
        for (int i = 0; i < n; i++) {
            cout << "\nSasiedzi " << i << ": ";
            for (int j = 0; j < m; j++) {
                if (A[i][j]==1){
                    for(int a=0;a<n;a++){
                        if(a==i){
                            continue;
                        }
                        if(A[a][j] == 1){
                            
                            cout << a << " ";
                        }
                    }
                }
            }
        }
    }
    

    
    cout<<endl;
    if(!isundirected){
        for (int i = 0; i < n; i++) {
            cout <<"\n"<< i<<" jest sasiadem dla: ";
            for (int j = 0; j < m; j++) {
                if (A[i][j]==-1){
                    for(int a=0;a<n;a++){
                        if(A[a][j] == 1){
                            
                            cout << a << " ";
                        }
                    }
                }
            }
        }
    }else{
        for (int i = 0; i < n; i++) {
            cout <<"\n"<< i<<" jest sasiadem dla: ";
            for (int j = 0; j < m; j++) {
                if (A[i][j]==1){
                    for(int a=0;a<n;a++){
                        if(a==i){
                            continue;
                        }
                        if(A[a][j] == 1){
                            
                            cout << a << " ";
                        }
                    }
                }
            }
        }
    }
    
    


    if(isundirected){
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wierzcholka " << i << ": ";
            int counter = 0;
            for (int j = 0; j < m; j++) {
                counter += A[i][j];
            }
            cout << counter;
        }
    }else{
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wychodzacy wierzcholka " << i << ": ";
            int counter = 0;
            for (int j = 0; j < m; j++) {
                if(A[i][j]==1){
                    counter++;
                }
                
            }
            cout << counter;
        }

        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wchodzacy wierzcholka " << i << ": ";
            int counter = 0;
            for (int j = 0; j < m; j++) {
                if(A[i][j]==-1){
                    counter++;
                }
            }
            cout << counter;
        }
    }

    

    
    cout << "\n\nWierzcholki izolowane: ";
    bool otherflag=true;
    for( int i=0;i<n;i++){
        
        flag = true;
        for (int j = 0; j < m; j++) {
            if(A[i][j]==1 || A[i][j]==-1){
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
        cout<<endl<<endl;
        cout<<"Krawedzie dwukierunkowe: ";
        if(!isundirected){
            for( int i=0;i<n;i++){
                for (int j = 0; j < m; j++) {
                    if (A[i][j]==1){
                        for(int a=0;a<n;a++){
                            if(A[a][j] == -1){ 
                                for(int b=0;b<m;b++){
                                    if(A[a][b]==1 && A[i][b]==-1){
                                        cout<<"("<<i<<", "<<a<<") ";
                                        
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }  
        }
    }
    



    for(int i=0;i<n;i++){
        delete [] A[i];
    }
    delete [] A;

}