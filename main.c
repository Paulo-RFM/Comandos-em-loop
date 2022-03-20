#include <stdbool.h>
#include <stdio.h>
#include "menu.c"
#include "jogo.c"
#include <ctype.h> //para ultilizar o isdigit()

int conversao(char c){
    if(c == '0'){
        return 0;
    }
    if(c == '1'){
        return 1;
    }
    if(c == '2'){
        return 2;
    }
    if(c == '3'){
        return 3;
    }
    if(c == '4'){
        return 4;
    }
    if(c == '5'){
        return 5;
    }else{
        return 0;
    }
}

int atribuiValor(char c){
    return conversao(c);
}

void scanff(int* op){
    int aux = *op;
    char c;
    int result = -1;
    do{
        c = getchar();
        result = isdigit(c); // se retornar 0 é caracter nao numeral, se retornar outro numero é caracter numero
        if(result != 0){//se for numero
            aux = atribuiValor(c);
            c = '0';
        }
    }while(c != '0');
    *op = aux;
}

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
