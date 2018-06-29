#ifndef MAIN_C_
#define MAIN_C_

#include "lista.h"
#include "pilha.h"
#include "funcoes.h"

int main() {
	/* Declara variáveis para o monitoramento do tempo */
	clock_t start, end;
	double execution_time = 0;

	/* Inicia a contagem */
	start = clock();

	TipoPilha *entrada = CriaPilha(), *resultado = CriaPilha();
	TipoLista *historico = CriaLista();
	TipoDado total = 0;

	entrada = LeEntrada(&total);
	entrada = InvertePilha(&entrada);
	resultado = ProcessaEntrada(&entrada, &resultado, total);
	historico = RemovePilha(&resultado);
	ImprimeStringsLista(historico);
	LiberaLista(historico);
	LiberaPilha(entrada);
	LiberaPilha(resultado);

	/* Para a contagem */
	end = clock();

	/* Calcula tempo de execução registrado em segundos */
	execution_time = (double)(end -start) / CLOCKS_PER_SEC;
	printf("Tempo consumido: %f\n", execution_time);
	
	return 0;
} /* main */

#endif	//MAIN_C_