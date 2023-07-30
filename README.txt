

LISTA.C
-------
-------

+Lista_crear--------> Reserva memoria para almacenar una lista y la inicializa.

+lista_insertar--------> Recibe una lista junto con un elemento, si la funcion puede ser implementada correctamente devolvera "0", en caso de que no haya lista devuelve "-1" y sale de la funcion.  Suponiendo de que nos encontramos en un caso ideal, reserva memoria para almacenar un nodo y a ese nodo le otorga el el elemento. Esta funcion inserta un nuevo nodo al final de la lista, entonces lo que hace es unir ese nuevo nodo al final de la lista, ingresando null en la posicion siguiente al nodo nuevo e incrementando la cantidad de elemnto que hay en la lista. En caso de que la lista no tenga ningun elemento aun, es decir que esta vacia, se crea la lista empezando por este nodo. 

+lista_insertar_en_posicion--------> Recibe una lista junto con un elemento y una posicion donde se quiere insertar ese nuevo elemento, si la funcion puede ser implementada correctamente devolvera "0", en caso de que no haya lista devuelve "-1" y sale de la funcion. Suponiendo de que nos encontramos en un caso ideal, reserva memoria para almacenar un nodo y a ese nodo le otorga el el elemento. luego esta funcion se ramifica en 3 soluciones:

(1)---> La posicion en la que se quiere insertar dicho elemento es mayor a la cantidad de elemntos en la lista o la lista esta vacia. Estos dos caso se pueden pensar como uno ya que ambos llevan a la misma soliucion. En caso de que la posicion sea mayor a la lista, el elemento debe ser insertado en la posicion final y en el caso de que la lista este vacia debo insertar el elemnto en el principio. Entonces en ambos casos llamo a la funcion "lista_insertar" que se encarga especialmente de esos dos casos.

(2)-----> Si la posicion en la que se quiere insertar es la posicion inicial, debo crear un nodo auxiliar pra almacenar la direccion de memoria del primer elemento, entoces lo que hago es copiar la direccion de memoria que esta almacenada en "lista->nodo_inicio" y la aguardo en este auxiliar, luego la copio como la direccion del elemento siguiente al que quiero almacenar para asi no perder mi lista anterior ni tampoco el elemento que estaba en esa posicion. Luego modifico la direccion que esta en "lista->nodo_inicio" y le inserto la direccion de este nuevo nodo y de esa manera queda la lista original con el agregado de este nuevo elemento en la primer posicion.

(3)-----> El ultimo caso es en el que la posicion es mas grande que 0 y mas chica que el tamaño de la lista. En ese caso debo buscar el elemto que se encuentra una posicion menos que donde lo quiero insertar, una vez que llego a ese elemento  me dirijo al elemento que esta en la posicion que quiero y copio su direccion de memoria y la inserto como la direccion de memoria del elemento siguiente al que quiero agregar, luego a elemento que busque como el anterior le inserto la direccion del nuevo como su elemento siguiente y de esa manera queda toda la lista perfectamente implementada y con el elemento nuevo en la posicion deseada.

+lista_borrar------> Si la funcion puede ser implementada correctamente devolvera "0", en caso contrario devolvera "-1". Para implementar esta funcion existen 2 ramificaciones:

(1)-----> El primer caso es que la lista tenga un solo elemento, osea que el principio y el fin apuntan al mismo nodo, entonces lo que hago es liberar la direccion de memoria de ese unico nodo y despues vuelvo a reiniciar los valores de la lista de modo que queda vacia.

(2)----->El segundo caso es que la lista tenga mas de un elemento y entonces debo eliminar el ultimo, entonces implemento una funcion que vaya recorriendo la lista hasta encontrar el anteultimo elemento, una vez que obtengo el anteultimo elemento copio la direccion de memoria del ultimo y la guardo en un auxiliar, luego a la direcion del siguiente al anteultimo le ingreso que es NULL, de esa manera se convierte en el ultimo elemento de la lista y luego libero la memoria del que solia ser el ultimo elemento. 

+lista_borrar_de_posicion------> Recibe una lista junto con  la posicion del elemento que debe ser eliminado, si la funcion puede ser implementada correctamente devolvera "0", en caso de que no haya lista devuelve "-1" y sale de la funcion.  Suponiendo de que nos encontramos en un caso ideal, pueden ocurrir 3 casos:

(1)-----> En el caso en el que la posicion que se quiera eliminar sea la inicial debo guardar en una variable auxiliar la direccion de ese elemento, luego tomo la direccion del elemento que le sigue y se lo inserto a "lista->nodo_inicio", con esto lo que estoy haciendo es poner el segundo elemento de la lista como el primero. Luego de eso libero la memoria que guarde en el auxiliar.

(2)-----> En el caso en el que la posicion que quiere ser eliminada sea mayot o igual que la cantidad de elementos debo eliminar el ultimo elemento de la lista, por lo tanto llamo a la funcion "lista_borrar" que se encarga de eso 

(3)-----> En el caso en que la posicion que se quiera borrar sea una del "medio", debo encontrar el nodo anterior al que estoy buscando, una vez que lo encuentro copio la direccion del que quiero eliminar en un auxiliar, luego uno el anterior al que quiero eliminar con el que le seguia al que quiero eliminar. Una vez hecho eso libero la memoria que almacene en el auxiliar. 


+lista_elemento_en_posicion----> Esta funcion en caso de recibir una lista vacia o una posicion que es mas grande que la cantidad de elementos de la lista devuelve null. Sea un caso ideal hay 3 posibilidades, si la posicion que se busca es la inicial o la final, como tengo la direccion del ṕrimer y el ultimo elemento de la lista puedo acceder directamente a ellos, entonces si es uno de esos caso solo devuelvo el elemento. Si es el caso que la posicion que se busca no es la inicial ni final, recorro la lista y voy recorriendo elemento por elemento hasta encontrar el pedido, una vez que lo encuentro lo devuelvo.

+lista_ultimo-------> Devuleve el ultimo elemento de la lista, como tengo la direccion de dicho elemento solo me dirijo a esa posicion y la devuelvo. En el caso en el que la lista este vacia devuelvo NULL.

+lista_vacia----> Recibe una lista, si esa lista esta vacia o es nula devuelve NULL, en caso contrario devuelve false.

+lista_elementos-------> devuelve la cantidad de elementos, y como la lista lleva consigo esas informacion solo tengo que aplicar "lista->cantidad" y devolverlo.

+lista_apilar---> Como el concepto de apilar es agregar un elemento en el final de la pila y es el mismo concepto que interpreta la funcion "lista_insertar" solo tengo que llamar a esa funcion.

+lista_desapilar-----> Como el concepto de desapilar es borrar el ultimo elemento de la pila y es el mismo concepto que se utiliza en "lista_borrar" solo tengo que llamar a esa funcion.

+lista_tope----> Muestro el ultimo elemento de la pila, entonces solo tengo que dirigirme al final y devolver el elemento

+lista_encolar-------> Como el concepto de encolar es agregar un elemento al final de la cola  y es el mismo concepto que interpreta la funcion "lista_insertar" solo tengo que llamar a esa funcion.

+lista_desencolar------> Como el concepto de desencolar es sacar el primer elemento de la cola, si la lista solo tiene un elemento llamo a "lista_borrar" que va borrarlo y reiniciaar los valores de la lista, en caso contrario llamo a "lista_borrar_de_posicion" y le digo que me borre la posicion 0;

+lista_primero-----> Muestra el primer elemento de la cola, entonces solo tengo que dirigirme al inicio y devolver el elemento


+lista_destruir---> Si la lista esta vacia, es decir que existe una lista pero no contiene ningun elemento, solo libero la lista. En otros casos, recorro la lista nodo por nodo, pero empiezo este recorrido desde el segundo elemento, es decir el que estaria e la posicion "1", de esta manera le asigno esa direccion de memoria a un auxiliar y conecto al primer elemento(el elemento 0) con el siguiente al auxiliar y luego libero la memoria del auxiliar. Este proceso se va a seguir realizando mientras que el nodo que le sigue al inicial no sea NULL, es decir que esto iterara hasta que la lista quede con un solo elemento que va a ser el elemento inicial. Una vez terminada la iteracion libero el elemento inicial y luego la lista.


+lista_iterador_crear-----> Reserva memoria para almacenar un iterador y le asigna la lista al iterador y el nodo inicial

+lista_iterador_tiene_siguiente-------> Devuelve true mientras que la la lista tenga un elemento mas, es decir que va a devolver true mientras que el elemento siguiente al actual no sea NULL.	En caso contrario devuelve false.


+lista_iterador_avanzar-------> Si el nodo en donde se encuentra no es NULL va a pasar al siguiente mediante un auxiliar, al auxiliar le asigno la direccion del que le sigue para despues ubicar esa direccion como la actual si pude hacer eso devuelve true, en caso contrario devuelve false.


+lista_iterador_elemento_actual-------> Si existe un iterador va a devolver el elemento en el cual esta ubicado osea el elemento actual.

+lista_iterador_destruir-----> libera la memoria reservada por el iterador

+lista_con_cada_elemento------> Recorre toda la lista hasta llegar a su fin, lo hace creando un auxiliar que ayuda a moverse dentro de esa lista, no deja de iterar hasta que la funcion que se le pasa devuleva false  o hasta que la iteracion se haya realizado la misma cantidad de veces como elementos tiene la lista, una vez terminada la iteracion devuleve la cantidad de veces que itero.



PREGUNTAS TEORICAS
------------------


COLA: La cola es un tipo de tda el cual se rige por el principio F.I.F.O. que significas "first in first out" osea primero entrado primero salido, esto lo que quiere decir que el primer elemento que entre en la cola sera el primero en salir. Visto desde una perspectiva diferente seria que cada elemento que tenga que ser agregado sera agregado por el final de la cola("Encolar") y no sera eliminado hasta que no llegue al principio de la misma, es decir, que siempre se elimina el inicio de la fila("Desencolar") y en su lugar aparecera el elemento que estaba ubicado en segundo lugar y asi sucesivamente.
Existen 6 operaciones basicas que deben estar en este tda a la hora de implementarlo:

(1)Crear 				(2)Destruir 				(3)Encolar 				(4)Desencolar 				(5)Primero 					(6)Vacio

Encolar se refiere a insertar un elemento en la cola por el final
Desencolar se refiere a borra un elemento en el inicio de la cola
Primero se refiere a mostrar el primer elemento de la cola, el unico que nos sera visible

Con la implementacion que hice en este programa cada una de estas funciones deberian tener una complejidad de O(1).

PILA: La pila es un tipo de tda el cual se rige por el principio L.I.F.O. "last in first out" que quiere decir que el ultimo que ingresa a la pila sera el primero en salir; puesto en otras palabras, significa que cada vez que agregemos un elemento a la pila("Apilar") lo debemos hacer por el final de la misma y siempre que borremos un elemento de la pila("Desapilar") lo debemos hacer por el final tambien.
Existen 6 operaciones basicas que deben estar en este tda a la hora de implementarlo:

(1)Crear 				(2)Destruir 				(3)Apilar 				(4)Desapilar 				(5)Tope 					(6)Vacio

Apilar se refiere a insertar un elemento en el final de la pila
Desapilar se refiere a borra un elemento en el final de la pila
Tope se refiere a mostrar el ultimo elemento de la pila, el unico que nos sera visible

Con la implementacion que hice en este programa cada una de estas funciones deberian tener una complejidad de O(1).

LISTA: El tda lista es un tda muy similar a la cola y a la pila, pero tiene una pequeña/gran diferencia que termina siendo una ventaja. Esa diferencia es que en este tda no hay ninguna premisa a cumplir con respecto a el agregado de elementos o a la hora de elimir, con esto quiero decir que no hace falta eliminar o insertar estrictamente por el principio o por el final, en este tda puedo inserter e ingresar un elemento en la posicion que quiera mientras que esa posicion exista, sino debo dar a conocer los hechos que ocurriran si quiero insertar o eliminar un elemento en posiciones mayores o menores a la lista. Me refiero a que es una ventaja esta diferencia ya que, depende la implementacion,  en la cola o en la pila puedo llegar a tener que recorrer toda la lista para insertar o eliminar un elemenr. Esto en mi implementacion no ocurre ya que se realiza con nodos enlazados y tengo un puntero que me dirige tanto al inicio como al final y en los casos de insersion de la pila o cola se convierte en un O(1), pero pra insertar en una posicion en especifico puede ser O(n). Sin embargo, al apĺicar otra implementacion, cada una de estas operaciones puede ser de una complejidad algoritmica de O(n).

BONUS: En mi opinion la mejor implementacion para cualquiera de los 3 tipos de TDA's, es la de nodos doblemente enlazados con un puntero al inicio(que obviamente lo tiene que tener) y otro al final. De esta manera optimiza mas el programa a la hora de insertar, eliminar, buscar y demas.














