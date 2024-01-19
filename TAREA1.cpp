#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

bool esPrimo(int numero) {
    if (numero < 2) {
        return false;
    }

    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}

void imprimirMatriz(int matriz[][10], int filas, int columnas) {
    for (int fil = 0; fil < filas; fil++) {
        for (int col = 0; col < columnas; col++) {
            cout << matriz[fil][col] << "\t";
        }
        cout << endl;
    }
}

void identificarMayorMenor(int matriz[][10], int filas, int columnas, int& mayor, int& menor) {
    mayor = matriz[0][0];
    menor = matriz[0][0];

    for (int fil = 0; fil < filas; fil++) {
        for (int col = 0; col < columnas; col++) {
            // a
            if (matriz[fil][col] > mayor) {
                mayor = matriz[fil][col];
            }

            // e
            if (matriz[fil][col] < menor) {
                menor = matriz[fil][col];
            }
        }
    }
}

void cambiarNumeroEnMatriz(int matriz[][10], int filas, int columnas, int numeroBuscar, int nuevoNumero) {
    for (int fil = 0; fil < filas; fil++) {
        for (int col = 0; col < columnas; col++) {
            if (matriz[fil][col] == numeroBuscar) {
                matriz[fil][col] = nuevoNumero;
            }
        }
    }
}

int main() {
    const int filas = 10;
    const int columnas = 10;
    int matriz[filas][columnas];

    std::srand(std::time(nullptr));

    // 1 y 100
    for (int fil = 0; fil < filas; fil++) {
        for (int col = 0; col < columnas; col++) {
            matriz[fil][col] = rand() % 100 + 1;
        }
    }

    cout << "Matriz original:\n";
    imprimirMatriz(matriz, filas, columnas);

    ////////////////////////////////////////////
    int mayor, menor;
    identificarMayorMenor(matriz, filas, columnas, mayor, menor);
    cout << "\nNúmero mayor en la matriz: " << mayor << endl;
    cout << "Número menor en la matriz: " << menor << endl;

    //prmos
    cout << "\nNúmeros primos en la matriz:\n";
    for (int fil = 0; fil < filas; fil++) {
        for (int col = 0; col < columnas; col++) {
            if (esPrimo(matriz[fil][col])) {
                cout << matriz[fil][col] << "//";
            }
        }
    }
    cout << endl;

    //cambiar
    int numeroBuscar, nuevoNumero;
    cout << "\nIngrese el número que desea buscar en la matriz: ";
    cin >> numeroBuscar;
    cout << "Ingrese el nuevo número con el que desea reemplazarlo: ";
    cin >> nuevoNumero;

    cambiarNumeroEnMatriz(matriz, filas, columnas, numeroBuscar, nuevoNumero);

    cout << "\nMatriz después de cambiar el número:\n";
    imprimirMatriz(matriz, filas, columnas);

    return 0;
}
