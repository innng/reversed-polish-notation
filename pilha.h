#ifndef PILHA_H_
#define PILHA_H_

#include "lista.h"

/* Estrutura para a Pilha, contém uma lista, o tamanho da Pilha e um ponteiro para o próximo nodo */
typedef struct TPilha {
	TipoLista* lista;
	TipoDado tamanho;
	struct TPilha* prox;
}TipoPilha;

/* --------------------------------	Protótipos --------------------------------	*/

/*
CriaPilha não possui inputs;
Criada para deixar o código mais legível;
Retorna um ponteiro NULL.
*/
TipoPilha* CriaPilha();

/*
PilhaVazia recebe uma pilha como input;
Testa se a pilha está vazia;
Retorna 1 caso a pilha esteja vazia e 0 caso contrário.
*/
int PilhaVazia(TipoPilha* pilha);

/*
InserePilha recebe uma pilha, um valor e um operador;
Insere o valor e o operador na lista correspondente ao novo nodo da pilha;
Retorna a pilha.
*/
TipoPilha* InserePilha(TipoPilha* pilha, TipoDado info, char* operador);

/*
RemovePilha recebe uma pilha e retira o topo da pilha;
Retorna a lista de dados que estavam contidos no nodo retirado.
*/
TipoLista* RemovePilha(TipoPilha** pilha);

/*
PegaDado recebe uma pilha;
Executa o processamento de tirar um dado da pilha: retira a lista da pilha e retira o dado da lista;
Retorna o dado retirado.
*/
TipoDado PegaDado(TipoPilha** pilha);

/*
InvertePilha recebe uma pilha;
Inverte a ordem de seus nodos (o fundo passa a ser o topo);
Retorna a pilha invertida.
*/
TipoPilha* InvertePilha(TipoPilha** pilha);

/*
TamanhoPilha recebe uma pilha e retorna a altura do nodo do topo.
*/
int TamanhoPilha(TipoPilha* pilha);

/*
LiberaPilha recebe uma pilha e libera todos os ponteiros relacionados à pilha e à sua lista alocados com malloc.
*/
void LiberaPilha(TipoPilha* pilha);

#endif	//PILHA_H_