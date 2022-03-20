#include <stdio.h>
#include <stdlib.h>

void menu(void){
    printf("\n---- MENU PRINCIPAL ----\n");
	printf("\n1 - INICIAR JOGO");
	printf("\n2 - REGRAS DO JOGO");
	printf("\n0 - SAIR DO JOGO");
    printf("\n\n---- DIGITE UMA OPCAO ----\n");
}

void regras(){
    printf("\t\t-----------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tFUNCIONAMENTO DO JOGO\n\n");
    printf("1 - O jogador deve informar a sequencia dos comandos;\n");
    printf("2 - O jogador deve informar a quantidade de vezes que os comandos serao executados;\n");
    printf("3 - O jogador tera 3 tentativas para atingir o objetivo;\n");
    printf("4 - O comando D rotaciona o sentido do player no sentido horario;\n");
    printf("5 - O comando E rotaciona o sentido do player no sentido anti horario;\n");
    printf("\n\t\t-----------------------------------------------------------------------\n");
}
