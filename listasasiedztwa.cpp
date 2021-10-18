#include <iostream>

using namespace std;


struct lista{
    lista *next;
    int value;
};

int main(){
    int n,m,i,v1,v2;
    lista **A;
    lista *p,*r;
    char ans;
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
	
    A = new lista * [n]; // Tworzymy tablicę list sąsiedztwa

    // Tablicę wypełniamy pustymi listami
    for(i = 0; i < n; i++) A[i] = NULL;

    // Odczytujemy kolejne definicje krawędzi
    for(i = 0; i < m; i++)
    {
        cin >> v1 >> v2;	// Wierzchołek startowy i końcowy krawędzi
        p = new lista;		// Tworzymy nowy element
        p->value = v2;      // Numerujemy go jako v2
        p->next = A[v1];    // Dodajemy go na początek listy A[v1]
        A[v1] = p;
        if(isundirected){
            r = new lista;		// Tworzymy nowy element
            r->value = v1;      // Numerujemy go jako v2
            r->next = A[v2];    // Dodajemy go na początek listy A[v1]
            A[v2] = r;
        }
        
    }

    

    // Wypisujemy zawartość tablicy list sąsiedztwa
    cout << endl;
    for(i = 0; i < n; i++){
        cout << "A[" << i << "] =";
        p = A[i];
        while(p)
        {
        cout.width(3);
        cout << p->value;
        p = p->next;
        }
        cout << endl;
    }

    cout<<endl;
    for(i = 0; i < n; i++){
        cout << "\nSasiedzi " << i << ":";
        p = A[i];
        while(p)
        {
        cout.width(3);
        cout << p->value;
        p = p->next;
        }
    }

    cout<<endl;
    for(i = 0; i < n; i++){
        cout<<endl;
        cout <<i<<" jest sasiadem dla: ";
        for(int j=0;j<n;j++){
            p = A[j];
            while(p){
                if(p->value==i){
                    cout<<j<<" ";
                }
                p = p->next;
            }
        }
        
    }

    if(!isundirected){
        cout << "\n\nWierzcholki z petla: ";
        flag = false;
        for (int i = 0; i < n; i++) {
            p = A[i];
            while(p){
                if(p->value==i){
                    cout<<i<<" ";
                    flag=true;
                }
                p = p->next;
            }  
        }
        if(!flag) cout<<"brak";
    }



    cout << "\n\nWierzcholki izolowane: ";
    bool otherflag=true;
    for( int i=0;i<n;i++){
        flag = true;
        p = A[i];
        while(p){
            if(p->value){
                flag=false;
            }
            p = p->next;
        }

        for(int j=0;j<n;j++){
            p = A[j];
            while(p){
                if(p->value==i){
                    flag=false;
                }
                p = p->next;
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
        for( int i=0;i<n;i++){
            r = A[i];
            while(r){
                for(int j=i+1;j<n;j++){
                    p = A[j];
                    while(p){
                        if(p->value==i && r->value==j){
                            cout<<"{"<<i<<", "<<j<<"} ";
                        }
                        p = p->next;
                    }
                }
                r = r->next;
            }
        }
    }
    
    if(isundirected){
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wierzcholka " << i << ": ";
            int counter = 0;
            p = A[i];
            while(p){
                counter++;
                p = p->next;
            }
            cout << counter;
        }
    }else{
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wychodzacy wierzcholka " << i << ": ";
            int counter = 0;
            p = A[i];
            while(p){
                counter++;
                p = p->next;
            }
            cout << counter;
        }
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout << "\nStopien wchodzacy wierzcholka " << i << ": ";
            int counter = 0;
            for(int j=0;j<n;j++){
                p = A[j];
                while(p){
                    if(p->value==i){
                        counter++;
                    }
                    p = p->next;
                }
            }
            
            cout << counter;
        }
    }
    



    // Usuwamy tablicę list sąsiedztwa
    for(i = 0; i < n; i++)
    {
        p = A[i];
        while(p)
        {
        r = p;
        p = p->next;
        delete r;
        }
    }
    delete [] A;

    cout << endl;

    return 0;
}