#include <iostream>
#include "Pila/Pila.h"

using namespace std;

// Función para buscar un número en una pila
bool buscarEnPila(Pila<int> pila, int clave) {
    while (!pila.esVacia()) {
        if (pila.peek() == clave) {
            return true; // Si encuentra el número
        }
        pila.pop(); // Elimina el elemento superior y continúa buscando
    }
    return false; // Si no se encuentra el número
}

int main() {
    cout << "Ejercicio 08/03" << endl;

    Pila<int> pila;
    int n, numero, clave;

    cout << "Ingrese el numero de elementos para la pila: ";
    cin >> n;

    cout << "Ingrese los elementos de la pila:\n";
    for (int i = 0; i < n; i++) {
        cin >> numero;
        pila.push(numero); // Agregar número a la pila
    }

    cout << "Ingrese el numero a buscar: ";
    cin >> clave;

    if (buscarEnPila(pila, clave)) {
        cout << "El numero se encontro en la pila.\n";
    } else {
        cout << "El numero no se encontro en la pila.\n";
    }

    return 0;
}
