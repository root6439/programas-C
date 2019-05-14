#include <stdio.h>

int main(void) {
	
	FILE *imprimir_matriz;
	
	int matriz[10][10];
	int i, j;
	int cont = 0;
	
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			matriz[i][j] = cont;
			cont++;
		}
	}
	
	imprimir_matriz = fopen("Elementos abaixo da diagonal principal.txt", "w");
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			if(i >= j) {
				fprintf(imprimir_matriz, "%d ", matriz[i][j]);	
			}
		}
		fprintf(imprimir_matriz, "\n");	
	}
	
	return 0;
}
