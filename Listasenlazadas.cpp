#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *siguiente;
} NODO;

NODO* crearNodo(int num);
int insertarFinal(NODO **cabeza, int num);
void imprimirNumeros(NODO *cabeza);
int insertarInicio(NODO **cabeza, int num);

int main(){
	
	NODO *cabeza =NULL;
	
	insertarInicio(&cabeza, 3);
	insertarFinal(&cabeza, 0);
	insertarFinal(&cabeza, 7);
	insertarFinal(&cabeza, 6);
	insertarFinal(&cabeza, 3);
	insertarFinal(&cabeza, 4);
	insertarFinal(&cabeza, 6);
	insertarFinal(&cabeza, 0);
	
	imprimirNumeros(cabeza);
	
	return 0;
}

NODO *crearNodo(int num){
	NODO *nuevo = NULL;
	
	nuevo = (NODO*)malloc(sizeof(NODO));
	
	if(nuevo != NULL){
		nuevo->num = num;
		nuevo->siguiente = NULL;
	}
	
	return nuevo;
}

int insertarInicio(NODO **cabeza, int num){
	
	NODO *nuevo = NULL;
	nuevo = crearNodo(num);
	
	if(nuevo != NULL){
		nuevo->siguiente = *cabeza;
		*cabeza = nuevo;
		return 1;
	}
	return 0;
}

int insertarFinal(NODO **cabeza, int num){
	NODO *nuevo = NULL, *aux= *cabeza;
	
	nuevo = crearNodo(num);
	
	if(nuevo != NULL){
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
		return 1;
	}
	
	return 0;
}

void imprimirNumeros(NODO *cabeza){
	NODO *nuevo = NULL, *aux = cabeza;
	
	while(aux != NULL){
		printf("%d", aux->num);
		aux = aux->	siguiente;
	}
}
