#include <stdio.h>
#include <stdlib.h>

// Estructura para representar una carga
typedef struct {
  
    int tiempo_llegada;
    int tiempo_atencion;
} Carga;

// Estructura para representar un nodo de la cola enlazada
typedef struct Nodo {
    Carga carga;
    struct Nodo* siguiente;
} Nodo;

// Estructura para representar la cola enlazada
typedef struct {
    int size;
    Nodo* frente;
    Nodo* final;
} Cola;

// Función para inicializar la cola
void inicializarCola(Cola* cola) {
    cola-> size=0;
    cola->frente = NULL;
    cola->final = NULL;
}

// Función para verificar si la cola está vacía

int esColaVacia(Cola* cola){
	if (cola->frente == 0)
		return 1;
	return 0;
	}
Nodo* frente(Cola* cola)
{
    return cola->frente;
}


// Función para agregar una carga a la cola
/*void agregarCarga(Cola* cola, Carga carga) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->carga = carga;
    nuevoNodo->siguiente = NULL;

    if (esColaVacia(cola)==1) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
}*/
void agregarCarga(Cola* cola, Carga carga) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    nuevoNodo->carga = carga;
    nuevoNodo->siguiente = NULL;

    if (esColaVacia(cola)==1) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
        cola->size = 1;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
        cola->size=cola->size+1;
    }
}
void descolar(Cola* cola)
{
    if(cola->size == 1){
        free(cola->frente);
        cola->frente = NULL;
        cola->final = NULL;
        cola->size = 0;
    }
    else if(cola->size > 1){
        Nodo *auxNodo = cola->frente;
        cola->frente = cola->frente->siguiente;
        free(auxNodo);
        cola->size=cola->size-1;
    }
}


void imprimirCola(Cola* cola) {
    Nodo* actual = cola->frente;
 printf(" \n -----------------------------------------------------------------");
    printf(" \n Elementos de la cola: ");

    while (actual != NULL) {
        printf("\n Tiempo en que llego = %d ", actual->carga.tiempo_llegada);
        printf(" ||Numero de Carga = %d", actual->carga.tiempo_atencion);
        actual = actual->siguiente;
    }
 printf(" \n -----------------------------------------------------------------");
    printf("\n");
}


// Función para eliminar y obtener la carga del frente de la cola
Carga eliminarCarga(Cola* cola) {
    if (esColaVacia(cola)==1) {
        printf("Error: la cola esta vacia.\n");
        exit(EXIT_FAILURE);
    }

    Nodo* nodoEliminar = cola->frente;
    Carga carga = nodoEliminar->carga;

    cola->frente = cola->frente->siguiente;
    free(nodoEliminar);

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    return carga;
}
