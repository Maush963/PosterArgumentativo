// =================================================================
//
// File: main.cpp
// Author: Mauricio Salas Hernández	- A01710309
// Date: 10/09/2023
//
// =================================================================


#include <iostream>
#include <string>
using namespace std;

void Sort(string* words, int n, int l, int* count) {
    for (int i = 0; i < n; i++) {
        count[i] = 0; // Inicializa el recuento de cada cadena a 0
        for (int k = 0; k < l; k++) {
            for (int z = k + 1; z < l; z++) { // Fijar los límites del bucle y la comparación
                if (words[i][k] > words[i][z]) {
                    count[i]++;
                }
            }
        }
    }
}

int main() {
    int n, l;
    cout << "Ingresa el número de cadenas y su longitud: ";
    cin >> n >> l;
    string* words = new string[n]; // Usar un arreglo dinámico para las cadenas
    int* count = new int[n];   // Usar un arreglo dinámico para contar inversiones
    // Leer las cadenas
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    Sort(words, n, l, count);
    // Ahora ordenamos las cadenas de acuerdo a su número de inversiones de menor a mayor
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (count[i] > count[k]) {
                swap(count[i], count[k]);
                swap(words[i], words[k]);
            }
        }
    }
    // Imprimir las cadenas ordenadas
    for (int i = 0; i < n; i++) {
        cout << words[i] << " " << count[i] << endl;
    }

    // Liberar la memoria 
    delete[] words;
    delete[] count;
    return 0;
}

