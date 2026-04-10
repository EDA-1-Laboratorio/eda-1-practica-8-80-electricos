#ifndef LISTADL_CIRCULAR_H
#define LISTADL_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef int DATO;

/* Nodo de la lista doblemente ligada circular */
typedef struct dllista_circular {
    DATO dato;
    struct dllista_circular *previo;
    struct dllista_circular *siguiente;
} dllista_circular;

/* Lista doblemente ligada circular */
typedef struct lista_dl_circular {
    dllista_circular *cabeza;
    int longitud;
} ListaDLCircular;

/*
 * Crea un nodo con el dato proporcionado.
 * Los punteros previo y siguiente se inicializan a NULL.
 * Retorna un puntero al nodo creado, o NULL si falla la asignación.
 */
dllista_circular *crear_elemento_circular(DATO dato);

/*
 * Inicializa una lista doblemente ligada circular vacía.
 * Retorna un puntero a la lista creada, o NULL si falla la asignación.
 */
ListaDLCircular *crear_lista_circular(void);

/*
 * Inserta un nuevo nodo con el dato dado al inicio de la lista.
 */
void insertar_inicio_circular(ListaDLCircular *lista, DATO dato);

/*
 * Inserta un nuevo nodo con el dato dado al final de la lista.
 */
void insertar_final_circular(ListaDLCircular *lista, DATO dato);

/*
 * Inserta un nuevo nodo con el dato dado en la posición indicada (0-indexada).
 * Si la posición es 0, inserta al inicio.
 * Si la posición es igual a la longitud, inserta al final.
 * Si la posición es inválida, no hace nada.
 */
void insertar_en_posicion_circular(ListaDLCircular *lista, DATO dato, int posicion);

/*
 * Elimina el primer nodo de la lista y retorna su dato.
 * Si la lista está vacía, retorna -1.
 */
DATO eliminar_inicio_circular(ListaDLCircular *lista);

/*
 * Elimina el último nodo de la lista y retorna su dato.
 * Si la lista está vacía, retorna -1.
 */
DATO eliminar_final_circular(ListaDLCircular *lista);

/*
 * Elimina el nodo en la posición indicada (0-indexada) y retorna su dato.
 * Si la posición es inválida, retorna -1.
 */
DATO eliminar_en_posicion_circular(ListaDLCircular *lista, int posicion);

/*
 * Busca la primera ocurrencia del dato en la lista.
 * Retorna la posición (0-indexada) si lo encuentra, -1 si no.
 */
int buscar_circular(ListaDLCircular *lista, DATO dato);

/*
 * Obtiene el dato en la posición indicada (0-indexada).
 * Si la posición es inválida, retorna -1.
 */
DATO obtener_circular(ListaDLCircular *lista, int posicion);

/*
 * Retorna 1 si la lista está vacía, 0 en caso contrario.
 */
int esta_vacia_circular(ListaDLCircular *lista);

/*
 * Retorna la longitud de la lista.
 */
int longitud_circular(ListaDLCircular *lista);

/*
 * Imprime la lista de inicio a fin en el formato:
 * [dato0] <-> [dato1] <-> ... <-> [datoN] (circular)
 * Nota: Se detiene después de recorrer todos los elementos una vez.
 */
void imprimir_lista_circular(ListaDLCircular *lista);

/*
 * Imprime la lista de fin a inicio en el formato:
 * [datoN] <-> ... <-> [dato1] <-> [dato0] (circular)
 */
void imprimir_lista_reversa_circular(ListaDLCircular *lista);

/*
 * Libera toda la memoria de la lista, incluyendo sus nodos.
 */
void liberar_lista_circular(ListaDLCircular *lista);

#endif /* LISTADL_CIRCULAR_H */
