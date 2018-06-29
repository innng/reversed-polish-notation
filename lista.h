#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Convenção: dados no trabalho são inteiros */
typedef int TipoDado;

/* Estrutura para a Lista, contém uma informação, um operador e um ponteiro para o próximo nodo */
typedef struct TLista
{
	TipoDado info;
	char* operador;
	struct TLista* prox;
}TipoLista;

/* --------------------------------	Protótipos --------------------------------	*/

/*
CriaLista não possui inputs;
Criada para deixar o código mais legível;
Retorna um ponteiro NULL.
*/
TipoLista* CriaLista();

/*
ListaVazia recebe uma lista como input;
Testa se a lista está vazia;
Retorna 1 caso a lista esteja vazia e 0 caso contrário.
*/
int ListaVazia(TipoLista* lista);

/*
InsereLista recebe uma lista, um valor e um operador;
Insere o valor e o operador num nodo da lista;
Retorna a lista.
*/
TipoLista* InsereLista(TipoLista* lista, TipoDado dado, char* operador);

/*
RemoveLista recebe uma lista e retira o seu primeiro elemento;
Retorna o dado que estava contido no nodo retirado.
*/
TipoDado RemoveLista(TipoLista** lista);

/*
ConsultaLista recebe uma lista e retorna o dado de seu primeiro nodo.
*/
TipoDado ConsultaLista(TipoLista* lista);

/*
TamanhoLista recebe um lista e devolve seu tamanho (número de nodos).
*/
int TamanhoLista(TipoLista* lista);

/*
ImprimeLista recebe uma lista e imprime seus dados do primeiro ao último nodo.
*/
void ImprimeLista(TipoLista* lista);

/*
ImprimeLista recebe uma lista e imprime suas strings do primeiro ao último nodo.
*/
void ImprimeStringsLista(TipoLista* lista);

/*
LiberaLista recebe uma lista e libera todos os ponteiros relacionados à lista alocados com malloc no curso do programa.
*/
void LiberaLista(TipoLista* lista);

#endif	//LISTA_H_