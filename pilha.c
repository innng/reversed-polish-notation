#ifndef PILHA_C_
#define PILHA_C_

#include "lista.h"
#include "pilha.h"

TipoPilha* CriaPilha() {
	return NULL;
} /* CriaPilha */

int PilhaVazia(TipoPilha* pilha) {
	if(pilha == NULL)
		return 1;
	else return 0;
} /* PilhaVazia */

TipoPilha* InserePilha(TipoPilha* pilha, TipoDado info, char* operador) {
	TipoPilha *novo = CriaPilha();

	/* Aloca e inicializa o novo nodo */
	novo = malloc(sizeof(TipoPilha));
	novo->lista = NULL;
	novo->lista = InsereLista(novo->lista, info, operador);

	/* Insere o nodo */
	if(PilhaVazia(pilha)) {
		novo->tamanho = 1;
		novo->prox = NULL;
	}
	else {
		novo->tamanho = pilha->tamanho + 1;
		novo->prox = pilha;
	}
	return novo;
} /* InserePilha */

TipoLista* RemovePilha(TipoPilha** pilha) {
	TipoPilha *pilha_aux = NULL;
	TipoLista *lista_aux = NULL;

	if(PilhaVazia(*pilha))
		return NULL;
	else {
		lista_aux = (*pilha)->lista;
		pilha_aux = *pilha;
		*pilha = (*pilha)->prox;
		free(pilha_aux);
		return lista_aux;
	}
} /* RemovePilha */

TipoDado PegaDado(TipoPilha** pilha) {
	TipoLista *lista_aux = NULL;
	TipoDado dado = 0;

	lista_aux = RemovePilha(pilha);
	dado = RemoveLista(&lista_aux);
	LiberaLista(lista_aux);
	return dado; 
} /* PegaDado */

TipoPilha* InvertePilha(TipoPilha** pilha) {
	TipoPilha *pilha_aux = NULL;
	TipoDado dado = 0;

	if(PilhaVazia(*pilha))
		return NULL;
	else
		while(!PilhaVazia(*pilha)) {
			dado = PegaDado(pilha);
			pilha_aux = InserePilha(pilha_aux, dado, "");
		}
	return pilha_aux;
} /* InvertePilha */

int TamanhoPilha(TipoPilha* pilha) {
	return pilha->tamanho;
} /* TamanhoPilha */

void LiberaPilha(TipoPilha* pilha) {
	TipoPilha *pilha_aux = NULL;

	while(pilha != NULL){
		pilha_aux = pilha;
		pilha = pilha->prox;
		LiberaLista(pilha_aux->lista);
		free(pilha_aux);
	}
	free(pilha);
} /* LiberaPilha */

#endif	//PILHA_C_