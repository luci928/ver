#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generarmatriz(char** matriz, int f, int c) {
    srand(time(nullptr));

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            matriz[i][j] = 'A' + rand() % 26; 
        }
    }
}

void imprimirmatriz(char** matriz, int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << " " << matriz[i][j];
        }
        cout << endl;
    }
}



void cambiarval(char** matriz, int p1, int p2,  char val) {
        matriz[p1][p2] = val;   
    }




int main() {
    const int filas = 10;
    const int columnas = 10;


    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }

  
    generarmatriz(matriz, filas, columnas);
    cout << "Matriz generada:\n";
    imprimirmatriz(matriz, filas, columnas);
    cout<<endl;
    cambiarval(matriz,2,2,'A');
    imprimirmatriz(matriz, filas, columnas);

}
