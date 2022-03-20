#include <stdio.h>
#include <stdlib.h>
#include "player.c"

void comandos1(void){ // funcao que define os comandos da primeira fase
    printf("\n---- COMANDOS ----\n");
    printf("\n1 - F F F");
    printf("\n2 - E F F");
    printf("\n3 - D F");
    printf("\n0 - EXECUTAR COMANDOS");
}

void comandos2(void){ // funcao que define os comandos da segunda fase
    printf("\n---- COMANDOS ----\n");
    printf("\n1 - F F F F");
    printf("\n2 - E F ");
    printf("\n3 - D F F");
    printf("\n4 - E F F");
    printf("\n0 - EXECUTAR COMANDOS");
}

void comandos3(){ // funcao que define os comandos da terceira fase
    printf("\n---- COMANDOS ----\n");
    printf("\n1 - F F");
    printf("\n2 - E F F ");
    printf("\n3 - D F F");
    printf("\n4 - D F ");
    printf("\n0 - EXECUTAR COMANDOS");
}

void pedirComando1(int* comandos){ // funcao que recebe os comandos referentes a primeira fase
    int comandoAux;
    do{
    comandos1();
    printf("\n\n---- DIGITE A OPCAO DE COMANDO -----\n");
    scanff(&comandoAux);
    comandos[0] = comandoAux;
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
        case 0:
            return;
        default:
            printf("\n---- OPCAO DE COMANDO INVALIDA! TENTE NOVAMENTE... ----\n");
            break;
        }
    }while (comandos[0] < 0 || comandos[0] > 3);

    while(comandos[1] <= 0){
        printf("\n---- DIGITE A QUANTIDADE DE VEZES QUE O COMANDO DEVERA SER EXECUTADO ----\n");
        scanff(&comandoAux);
        comandos[1] = comandoAux; 
    }
    
    
    comandos[3] = 0;
}


void pedirComando2(int* comandos){ // funcao que recebe os comandos referentes a segunda fase
    int comandoAux;
    do{
        comandos2();
        printf("\n\n---- DIGITE A OPCAO DE COMANDO -----\n");
        scanff(&comandoAux);
        comandos[0] = comandoAux;
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
            case 0:
                return;
            default:
                printf("\n---- OPCAO DE COMANDO INVALIDA! TENTE NOVAMENTE... ----\n");
                break;
            }
            
        }while (comandos[0] < 0 || comandos[0] > 4);
        
        while(comandos[1] <= 0){
            printf("\n---- DIGITE A QUANTIDADE DE VEZES QUE O COMANDO DEVERA SER EXECUTADO ----\n");
            scanff(&comandoAux);
            comandos[1] = comandoAux; 
        }
        
        comandos[3] = 0;
}

void pedirComando3(int* comandos){ // funcao que recebe os comandos referentes a terceira fase
    int comandoAux;
    do{
        comandos3();
        printf("\n\n---- DIGITE A OPCAO DE COMANDO -----\n");
        scanff(&comandoAux);
        comandos[0] = comandoAux;
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
            case 0:
                return;
            default:
                printf("\n---- OPCAO DE COMANDO INVALIDA! TENTE NOVAMENTE... ----\n");
                break;
            }
     
        }while (comandos[0] < 0 || comandos[0] > 4);
        
        while(comandos[1] <= 0){
            printf("\n---- DIGITE A QUANTIDADE DE VEZES QUE O COMANDO DEVERA SER EXECUTADO ----\n");
            scanff(&comandoAux);
            comandos[1] = comandoAux; 
        }
        comandos[3] = 0;
}
