#include "listadl_circular.h"

dllista_circular *crear_elemento_circular(DATO dato) {
    dllista_circular *nuevo = (dllista_circular *)malloc(sizeof(dllista_circular));
    if (nuevo == NULL)
        return NULL;
    nuevo->dato = dato;
    nuevo->previo = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

ListaDLCircular *crear_lista_circular(void) {
    ListaDLCircular *lista = (ListaDLCircular *)malloc(sizeof(ListaDLCircular));
    if (lista == NULL)
        return NULL;
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

void insertar_inicio_circular(ListaDLCircular *lista, DATO dato) {
    dllista_circular *nuevo = crear_elemento_circular(dato);
    if (nuevo == NULL)
        return;

    if (lista->cabeza == NULL) {
        // Lista vacía: el nodo se apunta a sí mismo
        lista->cabeza = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->previo = nuevo;
    } else {
        dllista_circular *ultimo = lista->cabeza->previo;
        
        // Insertar al inicio
        nuevo->siguiente = lista->cabeza;
        nuevo->previo = ultimo;
        lista->cabeza->previo = nuevo;
        ultimo->siguiente = nuevo;
        lista->cabeza = nuevo;
    }
    lista->longitud++;
}

void insertar_final_circular(ListaDLCircular *lista, DATO dato) {
    dllista_circular *nuevo = crear_elemento_circular(dato);
    if (nuevo == NULL)
        return;

    if (lista->cabeza == NULL) {
        // Lista vacía: el nodo se apunta a sí mismo
        lista->cabeza = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->previo = nuevo;
    } else {
        dllista_circular *ultimo = lista->cabeza->previo;
        
        // Insertar al final
        nuevo->siguiente = lista->cabeza;
        nuevo->previo = ultimo;
        ultimo->siguiente = nuevo;
        lista->cabeza->previo = nuevo;
    }
    lista->longitud++;
}

void insertar_en_posicion_circular(ListaDLCircular *lista, DATO dato, int posicion) {
    if (posicion < 0 || posicion > lista->longitud)
        return;

    if (posicion == 0) {
        insertar_inicio_circular(lista, dato);
        return;
    }
    if (posicion == lista->longitud) {
        insertar_final_circular(lista, dato);
        return;
    }

    dllista_circular *nuevo = crear_elemento_circular(dato);
    if (nuevo == NULL)
        return;

    dllista_circular *actual = lista->cabeza;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;

    nuevo->previo = actual->previo;
    nuevo->siguiente = actual;
    actual->previo->siguiente = nuevo;
    actual->previo = nuevo;
    lista->longitud++;
}

DATO eliminar_inicio_circular(ListaDLCircular *lista) {
    if (lista->cabeza == NULL)
        return -1;

    dllista_circular *eliminado = lista->cabeza;
    DATO dato = eliminado->dato;

    if (lista->longitud == 1) {
        // Solo un elemento
        lista->cabeza = NULL;
    } else {
        dllista_circular *ultimo = lista->cabeza->previo;
        lista->cabeza = lista->cabeza->siguiente;
        lista->cabeza->previo = ultimo;
        ultimo->siguiente = lista->cabeza;
    }

    free(eliminado);
    lista->longitud--;
    return dato;
}

DATO eliminar_final_circular(ListaDLCircular *lista) {
    if (lista->cabeza == NULL)
        return -1;

    if (lista->longitud == 1) {
        DATO dato = lista->cabeza->dato;
        free(lista->cabeza);
        lista->cabeza = NULL;
        lista->longitud--;
        return dato;
    }

    dllista_circular *ultimo = lista->cabeza->previo;
    dllista_circular *nuevo_ultimo = ultimo->previo;
    DATO dato = ultimo->dato;

    nuevo_ultimo->siguiente = lista->cabeza;
    lista->cabeza->previo = nuevo_ultimo;

    free(ultimo);
    lista->longitud--;
    return dato;
}

DATO eliminar_en_posicion_circular(ListaDLCircular *lista, int posicion) {
    if (posicion < 0 || posicion >= lista->longitud)
        return -1;

    if (posicion == 0)
        return eliminar_inicio_circular(lista);
    if (posicion == lista->longitud - 1)
        return eliminar_final_circular(lista);

    dllista_circular *actual = lista->cabeza;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;

    DATO dato = actual->dato;
    actual->previo->siguiente = actual->siguiente;
    actual->siguiente->previo = actual->previo;
    free(actual);
    lista->longitud--;
    return dato;
}

int buscar_circular(ListaDLCircular *lista, DATO dato) {
    if (lista->cabeza == NULL)
        return -1;

    dllista_circular *actual = lista->cabeza;
    int posicion = 0;
    
    do {
        if (actual->dato == dato)
            return posicion;
        actual = actual->siguiente;
        posicion++;
    } while (actual != lista->cabeza);
    
    return -1;
}

DATO obtener_circular(ListaDLCircular *lista, int posicion) {
    if (posicion < 0 || posicion >= lista->longitud)
        return -1;

    dllista_circular *actual = lista->cabeza;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;
    return actual->dato;
}

int esta_vacia_circular(ListaDLCircular *lista) {
    return lista->cabeza == NULL;
}

int longitud_circular(ListaDLCircular *lista) {
    return lista->longitud;
}

void imprimir_lista_circular(ListaDLCircular *lista) {
    if (lista->cabeza == NULL) {
        printf("Lista vacía (circular)\n");
        return;
    }

    dllista_circular *actual = lista->cabeza;
    do {
        printf("[%d]", actual->dato);
        if (actual->siguiente != lista->cabeza)
            printf(" <-> ");
        actual = actual->siguiente;
    } while (actual != lista->cabeza);
    printf(" (circular)\n");
}

void imprimir_lista_reversa_circular(ListaDLCircular *lista) {
    if (lista->cabeza == NULL) {
        printf("Lista vacía (circular)\n");
        return;
    }

    dllista_circular *actual = lista->cabeza->previo; // Comenzar desde el último
    do {
        printf("[%d]", actual->dato);
        if (actual->previo != lista->cabeza->previo)
            printf(" <-> ");
        actual = actual->previo;
    } while (actual != lista->cabeza->previo);
    printf(" (circular reversa)\n");
}

void liberar_lista_circular(ListaDLCircular *lista) {
    if (lista->cabeza == NULL) {
        free(lista);
        return;
    }

    dllista_circular *actual = lista->cabeza;
    dllista_circular *siguiente;
    
    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != lista->cabeza);
    
    free(lista);
}

