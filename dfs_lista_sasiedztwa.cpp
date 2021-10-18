#include <iostream>
#include <iomanip>

using namespace std;

// Typy dla dynamicznej tablicy list sasiedztwa
struct lista {
    lista * next, *prev;
    int v;
};

int n;                   // Liczba wierzcholkow
lista ** A, *plista;              // Macierz sasiedztwa
char * kolor;          // Tablica odwiedzin

void DFS(int s) {
    lista *q,*head,*tail;
    kolor[s] = 'G'; 
    q = new lista;
    q->next = NULL;
    q->prev = NULL;
    q->v = s;
    head=tail=q;
    cout<<s<<' ';
    

    while(head) {
        s = tail->v;
        plista = A[s];
        while(plista){
            if(kolor[plista->v]=='W'){
                cout << plista->v <<' ';
                q=new lista;
                q->next = NULL;
                q->prev = NULL;
                q->v = plista->v;
        
                tail->next = q;
                q->prev = tail;
                    
                tail = q;
                kolor[plista->v] = 'G'; 
            }
            plista = A[plista->v];
        }
        q = tail;
        tail = tail->prev;
        A[tail->v] = A[tail->v]->next;
        delete q;        
    }   
}

int main() {
    int m,v1,v2;
    lista *p,*r;

    cin >> n >> m;             // Czytamy liczbe wierzcholkow i krawedzi

    A = new lista * [n];       // Tworzymy tablice list sasiedztwa
    kolor = new char[n];     // Tworzymy tablice odwiedzin

    // Tablice wypelniamy pustymi listami
    for(int i = 0; i < n; i++) {
        A[i] = NULL;
        kolor[i] = 'W';
    }

    // Odczytujemy kolejne definicje krawedzi
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;    // Wierzcholek startowy i koncowy krawedzi
        p = new lista;      // Tworzymy nowy element
        p->v = v2;          // Numerujemy go jako v2
        p->next = A[v1];    // Dodajemy go na poczatek listy A[v1]
        p->prev = NULL;
        A[v1] = p;
    }

    cout << endl;
    for(int i = 0; i < n; i++){
        cout << "A[" << i << "] =";
        plista = A[i];
        while(plista){
            cout.width(3);
            cout << plista->v;
            plista = plista->next;
        }
        cout << endl;
    }


    cout << endl;
    cout<<"Odwiedzone wierzcholki: ";
    DFS(0);

    // Usuwamy tablice list sasiedztwa
    for(int i = 0; i < n; i++) {
        p = A[i];
        while(p) {
        r = p;
        p = p->next;
        delete r;
        }
    }
    delete [] A;
    delete [] kolor;

    cout << endl;
    return 0;
}