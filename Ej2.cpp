#include <iostream>
using namespace std;

// Función de búsqueda binaria
int busquedaBinaria(int arr[], int izquierda, int derecha, int clave) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Si el elemento está en el medio
        if (arr[medio] == clave)
            return medio;

        // Si el elemento es menor que el del medio, está en el lado izquierdo
        if (arr[medio] > clave)
            derecha = medio - 1;
        // Si el elemento es mayor, está en el lado derecho
        else
            izquierda = medio + 1;
    }

    // Si no se encuentra
    return -1;
}

int main() {
    cout << "Ejercicio 08/02" << endl;

    int n, clave;

    cout << "Ingrese el tamano del arreglo (debe estar ordenado): ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos del arreglo (en orden ascendente):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Ingrese el numero que desea buscar: ";
    cin >> clave;

    int resultado = busquedaBinaria(arr, 0, n - 1, clave);

    if (resultado == -1) {
        cout << "El numero no se encontro en el arreglo.\n";
    } else {
        cout << "El numero se encontro en la posicion: " << resultado << endl;
    }

    return 0;
}
