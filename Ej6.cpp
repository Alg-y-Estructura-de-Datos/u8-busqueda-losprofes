#include <iostream>
#include "Algoritmos Ordenamiento/shellSort.h"  // Para usar Ordenamiento

using namespace std;

// Función de búsqueda binaria recursiva
int busquedaBinariaRecursiva(int arr[], int izquierda, int derecha, int clave) {
    if (izquierda > derecha) {
        return -1; // Caso base: no se encontró la clave
    }

    // Calcular el punto medio
    int medio = izquierda + (derecha - izquierda) / 2;

    // Verificar si la clave está en el medio
    if (arr[medio] == clave) {
        return medio;  // Se encontró la clave, retornar la posición
    }

    // Si la clave es menor, buscar en la mitad izquierda
    if (arr[medio] > clave) {
        return busquedaBinariaRecursiva(arr, izquierda, medio - 1, clave);
    }

    // Si la clave es mayor, buscar en la mitad derecha
    return busquedaBinariaRecursiva(arr, medio + 1, derecha, clave);
}

int main() {
    cout << "Ejercicio 08/06" << endl;

    int n;

    // Solicitar al usuario el número de elementos
    cout << "Ingrese el numero de elementos: ";
    cin >> n;

    // Crear un arreglo dinámico
    int* arr = new int[n];

    // Solicitar al usuario los elementos
    cout << "Ingrese los " << n << " elementos (enteros):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Ordenar el arreglo
    shellSort(arr, n-1);

    // Mostrar el arreglo ordenado
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Solicitar la clave a buscar
    int clave;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> clave;

    // Realizar la búsqueda binaria recursiva
    int resultado = busquedaBinariaRecursiva(arr, 0, n - 1, clave);

    // Mostrar el resultado
    if (resultado != -1) {
        cout << "Numero encontrado en la posicion: " << resultado << endl;
    } else {
        cout << "Numero no encontrado en el arreglo." << endl;
    }

    // Liberar memoria
    delete[] arr;

    return 0;
}
