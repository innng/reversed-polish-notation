#ifndef FUNCOES_C_
#define FUNCOES_C_

#include "lista.h"
#include "pilha.h"
#include "funcoes.h"
#define ENTRADA 201

TipoPilha* LeEntrada(TipoDado *total) {
	TipoPilha *pilha = CriaPilha();
	char entrada_array[ENTRADA] = {'\0'}, *token = NULL, *string_inicial = "", char_lido = '\0';

	/* Pega a linha da expressão e o valor do resultado */
	fgets(entrada_array, ENTRADA, stdin);
	scanf("%d", total);

	/* Separa e trata o array de dados da entrada */
	token = strtok(entrada_array, " ");
	while(token != NULL) {
		char_lido = *token;
      	if(char_lido == '?') {
      		pilha = InserePilha(pilha, -2, string_inicial);
      	}
      	else {
      		long int dado = atol(token);
      		if(dado > 0)
	      		pilha = InserePilha(pilha, (int)dado, string_inicial);
      	}
	token = strtok(NULL, " ");
	}
	free(token);
	return pilha;
} /* LeEntrada */

TipoDado SomaAB(TipoDado operando1, TipoDado operando2, TipoDado total) {
	TipoDado soma = 0;

	soma = operando1 + operando2;
	if(soma <= total) {
		return soma;
	}
	else return -1;
} /* SomaAb */

TipoDado MultiplicaAB(TipoDado operando1, TipoDado operando2, TipoDado total) {
	TipoDado multi = 1;

	multi = operando1 * operando2;
	if(multi <= total)
		return multi;
	else return -1;
} /* MultiplicaAB */

char* ConcatenaStrings(char *string1, char *string2) {
	char *resultado_null = "";
	if(string1 == NULL && string2 != NULL)
		return string2;
	if(string1 != NULL && string2 == NULL)
		return string1;
	if(string1 == NULL && string2 == NULL)
		return resultado_null;

	char *operador = NULL;
	operador = malloc(strlen(string1) + strlen(string2) + 2);

	strcpy(operador, string1);
	strcat(operador, string2);
	return operador;
} /* ConcatenaStrings */

TipoPilha *ProcessaEntrada(TipoPilha** entrada, TipoPilha** resultado, TipoDado total) {
	TipoDado operando = 0;
	char *string_inicial = "";

	while(!PilhaVazia(*entrada)) {
		operando = PegaDado(entrada);
		if(operando != -2)
			*resultado = InserePilha(*resultado, operando, string_inicial);
		else
			CalculaExpressao(resultado, total);
	}
	FiltraResposta(resultado, total);
	return *resultado;		
} /* FiltraResposta */

TipoPilha *CalculaExpressao(TipoPilha** resultado, TipoDado total) {
	TipoLista *lista_aux = NULL, *lista_operandos1 = NULL, *lista_operandos2 = NULL;
	TipoDado operando1 = 0, operando2 = 0, soma = 0, multi = 1;
	char *operador1 = "", *operador2 = "", *operador_aux = "";

	/* Separa listas de operandos */
	lista_operandos2 = RemovePilha(resultado);
	lista_operandos1 = RemovePilha(resultado);

	/* Testa se há -1 no primeiro nodo */
	if(ConsultaLista(lista_operandos1) == -1) 
		operando1 = RemoveLista(&lista_operandos1);
	if(ConsultaLista(lista_operandos2) == -1) 
		operando1 = RemoveLista(&lista_operandos2);

	/* Cria novo nodo na pilha */
	*resultado = InserePilha(*resultado, -1, "");

	/* Faz as operações e reinsere na pilha */
	while(!ListaVazia(lista_operandos1)) {
		operador_aux = ConcatenaStrings(lista_operandos1->operador, "");
		if(strlen(lista_operandos1->operador) > 0)
			free(lista_operandos1->operador);
		operando1 = RemoveLista(&lista_operandos1);
		
		lista_aux = lista_operandos2;
		while(lista_aux != NULL) {
			/* Prepara as strings auxiliares */
			operador1 = ConcatenaStrings(operador_aux, lista_aux->operador);
			operador2 = ConcatenaStrings(operador_aux, lista_aux->operador);

			/* Faz os cálculos */
			operando2 = ConsultaLista(lista_aux);
			soma = SomaAB(operando1, operando2, total);
			multi = MultiplicaAB(operando1, operando2, total);

			/* Testa e insere na lista */
			if(soma >= 0) {
				strcat(operador1, "+");
				(*resultado)->lista = InsereLista((*resultado)->lista, soma, operador1);
			}
			if(multi >= 0) {
				strcat(operador2, "*");
				(*resultado)->lista = InsereLista((*resultado)->lista, multi, operador2);
			}
			lista_aux = lista_aux->prox;
			free(operador1);
			free(operador2);
		}
		free(operador_aux);
	}
	
	LiberaLista(lista_operandos1);
	LiberaLista(lista_operandos2);
	return *resultado;
} /* CalculaExpressao */

TipoPilha* FiltraResposta(TipoPilha** resultado, TipoDado total) {
	TipoLista *lista_aux = NULL;
	TipoDado dado = 0;
	char *operador = "";

	if(PilhaVazia(*resultado))
		return NULL;
	else {
		lista_aux = RemovePilha(resultado);
		*resultado = InserePilha(*resultado, -1, operador);

		while(lista_aux != NULL) {
			operador = ConcatenaStrings(lista_aux->operador, "");
			if(strlen(lista_aux->operador) > 0)
				free(lista_aux->operador);
			dado = RemoveLista(&lista_aux);
			if(dado == total)
				(*resultado)->lista = InsereLista((*resultado)->lista, dado, operador);
			free(operador);
		}
		dado = RemoveLista(&(*resultado)->lista);
		LiberaLista(lista_aux);
		return *resultado;		
	}
} /* FiltraResposta */

#endif	//FUNCOES_C_