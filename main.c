#include <stdbool.h>
#include <stdio.h>
#include "menu.c"
#include "jogo.c"

int main(void){
    int opcao;
    do{ 
        system("cls");
        menu();
        scanff(&opcao);

        switch (opcao){
            case 1:
                iniciarJogo();
                break;
            case 2:
                regras();
                break;
            case 0:
            	printf ("\n---- FINALIZANDO JOGO...----\n");
                break;
            default:
                printf("\n---- OPCAO INVALIDA! DIGITE NOVAMENTE!!! ----\n");
                break;
        }

    }while(opcao != 0);

return 0;
}
