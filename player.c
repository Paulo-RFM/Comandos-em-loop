#include <stdlib.h>
#include <stdio.h>
#include "FilaDinamica.c"
#include "PilhaDinamica.c"
#include <stdbool.h>

typedef struct sPlayer{
    int sentido;
    int i,j; //referencia as linhas e colunas do tabuleiro
    int vidas;
    bool vivo;
    bool checkPoint; //quando o player chega no objetivo, usado na terceira fase
}Player;

Player* alocaPlayer(void){
    return (Player*) malloc (sizeof(Player));
}

void iniciarPlayer(Player** player){
    (*player) = (Player*) malloc (sizeof(Player));
    (*player)->i = 0;
    (*player)->j = 0;
    (*player)->sentido = 2;
    (*player)->vivo = true;
    (*player)->vidas = 3;
    (*player)->checkPoint = false;
}

void reposicionarPlayer(Player** player){
    (*player)->i = 0;
    (*player)->j = 0;
    (*player)->sentido = 2;
    (*player)->vivo = true;
}

void desalocPlayer(Player *p){
    free(p);
}

void sentidoPlayer(Player** player){
    printf("\n---- SENTIDO DO PLAYER ----");
    switch ((*player)->sentido){
    case 1:
        printf("\n^\nP\n");
        break;
    case 2:
        printf("\nP >\n\n");
        break;
    case 3:
        printf("\nP\nv\n");
        break;
    case 4:
        printf("\n< P\n\n");
        break;
    default:
        break;
    }
}

void alterarSentidoPlayer(Player** player, int* comandos, int nivel){
    if (comandos != NULL && comandos[3] != 1){
        switch (comandos[0]){
        case 2:
            if((*player)->sentido == 1){
                (*player)->sentido = 4;
            }else{
                (*player)->sentido--;
            }
            comandos[3] = 1;
            break;
        case 3:
            if((*player)->sentido == 4){
                (*player)->sentido = 1;
            }else{
                (*player)->sentido++;
            }
            comandos[3] = 1;
            break;
        case 4:
            if(nivel == 2){
                if((*player)->sentido == 1){
                    (*player)->sentido = 4;
                }else{
                    (*player)->sentido--;
                }
                comandos[3] = 1;
                break;
            }else if(nivel == 3){
                if((*player)->sentido == 4){
                    (*player)->sentido = 1;
                }else{
                    (*player)->sentido++;
                }
                comandos[3] = 1;
                break;
            }
           
        default:
            break;
        }
    }
}

void moverParaCima(Player** player, int* comandos){
    if((*player)->i > 0 && comandos[2] > 0){
        (*player)->i--;
    }
}

void moverParaDireita(Player** player, int* comandos){
    if((*player)->j < 7 && comandos[2] > 0){
        (*player)->j++;
    }
}

void moverParaBaixo(Player** player, int* comandos){
    if((*player)->i < 7 && comandos[2] > 0){
        (*player)->i++;
    }
}

void moverParaEsquerda(Player** player, int* comandos){
    if((*player)->j > 0 && comandos[2] > 0){
        (*player)->j--;
    }
}

void alteraPosPlayer(Player** player, int* comandos){
    switch ((*player)->sentido){
    case 1:
        moverParaCima(player, comandos);
        break;
    case 2:
        moverParaDireita(player, comandos);
        break;
    case 3:
        moverParaBaixo(player, comandos);
        break;
    case 4:
        moverParaEsquerda(player, comandos);
        break;
    default:
        break;
    }
    comandos[2]--;
}




