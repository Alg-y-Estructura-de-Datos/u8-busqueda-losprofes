#include <iostream>
using namespace std;

// Función de búsqueda secuencial
int busquedaSecuencial(int arr[], int n, int clave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == clave) {
            return i; // Retorna la posición si se encuentra el elemento
        }
    }
    return -1; // Retorna -1 si no se encuentra
}

int main() {
    cout << "Ejercicio 08/01" << endl;

    int n, clave;

    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Ingrese el numero que desea buscar: ";
    cin >> clave;

    int resultado = busquedaSecuencial(arr, n, clave);

    if (resultado == -1) {
        cout << "El numero no se encontro en el arreglo.\n";
    } else {
        cout << "El numero se encontro en la posicion: " << resultado << endl;
    }

    return 0;
}
