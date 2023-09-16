#include <iostream>
#include <conio.h>


using namespace std;

struct nodo
{
    int valor;
    nodo* NodoIzquierda;
    nodo* NodoDerecha;
};

nodo* insertar(nodo* arbol, int valor) {
    if (arbol == nullptr) {
        nodo* nuevo = new nodo;
        nuevo->valor = valor;
        nuevo->NodoIzquierda = nullptr;
        nuevo->NodoDerecha = nullptr;
        return nuevo;
    }

    if (valor < arbol->valor) {
        arbol->NodoIzquierda = insertar(arbol->NodoIzquierda, valor);
    } else if (valor > arbol->valor) {
        arbol->NodoDerecha = insertar(arbol->NodoDerecha, valor);
    }

    return arbol;
}

void mostrarArbol(nodo* arbol) {
    if (arbol != nullptr) {
        mostrarArbol(arbol->NodoIzquierda);
        cout << arbol->valor << " ";
        mostrarArbol(arbol->NodoDerecha);
    }
}

int main() {
    int valor;
    char respuesta;
    nodo* arbol = nullptr;

    do{
        cout << "MENU:" << endl;
        cout << "1. Insertar un numero" << endl;
        cout << "2. Ver arbol" << endl;
        cout << "3. Salir del programa" << endl;
        cin >> respuesta;
    switch(respuesta){
        case '1':{
            int valor;
                cout << "Digite un numero: ";
                cin >> valor;
				cout<<"\n";
                arbol= insertar(arbol, valor);
                break;
        }
        case '2': {
                if (arbol != nullptr) { 
                    cout << "Arbol: ";
                    mostrarArbol(arbol);
                    cout << "\n";
                } else {
                    cout << "El arbol esta vacio." << endl;
                }
                break;
            }
        case '3':
                cout << "Saliendo del programa..." << endl;
                break;
    }
    }while (respuesta != '3');
    return 0;
}
