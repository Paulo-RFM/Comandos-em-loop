#include <stdlib.h>
#include <stdbool.h>

typedef struct sNoPilha{
	int comandos[4];
	struct sNoPilha *prox;
}NoPilha;

typedef struct sPilha{
    NoPilha* prox;
}Pilha;

Pilha* alocarPilha(void){
	return (Pilha*) malloc (sizeof(Pilha));
}

void iniciarPilha(Pilha* ptrPilha){
    ptrPilha->prox = NULL;
}

void desalocarNoPilha(NoPilha* q){
    free(q);
}

bool pilhaVazia(Pilha** ptrPilha){
	if((*ptrPilha)->prox == NULL){
		return true;
	}
	return false;
}

NoPilha* alocaNoPilha(){
    return (NoPilha*) malloc (sizeof(NoPilha));
}


bool pushPilha(Pilha** pilha, int* comandos){
    Pilha* aux = *pilha;
    NoPilha* novo = alocaNoPilha(novo);
    
    if(novo != NULL){
        if(comandos[0] != 0){
            novo->comandos[0] = comandos[0];
		    novo->comandos[1] = comandos[1];
		    novo->comandos[2] = comandos[2];
            novo->comandos[3] = comandos[3];

            if(pilhaVazia(pilha)){
                (*pilha)->prox = novo;
                novo->prox = NULL;
            }else{
                novo->prox = aux->prox;
                (*pilha)->prox = novo;
            }
            return true;
        }
    }
}

bool popPilha(Pilha** pilha, int nivel){
    NoPilha* aux = (*pilha)->prox;
    if(!pilhaVazia(pilha)){
        if ((*pilha)->prox->comandos[2] == 0){
            (*pilha)->prox->comandos[1]--;
            if((*pilha)->prox->comandos[1] == 0){
                (*pilha)->prox = aux->prox;
                free(aux);
                return true;
            }else{
                (*pilha)->prox->comandos[3] = 0;
                recarga(aux->comandos, nivel);
            }
        }
    }
    return false;
}

void mostrarPilha(Pilha** pilha){
	NoPilha* aux = (*pilha)->prox;
	
	printf("\nTOPO ->  ");
	
	if(!pilhaVazia(pilha)){
		while(aux != NULL){
			printf("%d-%d ", aux->comandos[0], aux->comandos[1]);
			aux = aux->prox;
		}
        printf("\n");
	}

}

void apagarPilha(Pilha** pilha){
    NoPilha *p;
    NoPilha *t;

    p = (*pilha)->prox;
    while(p!= NULL){
            //Guardando a referencia para o proximo elemento
            t = p->prox;
            // libera a memoria apontada por p
            free(p);
            // faz apontar para prox
            p=t;
    }
}
