#include <iostream>
#include<iomanip>

using namespace std;

struct kolejka {
    kolejka *next;
    int data;
};

int n;      //liczba wierzcholkow
int **T;   //macierz sasiedztwa
int *d;     //tablica odleglosci
int *p;     //tablica poprzednikow
char *kolor;//tablica kolorow wierzcholkow

void BFS(int s) {
    
    kolejka *q,*head,*tail;
    kolor[s] = 'G'; 
    d[s]=0;
    p[s]=-1;
    
    q = new kolejka;
    q->next = NULL;
    q->data = s;
    head=tail=q;

    while(head) {
        s = head->data; 
        for(int i=0;i<n;i++){
            if((T[s][i]==1) && kolor[i]=='W') {
                q=new kolejka;
                q->next = NULL;
                q->data = i;
                if(!tail) head = q;
                else tail->next = q;
                tail = q;
                d[i] = d[s] + 1; 
                p[i] = s;
                kolor[i] = 'G'; 
            }
        }
        q=head;
        head=head->next;
        if(!head) tail = NULL;
        delete q;
        cout.width(3);
        cout << s;
        kolor[s] = 'B';
    }
}

int main() {
    int m,i,j,v1,v2;
    cout << "Podaj V i E" << endl;
    cin >> n >> m;
    T = new int *[n];
    p = new int[n];
    d = new int[n];
    kolor=new char[n];

    for(i=0;i<n;i++)
        T[i] = new int[n];

    for(i=0;i<n;i++) {
        p[i]=-1;
        d[i]=-1;
        kolor[i]='W'; 
        for(j=0;j<n;j++) T[i][j] = 0;
    }
    
    cout << "Podaj krawedzie" << endl;
    for(i=0;i<m;i++) {
        cin >> v1 >> v2;
        T[v1][v2]=1;
    }


    cout<<"\n Macierz sasiedztwa.\n ";
    for(int i=0;i<n;i++){
        cout<<setw(3)<<i;
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<n;j++){
            cout<<setw(3)<<T[i][j];
        }
        cout<<endl;
    }


    cout << endl;
    cout<<"Wierzcholki w kolejnosci odwiedzania: ";
    BFS(1);

    cout << endl<<endl;
    

    cout << "ODLEGLOSCI" << endl;
    for(i=0;i<n;i++) cout << d[i] << " ";
    cout << endl;

    cout << "POPRZEDNICY" << endl;
    for(i=0;i<n;i++) cout << p[i] << " ";
    cout << endl;

    //czyszczenie pamieci
    delete [] kolor;
    delete [] p;
    delete [] d;
    for(i=0;i<n;i++) delete T[i];
    delete [] T;
    cout << endl;
    return 0;
}