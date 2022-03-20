#include "comando.c"

void copiaElementos(int paredesI[], int paredesJ[], int paredesIX[], int paredesJX[], int sizeI, int sizeJ){
    int i = 0;
    while(i < sizeI){
        paredesI[i] = paredesIX[i];
        i++;
    }
    i = 0;
    while(i < sizeI){
        paredesJ[i] = paredesJX[i];
        i++;
    }
}

void selecionarMapa(int nivel, int* paredesI, int* paredesJ, int paredesI1[], int paredesJ1[],  int sizeI1, int sizeJ1, int paredesI2[], int paredesJ2[], int sizeI2, int sizeJ2, int paredesI3[], int paredesJ3[], int sizeI3, int sizeJ3){

    switch (nivel){
        case 1:
            copiaElementos(paredesI, paredesJ,paredesI1, paredesJ1, sizeI1, sizeJ1);
            break;
        case 2:
            copiaElementos(paredesI, paredesJ, paredesI2, paredesJ2, sizeI2, sizeJ2);
            break;
        case 3:
            copiaElementos(paredesI, paredesJ, paredesI3, paredesJ3, sizeI3, sizeJ3);
            break;
        default:
            break;
    }
}

bool renderTabuleiro(Player** player, bool faseConcluida, int nivel){
    Player* auxPlayer = *player; 
    int auxColuna[] = {0,4,8,12,16,20,24,28,32};
    int auxLinha[] = {1,3,5,7,9,11,13,15,17};

    int auxCentroSetor[] = {2,6,10,14,18,22,26,30};

    int paredesI1[] = {1,1,1,3,5,5,5,5,9,9,9,11,13,15,15,15};       
    int paredesJ1[] = {18,22,26,6,6,22,26,30,6,10,14,22,22,2,6,10};
    int sizeI1 = (int)sizeof(paredesI1)/sizeof(paredesI1[0]);
    int sizeJ1 = (int)sizeof(paredesJ1)/sizeof(paredesJ1[0]);
    
    int paredesI2[] = {1,1,3,3,3,5,5,7,7,7,7,9,11,11,11,13,13,15}; 
    int paredesJ2[] = {14,30,14,22,30,14,22,2,6,22,26,14,10,14,22,2,22,2};
    int sizeI2 = (int)sizeof(paredesI2)/sizeof(paredesI2[0]);
    int sizeJ2 = (int)sizeof(paredesJ2)/sizeof(paredesJ2[0]);

    int paredesI3[] = {1,1,3,3,5,5,7,7,7,9,9,9,11,11,13,13,13,15,15,15}; 
    int paredesJ3[] = {10,26,10,26,14,18,6,14,26,6,14,26,6,26,14,18,22,2,6,10};
    int sizeI3 = (int)sizeof(paredesI3)/sizeof(paredesI3[0]);
    int sizeJ3 = (int)sizeof(paredesJ3)/sizeof(paredesJ3[0]);

    int auxParedesI[30];
    int auxParedesJ[30];

    int k = 0;
    int i;
    int j;
    
    int Pi = 0, Pj = 0;

    selecionarMapa(nivel, auxParedesI, auxParedesJ, paredesI1, paredesJ1, sizeI1, sizeJ1, paredesI2, paredesJ2, sizeI2, sizeJ2, paredesI3, paredesJ3, sizeI3, sizeJ3);

    for(i = 0 ; i < 17  ; i++){
        for(j = 0 ; j < 33 ; j++){
            if(j == auxColuna[k]){
                printf("|");
                k++;
                continue;
            }
            if(i%2 == 0){
                printf("-");
            }else{
                if((i == auxLinha[auxPlayer->i] && j == auxCentroSetor[auxPlayer->j])){
                    if(auxLinha[auxPlayer->i] == auxParedesI[Pi] && auxCentroSetor[auxPlayer->j] == auxParedesJ[Pj]){
                    auxPlayer->vivo = false;
                    printf("#");
                    Pi++;
                    Pj++;
                    }
                    if(auxLinha[auxPlayer->i] == auxLinha[7] && auxCentroSetor[auxPlayer->j] == auxCentroSetor[7]){
                        faseConcluida = true;
                        if (nivel == 3){
                            (auxPlayer)->checkPoint = true;
                            faseConcluida = false;
                        }
                    } 
                    if(auxPlayer->vivo){
                        printf("P");
                    }
                    continue;
                }
                if(i == auxParedesI[Pi] && j == auxParedesJ[Pj]){
                    printf("X");
                    Pj++;
                    Pi++;
                    continue;
                }
                
                if(i == auxLinha[7] && j == auxCentroSetor[7]){
                    printf("o");
                    continue;
                }

                if(auxLinha[auxPlayer->i] == auxLinha[0] && auxCentroSetor[auxPlayer->j] == auxCentroSetor[0]){
                        if (nivel == 3){
                            faseConcluida = true;
                        }
                }
                 
                printf(" ");
            }
        }
        printf("\n");
        k = 0;
    }
    return faseConcluida;
}
