#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _GNU_SOURCE

struct aplicacao{
	float ValorConstanteAplicacao;
	float taxa;
	int NumeroDeMeses;
};

int main(void) {
	
	setlocale(LC_ALL, "");
	
	char escolha;
	FILE *arq_entrada;
	FILE *arq_saida;
	
	
	struct aplicacao PrimeiraAplicacao;
	
	arq_entrada = fopen("Dados para poupança programada.txt", "r");
		if(arq_entrada == NULL) {
			printf("Arquivo não pode ser aberto");
			system("pause");
			return 0;
		} 
	
		fscanf(arq_entrada,"\n%f\n%f\n%d", &PrimeiraAplicacao.ValorConstanteAplicacao, &PrimeiraAplicacao.taxa, &PrimeiraAplicacao.NumeroDeMeses);
	fclose(arq_entrada);
	
	PrimeiraAplicacao.taxa = PrimeiraAplicacao.taxa/100;
	float aux1 = pow((1+PrimeiraAplicacao.taxa), PrimeiraAplicacao.NumeroDeMeses);
	float aux2 = (aux1 - 1)/PrimeiraAplicacao.taxa;
	float ValorAcumulado = PrimeiraAplicacao.ValorConstanteAplicacao*aux2;
	
	arq_saida = fopen("Informações da poupança calculada.txt", "a");
		fprintf(arq_saida, "\n\n\t\t\tInformações da poupança programada");
		fprintf(arq_saida, "\n\nCom uma taxa de %.0f por cento, R$%.2f aplicados mensalmente durante %d meses, o valor acumulado será de %.2f", PrimeiraAplicacao.taxa*100, PrimeiraAplicacao.ValorConstanteAplicacao, PrimeiraAplicacao.NumeroDeMeses, ValorAcumulado);
	fclose(arq_saida);
	
	
		
	return 0;

	
}
