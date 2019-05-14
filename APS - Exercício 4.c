#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct {
	char nome[16];
	int telefone;
	char endereco[26];
	int codigo;
} cadastro;


int main(void) {
	
	setlocale(LC_ALL, "");
	
	FILE *informacoes_dos_clientes;
	
	char escolha = 's';
	int cont = 0;
	int codigo_busca;
	int i;
	
	printf("\t\t Cadastro de clientes");
	
	cadastro novo[50];
	
	
	while(escolha != 'n') {
		
		printf("\n\nDigite o nome do cliente: ");
		gets(novo[cont].nome);
		fflush(stdin);
		
		printf("\nDigite o telefone: ");
		scanf("%d", &novo[cont].telefone);
		fflush(stdin);
		
		printf("\nDigite o endereço: ");
		gets(novo[cont].endereco);
		fflush(stdin);
		
		printf("\n\nNovo cliente? S/N ");
		scanf("%c", &escolha);
		fflush(stdin);
		
		novo[cont].codigo = cont;
		
		system("CLS");
		
		cont++;
	}
	
	informacoes_dos_clientes = fopen("Dados dos clientes.txt", "a");
	fprintf(informacoes_dos_clientes, "\t\tInformações dos clientes\n\n");
	for(i = 0; i < cont; i ++) {
		fprintf(informacoes_dos_clientes, "Cliente %d: ", i);
		fprintf(informacoes_dos_clientes, "\t-Nome: %s", novo[i].nome);
		fprintf(informacoes_dos_clientes, "\n\t-Telefone: %d", novo[i].telefone);
		fprintf(informacoes_dos_clientes, "\n\t-Endereço: %s", novo[i].endereco);
		fprintf(informacoes_dos_clientes, "\n\n");
	}
	fclose(informacoes_dos_clientes);
	
	while(codigo_busca != 999){
		
		printf("Consulta de clientes por código\n\n\n");
		
		printf("Digite o código do cliente: ");
		
		printf("\nDigite 999 para sair do programa\n");
		scanf("%d", &codigo_busca);
		
		if(codigo_busca > cont && codigo_busca != 999) {
			printf("\n\nCódigo inválido\n\n");
		} else {
			for(i = 0; i < cont; i++) {
				if(novo[i].codigo == codigo_busca) {
					printf("\n\nCliente: %s", novo[i].nome);
					printf("\nEndereço: %s", novo[i].endereco);
					printf("\nTelefone: %d\n\n", novo[i].telefone);
				} 
			}
		}
		
		if (codigo_busca == 999) {
			printf("Obrigado por usar nosso programa!!\n\n");	
		}
		
		system("pause");
		system("CLS");
		
	}
	
	
	return 0;
	
	
	
}
