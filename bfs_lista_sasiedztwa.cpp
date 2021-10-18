#include <iostream>
#include<iomanip>

using namespace std;


struct lista{
    lista *next;
    int value;
};

int n;      //liczba wierzcholkow
lista **T;   //macierz sasiedztwa
int *d;     //tablica odleglosci
int *p;     //tablica poprzednikow
char *kolor;//tablica kolorow wierzcholkow
lista *plista, *p1lista;

void BFS(int s) {
    
    lista *q,*head,*tail;
    
    kolor[s] = 'G'; 
    d[s]=0;
    p[s]=-1;
    
    q = new lista;
    q->next = NULL;
    q->value = s;
    head=tail=q;
    

    while(head) {
        s = head->value;
        
        plista = T[s];
        
        while(plista){
            
            if(kolor[plista->value]=='W') {
                
                q=new lista;
                q->next = NULL;
                q->value = plista->value;
                if(!tail){
                    head = q;
                }else{
                    tail->next = q;
                } 
                tail = q;
                d[plista->value] = d[s] + 1; 
                p[plista->value] = s;
                kolor[plista->value] = 'G'; 
            }
            plista = plista->next;
        }
        q=head;
        head=head->next;
        if(!head) tail = NULL;
        delete q;
        
        cout << s<<' ';
        kolor[s] = 'B';
    }
}

int main() {
    int m,i,j,v1,v2;
    
    bool isundirected = false;
    cout << "Podaj V i E" << endl;
    cin >> n >> m;
    T = new lista *[n];
    p = new int[n];
    d = new int[n];
    kolor=new char[n];

    for(i=0;i<n;i++)
        T[i] = new lista;

    for(i=0;i<n;i++) {
        p[i]=-1;
        d[i]=-1;
        kolor[i]='W'; 
        
    }

    for(j=0;j<n;j++) T[j] = NULL;
    
     // Odczytujemy kolejne definicje krawędzi
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;	// Wierzchołek startowy i końcowy krawędzi
        plista = new lista;		// Tworzymy nowy element
        plista->value = v2;      // Numerujemy go jako v2
        plista->next = T[v1];    // Dodajemy go na początek listy A[v1]
        T[v1] = plista;

        if(isundirected){
            p1lista = new lista;		
            p1lista->value = v1;      
            p1lista->next = T[v2];    
            T[v2] = p1lista;
        }
        
    }


    // Wypisujemy zawartość tablicy list sąsiedztwa
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "A[" << i << "] =";
        plista = T[i];
        while(plista){
            cout.width(3);
            cout << plista->value;
            plista = plista->next;
        }
        cout << endl;
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