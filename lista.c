#include "lista.h"
#include <stdlib.h>
#include <stdbool.h>



lista_t* lista_crear(){
    
    lista_t* lista = calloc(1, sizeof(lista_t));
    if(!lista){
        return NULL;
    }
    lista->cantidad = 0;
    return lista;
}

int lista_insertar(lista_t* lista, void* elemento){
    
    if(!lista){
        return -1;
    }
    nodo_t* aux = calloc(1, sizeof(nodo_t));
    if(!aux)
        return -1;
    aux->elemento = elemento;
    
    //esto serian los valores de una cadena/lista nula
    if(lista_vacia(lista)){
        lista->nodo_inicio = aux;
        lista->nodo_fin = aux;
        lista->cantidad = 1;
        return 0;
    }

    lista->nodo_fin->siguiente = aux;
    lista->nodo_fin = aux;
    lista->cantidad += 1;

    return 0;
}

/*
* Recibe el nodo del elemento por el cual debe empezar a contar cunto con la posicion a la que quiere llegar
*
* Devuelve el nodo del elemento anterior al que quiere encontrar
*/
nodo_t* encontrar_posicion(nodo_t* actual, int posicion){
   
    if(posicion > 1){
       return encontrar_posicion(actual->siguiente, posicion-1);
    }
    
    return actual;
} 

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){

    if(!lista){
        return-1;
    }
    //esto seria insertar al final
    if(posicion >= lista->cantidad || lista_vacia(lista)){
        return lista_insertar(lista, elemento);
    }
    nodo_t* aux; 
    nodo_t* nuevo  = calloc(1, sizeof(nodo_t));
    if(!nuevo){
        return -1;
    }
    nuevo->elemento = elemento;
    int i = (int)posicion;

    if(posicion == 0){
        nuevo->siguiente = lista->nodo_inicio;
        lista->nodo_inicio = nuevo;
        lista->cantidad += 1;
        return 0;
    }
    aux = encontrar_posicion(lista->nodo_inicio, i);
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
    lista->cantidad += 1;

    return 0;
}

int lista_borrar(lista_t* lista){

    if(lista_vacia(lista)){
        return -1;
    }
    nodo_t* actual;
    nodo_t* aux;
    int final = (int)lista->cantidad-1;

    if(lista->nodo_fin == lista->nodo_inicio){
        free(lista->nodo_inicio);
        lista->nodo_inicio = NULL;
        lista->nodo_fin = NULL;
        lista->cantidad -= 1;
        return 0;
    }
    actual =  encontrar_posicion(lista->nodo_inicio, final);;
    aux = lista->nodo_fin;
    lista->nodo_fin = actual;
    actual->siguiente = NULL;
    free(aux);
    lista->cantidad -= 1;
    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    
    if(lista_vacia(lista)){
        return -1;
    }
    nodo_t* actual;
    nodo_t* aux;
    int i = (int)posicion;
    
    if(posicion == 0 && lista->cantidad-1 != 0){//si la cantidad de la lista es 0 tengo que insertar al final
        aux = lista->nodo_inicio;
        lista->nodo_inicio = aux->siguiente;
        lista->cantidad -= 1;
        free(aux);
        return 0;
    }
    if(posicion >= lista->cantidad-1 || lista->cantidad-1 == 0){// es cantidad -1 porque empieza a contar desde el 0,entonces el ultimo es cant-1 
        return lista_borrar(lista);
    }

    actual = encontrar_posicion(lista->nodo_inicio, i);
    aux = actual->siguiente;
    actual->siguiente = aux->siguiente;
    lista->cantidad -= 1;
    free(aux);
    return 0;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){

   if(lista_vacia(lista) || lista->cantidad < posicion){
        return NULL;
   }
   if(posicion == 0){
        return lista->nodo_inicio->elemento;
   }
   if(posicion == lista->cantidad){
        return lista->nodo_fin->elemento;
   }
   nodo_t* aux; 
   int i = (int)posicion;
   aux = encontrar_posicion(lista->nodo_inicio->siguiente, i);
   return aux->elemento;
}

void* lista_ultimo(lista_t* lista){
    if(lista_vacia(lista)){
        return NULL;
    }
    return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t* lista){
    if(!lista || (lista->nodo_inicio == NULL && lista->nodo_fin == NULL && lista->cantidad == 0)){
        return true;
    }
    return false;
}

size_t lista_elementos(lista_t* lista){
    if(lista_vacia(lista)){
        return 0;
    }
    return lista->cantidad;
}

int lista_apilar(lista_t* lista, void* elemento){
    return lista_insertar(lista, elemento);
}

int lista_desapilar(lista_t* lista){
    return lista_borrar(lista);
}

void* lista_tope(lista_t* lista){
    
    if(lista_vacia(lista))
        return NULL;
    return lista->nodo_fin->elemento;
}

int lista_encolar(lista_t* lista, void* elemento){
    return lista_insertar(lista, elemento);
}

int lista_desencolar(lista_t* lista){
    if(!lista){
        return -1;        
    }
    return lista_borrar_de_posicion(lista, 0);
}

void* lista_primero(lista_t* lista){
    
    if(lista_vacia(lista))
        return NULL;
    return lista->nodo_inicio->elemento;
}

void lista_destruir(lista_t* lista){
   
   if(lista_vacia(lista)){
        free(lista);
        return;
   }
    nodo_t* aux;
    while(lista->nodo_inicio->siguiente != NULL){
        aux = lista->nodo_inicio->siguiente;
        lista->nodo_inicio->siguiente = aux->siguiente;
        free(aux);
    }
    free(lista->nodo_inicio);
    free(lista);
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){
    
    if(!lista)
        return NULL;
    
    lista_iterador_t* iterador = calloc(1, sizeof(lista_iterador_t));
    if(!iterador)
        return NULL;

    if(lista_vacia(lista))
        return iterador;

    iterador->lista = lista;
    iterador->corriente = lista->nodo_inicio;
    return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    
    if(!iterador)
        return true;

    if(iterador->corriente != NULL && iterador->corriente->siguiente != NULL)
        return true;
    else if(iterador->corriente != NULL && iterador->corriente == iterador->lista->nodo_fin){
        return true;
    }
    return false;
}

bool lista_iterador_avanzar(lista_iterador_t* iterador){
    
    if(iterador->corriente != NULL){
        nodo_t* aux = iterador->corriente->siguiente;
       
        if(iterador->corriente == iterador->lista->nodo_fin){
            iterador->corriente = aux;
            return false;
        }    
        iterador->corriente = aux;
        return true;
    }   

    return false;
}

void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
  
    if(iterador->corriente == NULL){
        return NULL;
    }
    return iterador->corriente->elemento;
}

void lista_iterador_destruir(lista_iterador_t* iterador){
    free(iterador);
}

size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
   
    if(lista_vacia(lista) || !funcion)
        return 0;
   
    nodo_t* actual = lista->nodo_inicio;
    nodo_t* aux;
    int contador = 0;

    while(contador < lista->cantidad && funcion(actual->elemento, contexto)){
        contador++;
        aux = actual;
        actual = aux->siguiente;
    }
    return (size_t)contador;
}

