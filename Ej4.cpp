#include <iostream>
#include "Cola/Cola.h"

using namespace std;

// Función para buscar un número en una cola
bool buscarEnCola(Cola<int>& cola, int clave) {
    while (!cola.esVacia()) {
        if (cola.peek()== clave) {
            return true; // Si encuentra el número
        }
        cola.desencolar(); // Elimina el frente y continúa buscando
    }
    return false; // Si no se encuentra
}

int main() {
    cout << "Ejercicio 08/04" << endl;

    Cola<int> cola;
    int n, numero, clave;

    cout << "Ingrese el numero de elementos para la cola: ";
    cin >> n;

    cout << "Ingrese los elementos de la cola:\n";
    for (int i = 0; i < n; i++) {
        cin >> numero;
        cola.encolar(numero); // Agregar número a la cola
    }

    cout << "Ingrese el numero a buscar: ";
    cin >> clave;

    if (buscarEnCola(cola, clave)) {
        cout << "El numero se encontro en la cola.\n";
    } else {
        cout << "El numero no se encontro en la cola.\n";
    }

    return 0;
}

