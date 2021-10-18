#include <iostream>
#include <iomanip>

using namespace std;

// Typy dla dynamicznej tablicy list sasiedztwa
struct lista {
    lista * next;
    int v;
};

int n;                   // Liczba wierzcholkow
lista ** A;              // Macierz sasiedztwa
bool * visited;          // Tablica odwiedzin

void DFS(int v) {
    lista * p;

    visited[v] = true;     // Zaznaczamy wezel jako odwiedzony
    cout << setw(3) << v;  // Wypisujemy numer wezla

    // Rekurencyjnie odwiedzamy nieodwiedzonych sasiadow
    for(p = A[v]; p; p = p->next){
        if(!visited[p->v]){
            DFS(p->v);
        } 
    }
        
}

int main() {
    int m,v1,v2;
    lista *p,*r;

    cin >> n >> m;             // Czytamy liczbe wierzcholkow i krawedzi

    A = new lista * [n];       // Tworzymy tablice list sasiedztwa
    visited = new bool[n];     // Tworzymy tablice odwiedzin

    // Tablice wypelniamy pustymi listami
    for(int i = 0; i < n; i++) {
        A[i] = NULL;
        visited[i] = false;
    }

    // Odczytujemy kolejne definicje krawedzi
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;    // Wierzcholek startowy i koncowy krawedzi
        p = new lista;      // Tworzymy nowy element
        p->v = v2;          // Numerujemy go jako v2
        p->next = A[v1];    // Dodajemy go na poczatek listy A[v1]
        A[v1] = p;
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
    delete [] visited;

    cout << endl;
    return 0;
}