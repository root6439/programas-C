#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define salario_minimo 954

typedef struct {
	char nome[16];
	char cargo[16];
	float salario;
} informacoes;

int main(void) {
	
	setlocale(LC_ALL, "");

	FILE *informacoes_dos_salarios;

	int num_funcionarios, i, aux, j, media_salario = 0;
	
	char nome_aux[16];
	float salario_aux;
	char cargo_aux[16];
		
	printf("Quantos funcion�rios deseja cadastrar?\n");
	scanf("%d", &num_funcionarios);
	fflush(stdin);
	
	system("CLS");
	
	informacoes cadastrar[num_funcionarios];
	
	//L� as informa��es dos funcionarios
	for(i = 0; i < num_funcionarios; i++) {
		
		printf("Digite o nome do funcion�rio: ");
		gets(cadastrar[i].nome);
		
		printf("Digite o cargo do funcion�rio: ");
		gets(cadastrar[i].cargo);
		
		printf("Digite o sal�rio: ");
		scanf("%f", &cadastrar[i].salario);
		fflush(stdin);
		
		media_salario = media_salario + cadastrar[i].salario;
	}
	
	//Calcula a m�dia salarial
	media_salario = media_salario/num_funcionarios;
	
	//Ordena lista crescentemente com base no sal�rio
	for(i = 0; i < num_funcionarios-1; i++) {
		for(j = i + 1; j < num_funcionarios; j++) {
			if(cadastrar[i].salario > cadastrar[j].salario) {
				
				strcpy(nome_aux, cadastrar[i].nome);
				strcpy(cargo_aux, cadastrar[i].cargo);
				salario_aux = cadastrar[i].salario;
				
				strcpy(cadastrar[i].nome, cadastrar[j].nome);
				strcpy(cadastrar[i].cargo, cadastrar[j].cargo);
				cadastrar[i].salario = cadastrar[j].salario;
				
				strcpy(cadastrar[j].nome, nome_aux);
				strcpy(cadastrar[j].cargo, cargo_aux);
				cadastrar[j].salario = salario_aux;
				
			}
		}
		
	}
	
	//Imprime aqueles que possuem salario superior a 10 SM
	informacoes_dos_salarios = fopen("Dados dos funcion�rios.txt", "a");
		fprintf(informacoes_dos_salarios, "\t\t\t Funcion�rios com sal�rios superiores a 10 SM\n");
	fclose(informacoes_dos_salarios);
	
	for(i = 0; i < num_funcionarios; i++) {
		if(cadastrar[i].salario > 10*salario_minimo) {
			informacoes_dos_salarios = fopen("Dados dos funcion�rios.txt", "a");
				fprintf(informacoes_dos_salarios, "\nFuncion�rio: %s", cadastrar[i].nome);
				fprintf(informacoes_dos_salarios, "\nCargo: %s", cadastrar[i].cargo);
				fprintf(informacoes_dos_salarios, "\nSal�rio: %.2f", cadastrar[i].salario);
				fprintf(informacoes_dos_salarios,"\n");
			fclose(informacoes_dos_salarios);
		}
	}
	
	
	//Imprime funcionarios que posuem 5% para mais ou para menos da media salarial
	informacoes_dos_salarios = fopen("Dados dos funcion�rios.txt", "a");
		fprintf(informacoes_dos_salarios, "\n\n     Funcion�rios com sal�rio de 5%% para mais ou para menos da m�dia de todos os sal�rios:");
		fprintf(informacoes_dos_salarios, "\n");
	fclose(informacoes_dos_salarios);
	
	for(i = 0; i < num_funcionarios; i++) {
		if(cadastrar[i].salario <= media_salario - (0.05*media_salario) && cadastrar[i].salario >= media_salario + (0.05*media_salario)) {
			informacoes_dos_salarios = fopen("Dados dos funcion�rios.txt", "a");
				fprintf(informacoes_dos_salarios, "\nFuncion�rio: %s", cadastrar[i].nome);
				fprintf(informacoes_dos_salarios, "\nCargo: %s", cadastrar[i].cargo);
				fprintf(informacoes_dos_salarios, "\nSal�rio: %.2f", cadastrar[i].salario);
			fclose(informacoes_dos_salarios);
		}	
	}
	
	
	//Imprime funcionarios mais pobres
	informacoes_dos_salarios = fopen("Dados dos funcion�rios.txt", "a");
		fprintf(informacoes_dos_salarios, "\n\n\t\t\tFuncion�rios com menores sal�rios\n");
	fclose(informacoes_dos_salarios);
	
	
	informacoes_dos_salarios = fopen("Dados dos funcion�rios.txt", "a");
		if(num_funcionarios < 10) {
				for(i = 0; i < num_funcionarios; i++) {
				fprintf(informacoes_dos_salarios, "\nFuncion�rio: %s", cadastrar[i].nome);
				fprintf(informacoes_dos_salarios, "\nCargo: %s", cadastrar[i].cargo);
				fprintf(informacoes_dos_salarios, "\nSal�rio: %.2f", cadastrar[i].salario);
				fprintf(informacoes_dos_salarios,"\n");
			}	
		} else {
				for(i = 0; i < 10; i++) {
				fprintf(informacoes_dos_salarios, "\nFuncion�rio: %s", cadastrar[i].nome);
				fprintf(informacoes_dos_salarios, "\nCargo: %s", cadastrar[i].cargo);
				fprintf(informacoes_dos_salarios, "\nSal�rio: %.2f", cadastrar[i].salario);
				fprintf(informacoes_dos_salarios,"\n");
			}
		}
	fclose(informacoes_dos_salarios);
	
	
	
	return 0;
}
