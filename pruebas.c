#include "lista.h"
#include "pa2mm.h"

void cuandocreounalista_secreaunalistavacia(){
	lista_t* lista = lista_crear();
	pa2m_afirmar((lista_vacia(lista)) == true, "Se crea una lista vacia.");
	lista_destruir(lista);
}

void dadounalistaNULL_cuadnollamoalistainsertar_devuelveMENOSUNO(){
    lista_t* lista = NULL;
    int resultado;
    int elemento = 32;
    pa2m_afirmar((resultado = lista_insertar(lista, &elemento)) == -1, "Insertar un elemento en una lista inexistente devuelve -1.");
}

void dadounalista_cuandoinserto3elementos_lalistatiene3elementos(){
    
    lista_t* lista = lista_crear();
    char a='a', b='b', c='c';
    int resultado;

    pa2m_afirmar((resultado = lista_insertar(lista, &a)) == 0, "Inserta un elemento en una lista corretamente.");
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);

    if(lista_elemento_en_posicion(lista, 0) == &a && lista_elemento_en_posicion(lista, 1) == &b && lista_elemento_en_posicion(lista, 2) == &c){
    	pa2m_afirmar(1 == 1, "Los 3 elementos se insertertaron corretamente");
    }
    else{
    	pa2m_afirmar(0 == 1, "Los 3 elementos se insertertaron corretamente");
    }
    lista_destruir(lista);
}

void lista_insertar_posicion_con_lista_NULL_devuelve_menos_uno(){
	lista_t* lista = NULL;
	char a='a', b='b', c='c';

	pa2m_afirmar((lista_insertar_en_posicion(lista, &a, 0)) == -1, "Insertar en posicion inicial lista NULL, devuelve -1");
	pa2m_afirmar((lista_insertar_en_posicion(lista, &b, 1)) == -1, "Insertar en posicion 1 en lista NULL, devuelve -1");
	pa2m_afirmar((lista_insertar_en_posicion(lista, &c, 200)) == -1, "Insertar posicion mayor al tamaño de la lista en lista NULL, devuelve -1");
}

void dadounalista_cuadnollamoalistainsertarenpos_insertacorrectamente(){
    
    lista_t* lista = lista_crear();
    char a='a', b='b', c='c', r='r', s='s', t='t', u='u', w='w';
    lista_insertar(lista, &r);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &u);
    lista_insertar(lista, &w);

    //lista_insertar_en_posicion(lista, &a, 0);
    pa2m_afirmar((lista_insertar_en_posicion(lista, &a, 0)) == 0, "Puedo insertar un elemento en la posicion inicial.");
    //lista_insertar_en_posicion(lista, &b, 4);
    pa2m_afirmar((lista_insertar_en_posicion(lista, &b, 4)) == 0, "Puedo insertar otro elemento en la posicion 4.");
    //lista_insertar_en_posicion(lista, &c, 100);
    pa2m_afirmar((lista_insertar_en_posicion(lista, &c, 100)) == 0, "Puedo insertar otro elemento en la posicion 100.");

    
    pa2m_afirmar((lista_elemento_en_posicion(lista, 0)) == &a, "El elemento se inserto en la posicion inicial.");
    pa2m_afirmar((lista_elemento_en_posicion(lista, 4)) == &b, "El elemento se inserto en la cuarta posicion.");
    pa2m_afirmar((lista_elemento_en_posicion(lista, lista->cantidad-1)) == &c, "Insertar elemento en posicion mayor a la cantidad de elementos en la lista lo inserta en la ultima posicion.");

    lista_destruir(lista);
}

void lista_borrar_con_lista_NULL_devuelve_menos_uno(){
	lista_t* lista = NULL;

	pa2m_afirmar((lista_borrar(lista)) == -1, "Eliminar en lista NULL, devuelve -1");
}

void dadounalista_cuadnollamoalistaborrar_borraelultimoelemento(){

	lista_t* lista = lista_crear();
	int resultado;
    char r='a', s='b', t='c', a='s';
    lista_insertar(lista, &r);
    lista_insertar(lista, &a);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);

    pa2m_afirmar((resultado = lista_borrar(lista)) == 0, "Borrar un elemento en una lista de 4 elementos devuelve 0.");
    pa2m_afirmar((resultado = lista_borrar(lista)) == 0, "Borrar un elemento en una lista de 3 elementos devuelve 0.");
    pa2m_afirmar((resultado = lista_borrar(lista)) == 0, "Borrar un elemento en una lista de 2 elementos devuelve 0.");
    pa2m_afirmar((resultado = lista_borrar(lista)) == 0, "Borrar un elemento en una lista de 1 elementos devuelve 0.");
    pa2m_afirmar((resultado = lista_borrar(lista)) == -1, "Borrar un elemento en una lista de 0 elementos devuelve -1.");

    //solo hago free de ola lista porque en este ejmplo vacio toda la lista borrando cada elemento
    //lista_destruir(lista);
    free(lista);
}

void lista_borrar_posicion_con_lista_NULL_devuelve_menos_uno(){
	lista_t* lista = NULL;

	pa2m_afirmar((lista_borrar_de_posicion(lista, 0)) == -1, "Eliminar en lista NULL, devuelve -1");
	//pa2m_afirmar((lista_borrar_de_posicion(lista, 1)) == -1, "La lista esta vacia, devuelve NULL");
	//pa2m_afirmar((lista_borrar_de_posicion(lista, 1000)) == -1, "La lista esta vacia, devuelve NULL");
}

void dadounalistade4_cuadopidoqueborreel3_borraelelementopedido(){

	lista_t* lista = lista_crear();
    char r='a', s='b', t='c', u='d';
    lista_insertar(lista, &r);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &u);

    pa2m_afirmar((lista_elemento_en_posicion(lista, 2)) == &t, "El elemento 2 es el elemnto 2.");
    
    lista_borrar_de_posicion(lista, 2);

    pa2m_afirmar((lista_elemento_en_posicion(lista, 2)) == &u, "El elemento 3 ahora es el elemnto 2.");

    lista_destruir(lista);
}

void dadounalista_cuadnollamoalistaborrarporposicion_borraelelementopedido(){
	
	lista_t* lista = lista_crear();
    char e_0='a', e_1='b', e_2='c', e_3='d', e_4='r';
    lista_insertar(lista, &e_0);
    lista_insertar(lista, &e_1);
    lista_insertar(lista, &e_2);
    lista_insertar(lista, &e_3);
    lista_insertar(lista, &e_4);

    pa2m_afirmar((lista_elemento_en_posicion(lista, 0)) != &e_1, "El elemento 1 NO se encuentra en la posicion principal.");

    pa2m_afirmar((lista_borrar_de_posicion(lista, 0)) == 0, "Se elimina correctamente un elemento en la posicion inicial.");

    pa2m_afirmar((lista_elemento_en_posicion(lista, 0)) == &e_1, "El elemento 1 ahora es el elemento inicial.");

    pa2m_afirmar((lista_borrar_de_posicion(lista, lista->cantidad-1)) == 0, "Se elimina correctamente un elemento en la posicion final.");
    
    pa2m_afirmar((lista_elemento_en_posicion(lista, lista->cantidad-1)) == &e_3, "El anteultimo elemento  ahora es el ultimo.");

    pa2m_afirmar((lista_borrar_de_posicion(lista, 32)) == 0, "Se elimina correctamente un elemento en la posicion mayor al tamaño de la lista.");
    pa2m_afirmar((lista_elemento_en_posicion(lista, lista->cantidad-1)) == &e_2, "Cuando quiero borrar una posicion inexistente borro el ultimo.");

    lista_destruir(lista);
}

void dadounalistaconXelementos_lacantidaddeelementoseslaesperada(){

	lista_t* lista = lista_crear();
    char r='a', s='b', t='c', u='d', w='w';
    lista_insertar(lista, &r);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);

    pa2m_afirmar((lista_elementos(lista)) == 3, "la cantidad de elementos insertados es igual a la cantidad de elementos en la lista .");

    lista_borrar(lista);

    pa2m_afirmar((lista_elementos(lista)) == 2, "La cantidad de elemntos disminuyo en uno.");
    
    lista_insertar(lista, &u);
    lista_insertar(lista, &w);

    pa2m_afirmar((lista_elementos(lista)) == 4, "Ahora la lista tiene 4 elementos.");

    lista_destruir(lista);
}

void dadounalista_cuandodesencolo_borraelprimerelemnto(){

	lista_t* lista = lista_crear();
    char r='a', s='b', t='c', u='d', w='w';
    lista_insertar(lista, &r);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &u);
    lista_insertar(lista, &w);
    nodo_t* e_2 = lista->nodo_inicio->siguiente;
    int resultado;

    pa2m_afirmar(e_2 != lista->nodo_inicio , "El segundo elemento no es el primero");
    pa2m_afirmar((resultado = lista_desencolar(lista)) == 0, "Desaencola correctamente ");
    //tengo que probar los casos de lista null y demas
    pa2m_afirmar(e_2 == lista->nodo_inicio , "El segundo elemento ahora es el primero");

    lista_destruir(lista);
}

void dadounalista_cuandobuscounaposicion_devuelveelelementobuscado(){

	lista_t* lista = lista_crear();
    char r='a', s='b', t='c', u='d', w='w';
    lista_insertar(lista, &r);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &u);
    lista_insertar(lista, &w);

    pa2m_afirmar((lista_elemento_en_posicion(lista, 0)) == &r, "Devuelve el primer elemento");
    //es la cantidad -1 porque las posiciones empiezan desde el 0 pero el contador de la lista no
    pa2m_afirmar((lista_elemento_en_posicion(lista, lista->cantidad-1)) == &w, "Devuleve el ultimo elemento");
    pa2m_afirmar((lista_elemento_en_posicion(lista, 100)) == NULL, "El elemento solicitado no se puede encontrar, posicion requerida inexistente");


    lista_destruir(lista);
}

void lista_elemento_en_posicion_con_lista_NULL_elementos_me_devuelve_el_NULL(){
	lista_t* lista = NULL;

	pa2m_afirmar((lista_elemento_en_posicion(lista, 0)) == NULL, "Buscar elementos en lista NULL, devuelve NULL");
}

void lista_ultimo_con_3_elementos_me_devuelve_el_elemento_3(){
	lista_t* lista = lista_crear();
    char r='a', s='b', t='c', u='d', w='w';
    lista_insertar(lista, &r);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &u);
    lista_insertar(lista, &w);

    pa2m_afirmar((lista_ultimo(lista)) == &w, "Devuelve el ultimo elemento");
    lista_borrar(lista);
    pa2m_afirmar((lista_ultimo(lista)) == &u, "Devuelve el anteultimo que ahora es el ultimo elemento");

    lista_destruir(lista);

}

void lista_ultimo_con_lista_NULL_elementos_me_devuelve_el_NULL(){
	lista_t* lista = NULL;

    pa2m_afirmar((lista_ultimo(lista)) == NULL, "La lista esta NULL, devuelve NULL");
}

void probar_operaciones_cola_null(){
    lista_t* cola =NULL;
    char a='a';

    pa2m_afirmar((lista_encolar(cola, &a)) == -1, "No es posible encolar con una cola NULL");
    pa2m_afirmar((lista_desencolar(cola)) == -1, "No es posible desencolar con una cola NULL");

    lista_destruir(cola);
}

void probar_operaciones_cola(){
  
    lista_t* cola = lista_crear();
    char* letras={"HOLA"};
    int primero = 0;

    for(int i=0; letras[i]!= 0; i++){
        pa2m_afirmar((lista_encolar(cola, &letras[i])) == 0, "Encolo elementos correctamente");
        pa2m_afirmar((lista_tope(cola)) == &letras[i], "EL elemento se inserto en el final de la cola");
    	printf("\n");
    }
    printf("\n");
    pa2m_afirmar((lista_primero(cola)) == &letras[primero], "El primer elemento encolado esta en el inicio");
    printf("\n");
    while(!lista_vacia(cola)){
    	pa2m_afirmar((lista_desencolar(cola)) == 0, "Desencolo elementos correctamente");
        primero++;
        if(primero < 4)
        	pa2m_afirmar((lista_primero(cola)) == &letras[primero], "Se elimino el primer elemento");
    	printf("\n");
    }

    //muestro
    printf("\nEncolo y muestro: ");
    for(int i=0; letras[i]!= 0; i++){
        printf("%c", letras[i]);
        lista_encolar(cola, &letras[i]);
    }
    printf("\nDesencolo y muestro: ");
    while(!lista_vacia(cola)){
        printf("%c", *(char*)lista_primero(cola));
    	lista_desencolar(cola);
    }
    lista_destruir(cola);
}

void probar_operaciones_pila_null(){
    lista_t* pila =NULL;
    char a='a';

    pa2m_afirmar((lista_apilar(pila, &a)) == -1, "No es posible apilar con una pila NULL");
    pa2m_afirmar((lista_desapilar(pila)) == -1, "No es posible desapilar con una pila NULL");
    lista_destruir(pila);
}

void probar_operaciones_pila(){
    lista_t* pila = lista_crear();
    char* letras="ALOH";

    for(int i=0; letras[i]!= 0; i++){
        pa2m_afirmar((lista_apilar(pila, &letras[i])) == 0, "Apilo elementos correctamente");
        pa2m_afirmar((lista_tope(pila)) == &letras[i], "EL elemento se inserto en el final de la pila");
    	printf("\n");
    }
    printf("\n");
    int tope = (int)pila->cantidad-1;
     
    pa2m_afirmar((lista_tope(pila)) == &letras[tope], "EL tope se encuentra en el ultimo elemento");
    printf("\n");
    while(!lista_vacia(pila)){
   		pa2m_afirmar((lista_desapilar(pila)) == 0, "Desapilo elementos correctamente");
   		tope--;
   		if(tope >=0)
        	pa2m_afirmar((lista_tope(pila)) == &letras[tope], "El elemento anterior se encuentra en el tope");
    	printf("\n");
    }

    //apilo y desapilo de nuevo y muestro
    printf("\nApilo y muestro: ");
    for(int i=0; letras[i]!= 0; i++){
        printf("%c", letras[i]);
        lista_apilar(pila, &letras[i]);
    }
    printf("\nDesapilo y muestro: ");
    while(!lista_vacia(pila)){
        printf("%c", *(char*)lista_tope(pila));
   		lista_desapilar(pila);
    }

    lista_destruir(pila);
}

bool mostrar(void* elemento, void* contador){
    if(elemento && contador){
    	(*(int*)contador)++;
        printf("%c ",*(char*)elemento);
    }
    return true;
}

void probar_iterador_interno(){
	lista_t* lista = lista_crear();
    char a='a', b='b', c='c', d='d', e='e';
  
    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    lista_insertar(lista, &d);
    lista_insertar(lista, &e);
    
	int contador=0;
    size_t elementos_recorridos = 0;
    printf("Imprimo la lista: \n");
    elementos_recorridos = lista_con_cada_elemento(lista, mostrar, (void*)&contador);
    printf("\n");

    pa2m_afirmar(contador == elementos_recorridos, "El iterador interno funciona correctamente");
    lista_destruir(lista);
}

void probar_iterador_interno_con_lista_NULL(){
	lista_t* lista = NULL;

	int contador=0;
    size_t elementos_recorridos = 0;
    elementos_recorridos = lista_con_cada_elemento(lista, mostrar, (void*)&contador);
    pa2m_afirmar(elementos_recorridos == 0, "El iterador interno con lista NULL no itera ");
    lista_destruir(lista);
}

void probar_iterador_externo(){
	
	lista_t* lista = lista_crear();
	lista_iterador_t* it = NULL;
    char a='a', b='b', c='c', d='d', e='e';
  	
  	int contador = 0;
  	int cantidad_elementos = 5;

    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    lista_insertar(lista, &d);
    lista_insertar(lista, &e);

    printf("Imprimo la lista: \n");
	for(it = lista_iterador_crear(lista);lista_iterador_tiene_siguiente(it);lista_iterador_avanzar(it)){
        printf("%c ", *(char*)lista_iterador_elemento_actual(it));
        contador++;
	}
	printf("\n");
    pa2m_afirmar(contador == cantidad_elementos, "El iterador externo funciona correctamente");

    lista_iterador_destruir(it);
    lista_destruir(lista);
}

void probar_iterador_externo_con_lista_NULL(){
	lista_t* lista_1 = NULL;
	lista_t* lista_2 = lista_crear();
	lista_iterador_t* it_1 = lista_iterador_crear(lista_1);
	lista_iterador_t* it_2 = lista_iterador_crear(lista_2);

    pa2m_afirmar(it_1 == NULL, "Un iterador de una lista nula es nulo");
	
    pa2m_afirmar(it_2 != NULL, "Puedo crear un iterador con una lista vacía");

    lista_iterador_destruir(it_1);
    lista_iterador_destruir(it_2);
    lista_destruir(lista_2);
}

void pruebas_de_cola(){
	
	//pa2m_nuevo_grupo("Pruebas de desencolar");
	//dadounalista_cuandodesencolo_borraelprimerelemnto();
	pa2m_nuevo_grupo("Cola NULL");
	probar_operaciones_cola_null();
	pa2m_nuevo_grupo("Cola no con elementos");
	probar_operaciones_cola();
}

void pruebas_de_pila(){
	pa2m_nuevo_grupo("Pila NULL");
	probar_operaciones_pila_null();
	pa2m_nuevo_grupo("Pila no con elementos");
	probar_operaciones_pila();
}

void pruebas_de_lista(){
	pa2m_nuevo_grupo("Pruebas de crear");
	cuandocreounalista_secreaunalistavacia();

	pa2m_nuevo_grupo("Pruebas de insertar al final");
	dadounalistaNULL_cuadnollamoalistainsertar_devuelveMENOSUNO();
 	dadounalista_cuandoinserto3elementos_lalistatiene3elementos();
  
	pa2m_nuevo_grupo("Pruebas de insertar en posicion");
	lista_insertar_posicion_con_lista_NULL_devuelve_menos_uno();
	dadounalista_cuadnollamoalistainsertarenpos_insertacorrectamente();

	pa2m_nuevo_grupo("Pruebas de borrar");
	lista_borrar_con_lista_NULL_devuelve_menos_uno();
	dadounalista_cuadnollamoalistaborrar_borraelultimoelemento();

	pa2m_nuevo_grupo("Pruebas de borrar en posicion");
	lista_borrar_posicion_con_lista_NULL_devuelve_menos_uno();
	dadounalistade4_cuadopidoqueborreel3_borraelelementopedido();
	dadounalista_cuadnollamoalistaborrarporposicion_borraelelementopedido();

	pa2m_nuevo_grupo("Pruebas de elementos");
	dadounalista_cuandobuscounaposicion_devuelveelelementobuscado();
	dadounalistaconXelementos_lacantidaddeelementoseslaesperada();
	lista_ultimo_con_3_elementos_me_devuelve_el_elemento_3();
	lista_elemento_en_posicion_con_lista_NULL_elementos_me_devuelve_el_NULL();
	lista_ultimo_con_lista_NULL_elementos_me_devuelve_el_NULL();
}

void pruebas_del_iterador_interno(){
	pa2m_nuevo_grupo("Lista con elementos");
	probar_iterador_interno();
	pa2m_nuevo_grupo("Lista NULL");
	probar_iterador_interno_con_lista_NULL();
}

void pruebas_del_iterador_externo(){
	pa2m_nuevo_grupo("Lista con elementos");
	probar_iterador_externo();
	pa2m_nuevo_grupo("Lista NULL");
	//intento de recreacion de 2 pruebas de CHANUTRON 
	probar_iterador_externo_con_lista_NULL();
}


int main() {

	pa2m_nuevo_grupo("PRUEBAS LISTA");
	pruebas_de_lista();
	
	pa2m_nuevo_grupo("PRUEBAS COLA");
	pruebas_de_cola();

	pa2m_nuevo_grupo("PRUEBAS PILA");
	pruebas_de_pila();

	pa2m_nuevo_grupo("PRUEBAS ITERADOR INTERNO");
	pruebas_del_iterador_interno();

	pa2m_nuevo_grupo("PRUEBAS ITERADOR EXTERNO");
	pruebas_del_iterador_externo();

  return pa2m_mostrar_reporte();
}
