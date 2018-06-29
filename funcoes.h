#ifndef FUNCOES_H_
#define FUNCOES_H_

#include "lista.h"
#include "pilha.h"

/* --------------------------------	Protótipos --------------------------------	*/

/*
LeEntrada recebe um ponteiro de dado;
Recebe e trata a entrada (expressão e resultado) e guarda nas devidas estruturas;
Retorna a pilha com a entrada.
*/
TipoPilha* LeEntrada(TipoDado *total); 

/*
SomaAB recebe dois operandos e um total;
Faz a soma e compara com total;
Retorna o valor da soma se for menor que o total e -1 caso contrário.
*/
TipoDado SomaAB(TipoDado operando1, TipoDado operando2, TipoDado total);

/*
MultiplicaAB recebe dois operandos e um total;
Faz a multiplicação e compara com total;
Retorna o valor da multiplicação se for menor que o total e -1 caso contrário.
*/
TipoDado MultiplicaAB(TipoDado operando1, TipoDado operando2, TipoDado total);

/*
ConcatenaStrings recebe duas strings, concatena-as e retorna o resultado da operação.
*/
char* ConcatenaStrings(char* string1, char *string2);

/*
ProcessaEntrada recebe duas pilhas e um dado;
Primeira etapa da solução do problema proposto: trata a entrada e designa chamada das funções sequentes;
Retorna a pilha com a resolução final.
*/
TipoPilha *ProcessaEntrada(TipoPilha** entrada, TipoPilha** resultado, TipoDado total);

/*
CalculaExpressao recebe uma pilha e o total;
Segunda etapa do problema: faz as operações de multiplicação e adição para cada caso que está na pilha;
Retorna a pilha com as operações feitas.
*/
TipoPilha *CalculaExpressao(TipoPilha** resultado, TipoDado total);

/*
FiltraResposta recebe uma pilha e o total;
Terceira e última etapa do problema: verifica os itens da pilha de acordo com o total;
Retorna a pilha.
*/
TipoPilha *FiltraResposta(TipoPilha** resultado, TipoDado total);

#endif	//FUNCOES_H_