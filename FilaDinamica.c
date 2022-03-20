#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// aqui se encontra as funcoes e structs responsaveis pela execucao da fila no jogo, que foram usadas
// para armazenar os comandos da primeira fase e, os comandos de ida da terceira fase.

typedef struct sNoFila{
	int comandos[4]; //[0]-opcao [1]-qtd repeticoes [2]-qtd passos [3]-visitado(s/n)
	struct sNoFila *prox;
}NoFila;

typedef struct sFila{
	NoFila* inicio;
	NoFila* fim;
}Fila;

Fila* alocarFila(void){
	return (Fila*) malloc (sizeof(Fila));
}

void iniciarFila(Fila* ptrF){
	ptrF->inicio = NULL;
	ptrF->fim = NULL;
}

NoFila* alocarNoFila(){
	return (NoFila*)malloc(sizeof(NoFila));
}

void desalocarNoFila(NoFila* q){
	free(q);
}

bool filaVazia(Fila** ptrF){
	if((*ptrF)->inicio == NULL){
		return true;
	}
	return false;
}

void recarga(int* comandos, int nivel){
    switch (nivel){
        case 1:
            switch (comandos[0]){
                case 1:
                    comandos[2] = 3;
                    break;
                case 2:
                    comandos[2] = 2;
                    break;
                case 3:
                    comandos[2] = 1;
                    break;
            }
            break;
        case 2:
            switch (comandos[0]){
                case 1:
                    comandos[2] = 4;
                    break;
                case 2:
                    comandos[2] = 1;
                    break;
                case 3:
                    comandos[2] = 2;
                    break;
                case 4:
                    comandos[2] = 2;
                    break;
            }
            break;
        case 3:
            switch (comandos[0]){
                case 1:
                    comandos[2] = 2;
                    break;
                case 2:
                    comandos[2] = 2;
                    break;
                case 3:
                    comandos[2] = 2;
                    break;
                case 4:
                    comandos[2] = 1;
                    break;
            }
            break;
    }
}

void enfileirar(Fila** ptrF, int* comandos){
	Fila* aux = *ptrF;
		NoFila* novo;
		novo = alocarNoFila();

		if(novo != NULL){
			if(comandos[0] != 0){
				novo->comandos[0] = comandos[0];
				novo->comandos[1] = comandos[1];
				novo->comandos[2] = comandos[2];
				novo->prox = NULL;
				if(filaVazia(&aux)){
					aux->inicio = novo;
				}else{
					(aux->fim)->prox = novo;
				}
				aux->fim = novo;
			}
		}else{
			printf("\nERRO NA ALOCACAO DO NO!\n");
		}
}

bool desenfileirar(Fila** ptrF, int nivel){
	Fila* auxFila = *ptrF;
	NoFila* aux = (*ptrF)->inicio;
	NoFila* q = aux;
	if(!filaVazia(&auxFila)){
		if((*ptrF)->inicio->comandos[2] == 0){
			(*ptrF)->inicio->comandos[1]--;
			if((*ptrF)->inicio->comandos[1] <= 0){
				aux = aux->prox;
				free(q);
				(*ptrF)->inicio = aux;
			}else{
				(*ptrF)->inicio->comandos[3] = 0;
				recarga(aux->comandos, nivel);
			}
		}
	}
	if(filaVazia(&auxFila)){
		return true;
	}else{
		return false;
	}
}

void mostrarFila(Fila** fila){
	NoFila* aux = (*fila)->inicio;

	printf("\nFILA ->  ");
	
	if(!filaVazia(fila)){
		while(aux != NULL){
			printf("%d-%d ", aux->comandos[0], aux->comandos[1]);
			aux = aux->prox;
		}
		printf("\n");
	}
}

void apagarFila(Fila** prtF){
	NoFila* aux = (*prtF)->inicio;
	NoFila* q = aux;

	while(aux != NULL){
		aux = aux->prox;
		free(q);
		q = aux;
	}
}
