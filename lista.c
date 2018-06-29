#ifndef LISTA_C_
#define LISTA_C_

#include "lista.h"

TipoLista* CriaLista() {
	return NULL;
} /* CriaLista */

int ListaVazia(TipoLista* lista) {
	if(lista == NULL)
		return 1;
	else
		return 0;
} /* ListaVazia */

TipoLista* InsereLista(TipoLista* lista, TipoDado dado, char* operador) {
	TipoLista *novo = CriaLista(), *lista_aux = NULL;

	/* Aloca e preenche novo nodo */
	novo = malloc(sizeof(TipoLista));
	novo->info = dado;
	if(strlen(operador) > 0) {
		novo->operador = malloc((strlen(operador) + 1)*sizeof(char));
		strcpy(novo->operador, operador);
	}
	else novo->operador = operador;
	novo->prox = NULL;

	/* Insere novo nodo */
	if(ListaVazia(lista))
		lista = novo;
	else {
		lista_aux = lista;
		while(lista_aux->prox != NULL) 
			lista_aux = lista_aux->prox;
		lista_aux->prox = novo;
	}
	return lista;
} /* InsereLista */

TipoDado RemoveLista(TipoLista** lista) {
	TipoLista *lista_aux = NULL;
	TipoDado dado = 0;

	if(ListaVazia(*lista))
		return -1;
	else {
		dado = (*lista)->info;
		lista_aux = *lista;
		*lista = (*lista)->prox;
		free(lista_aux);		
		return dado;
	}
} /* RemoveLista */

TipoDado ConsultaLista(TipoLista* lista) {
	return lista->info;
} /* ConsultaLista */

int TamanhoLista(TipoLista* lista) {
	TipoLista *lista_aux = NULL;
	TipoDado contador = 0;

	lista_aux = lista;
	while(lista_aux != NULL) {
		contador++;
		lista_aux = lista_aux->prox;
	}
	return contador;
} /* TamanhoLista */

void ImprimeLista(TipoLista* lista) {
	TipoLista *lista_aux = NULL;

	lista_aux = lista;
	while(lista_aux != NULL) {
		printf("%d\n", lista_aux->info);
		lista_aux = lista_aux->prox;
	}
} /* ImprimeLista */

void ImprimeStringsLista(TipoLista* lista) {
	TipoLista *lista_aux = NULL;

	lista_aux = lista;
	while(lista_aux != NULL) {
		printf("%s\n", lista_aux->operador);
		lista_aux = lista_aux->prox;
	}
} /* ImprimeLista */

void LiberaLista(TipoLista* lista) {
	TipoLista *lista_aux = NULL;

	while(lista != NULL) {
		lista_aux = lista;
		lista = lista->prox;
		if(strlen(lista_aux->operador) > 0)
			free(lista_aux->operador);
		free(lista_aux);
	}
	free(lista);
} /* LiberaLista */

#endif	//LISTA_C_