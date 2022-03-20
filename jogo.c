#include <stdbool.h>
#include "tabuleiro.c"
#include <unistd.h>

void removerComando(Fila** fila, Pilha** pilha, int nivel){ 
    // funcao que vai desempilhar ou desenfileirar de acordo com a fase
    switch (nivel){
    case 1:
        if((*fila)->inicio->comandos[2] == 0){
            desenfileirar(fila, nivel);
        }
        break;
    case 2:
        if((*pilha)->prox->comandos[2] == 0){
            popPilha(pilha, nivel);
        }    
        break;
    case 3:
        if(!filaVazia(fila)){
            if((*fila)->inicio->comandos[2] == 0){
                desenfileirar(fila, nivel);
            }
        }else{
            if((*pilha)->prox->comandos[2] == 0){
                popPilha(pilha, nivel);
            }
        }
    default:
    break;
    }
    
}

bool movimentarPlayer1(Player** player, Fila* fila, bool faseConcluida, int nivel){
    //funcao que movimenta o player no tabuleiro na fase 1
    if((*player)->vivo){
        if(!filaVazia(&fila)){
            system("cls");
            alterarSentidoPlayer(player, fila->inicio->comandos, nivel);
            sentidoPlayer(player);
            alteraPosPlayer(player, fila->inicio->comandos);
            faseConcluida = renderTabuleiro(player, faseConcluida, nivel);
            desenfileirar(&fila, nivel);
            mostrarFila(&fila);
            sleep(1.5);
        }
    }else{
        apagarFila(&fila);
        iniciarFila(fila);
    }
    if(faseConcluida && filaVazia(&fila)){
        printf("\n---- PARABENS! VOCE CONCLUIU O NIVEL %d !!! ----\n", nivel);
        sleep(2);
    }
   return faseConcluida;
}

bool movimentarPlayer2(Player** player, Pilha* pilha, bool faseConcluida, int nivel){
    //funcao que movimenta o player no tabuleiro na fase 2
    if((*player)->vivo){
        if(!pilhaVazia(&pilha)){
            system("cls");
            alterarSentidoPlayer(player, pilha->prox->comandos, nivel);
            sentidoPlayer(player);
            alteraPosPlayer(player, pilha->prox->comandos);
            faseConcluida = renderTabuleiro(player, faseConcluida, nivel);
            popPilha(&pilha, nivel);
            mostrarPilha(&pilha);
            sleep(1.5);
        }
    }else{
        apagarPilha(&pilha);
        iniciarPilha(pilha);
    }
    if(faseConcluida && pilhaVazia(&pilha)){
        printf("\n---- PARABENS! VOCE CONCLUIU O NIVEL %d !!! ----\n", nivel);
        sleep(2);
    }
   return faseConcluida;
}

bool movimentarPlayer3(Player** player, Pilha* pilha, Fila* fila, bool faseConcluida, int nivel){
     //funcao que movimenta o player no tabuleiro na fase 3
    bool aux = false;
    if((*player)->vivo){
        if(!(*player)->checkPoint){
            //verificando se a fila e a pilha nao estao vazias
            system("cls");
            if(!filaVazia(&fila)){
                alterarSentidoPlayer(player, fila->inicio->comandos, nivel);
                sentidoPlayer(player);
                alteraPosPlayer(player, fila->inicio->comandos);
                faseConcluida = renderTabuleiro(player, faseConcluida, nivel);
                (*player)->checkPoint = desenfileirar(&fila, nivel);
                mostrarFila(&fila);
                mostrarPilha(&pilha);
                sleep(1.5);
            }  
        }else{
            if(!pilhaVazia(&pilha)){
                system("cls");
                alterarSentidoPlayer(player, pilha->prox->comandos, nivel);
                sentidoPlayer(player);
                alteraPosPlayer(player, pilha->prox->comandos);
                faseConcluida = renderTabuleiro(player, faseConcluida, nivel);
                aux = popPilha(&pilha, nivel); //popPilha = desempilhar
                mostrarFila(&fila);
                mostrarPilha(&pilha);
                sleep(1.5);
            }
        }
    }else{
        apagarFila(&fila);
        apagarPilha(&pilha);
        iniciarFila(fila);
        iniciarPilha(pilha);
    }
    if(faseConcluida){
       	printf("\n---- PARABENS!!! VOCE CONCLUIU O JOGO!!! ----\n");
        sleep(2);
    }
   return faseConcluida;
}

void mostrarComandos(int nivel, Fila** fila, Pilha** pilha, bool checkpoint){
    //funcao que imprime os comandos das tres fases
    switch (nivel){
        case 1:
            mostrarFila(fila);
            break;
        case 2:
            mostrarPilha(pilha);
            break;
        case 3:
            if(!checkpoint){
                mostrarFila(fila);
            }else{
                mostrarPilha(pilha);
            }
            break;
        default:
            break;
        }
}

void iniciarComandos(int* comandos){
    comandos[0] = 0;
    comandos[1] = 0;
    comandos[2] = 0;
    comandos[3] = 0;
}

int primeiraFase(Player** player, int nivel){
    Fila* ptrF;
    ptrF = alocarFila();
    iniciarFila(ptrF);

    int comandos[4];
    int opcao;
    bool faseConcluida = false;

    do{
        system("cls");
        iniciarComandos(comandos);
        printf("\n---- FASE: %d ------ VIDAS: %d ----\n", nivel, (*player)->vidas);
        renderTabuleiro(player, faseConcluida, nivel);
        sentidoPlayer(player);
        mostrarFila(&ptrF);
        pedirComando1(comandos);

        if(comandos[0] != 0){
            enfileirar(&ptrF, comandos);
        }else{
            while(!filaVazia(&ptrF)){
               faseConcluida = movimentarPlayer1(player, ptrF, faseConcluida, nivel);
            }

            reposicionarPlayer(player);
            apagarFila(&ptrF);
            iniciarFila(ptrF);

            if(faseConcluida){
                ptrF = NULL;
                nivel++;
                (*player)->vidas = 3;
                return nivel;

            }else{
                (*player)->vidas--;
                return nivel;
            }
        }
    }while((*player)->vidas > 0);
}


int segundaFase(Player** player, int nivel){
    Pilha* ptrP;
    ptrP = alocarPilha();
    iniciarPilha(ptrP);

    int comandos[4];
    int opcao;
    bool faseConcluida = false;

    do{
        system("cls");
        iniciarComandos(comandos);
        printf("\n---- FASE: %d ------ VIDAS: %d -----\n", nivel, (*player)->vidas);
        renderTabuleiro(player, faseConcluida, nivel);
        sentidoPlayer(player);
        mostrarPilha(&ptrP);
        pedirComando2(comandos);

        if(comandos[0] != 0){
            pushPilha(&ptrP, comandos);
        }else{
            while(!pilhaVazia(&ptrP)){
               faseConcluida = movimentarPlayer2(player, ptrP, faseConcluida, nivel);
            }

            reposicionarPlayer(player);
            apagarPilha(&ptrP);
            iniciarPilha(ptrP);

            if(faseConcluida){
                nivel++;
                (*player)->vidas = 3;
                return nivel;
            }else{
                (*player)->vidas--;
                return nivel;
            }
        }
    }while((*player)->vidas > 0);
    return 0;
}

int terceiraFase(Player** player, int nivel){
    Fila* ptrF;
    ptrF = alocarFila();
    iniciarFila(ptrF);

    Pilha* ptrP;
    ptrP = alocarPilha();
    iniciarPilha(ptrP);

    int comandos[4];
    int opcao;
    bool faseConcluida = false;

    do{
        system("cls");
        iniciarComandos(comandos);
        printf("\n---- FASE: %d ------ VIDAS: %d -----\n", nivel, (*player)->vidas);
        renderTabuleiro(player, faseConcluida, nivel);
        sentidoPlayer(player);
        mostrarFila(&ptrF);
        pedirComando3(comandos);
        enfileirar(&ptrF, comandos);     
    }while(comandos[0] != 0);

     do{
        system("cls");
        iniciarComandos(comandos);
        printf("\n---- FASE: %d ------ VIDAS: %d -----\n", nivel, (*player)->vidas);
        renderTabuleiro(player, faseConcluida, nivel);
        sentidoPlayer(player);
        mostrarFila(&ptrF);
        mostrarPilha(&ptrP);
        pedirComando3(comandos);
        (*player)->checkPoint = pushPilha(&ptrP, comandos);    
     }while(comandos[0] != 0); 

    while(!filaVazia(&ptrF)){
        faseConcluida = movimentarPlayer3(player, ptrP, ptrF, faseConcluida, nivel);
    }
        
    while(!pilhaVazia(&ptrP)){
        faseConcluida = movimentarPlayer3(player, ptrP, ptrF, faseConcluida, nivel);
    }       
    
    if(filaVazia(&ptrF) && pilhaVazia(&ptrP)){
        reposicionarPlayer(player);
        apagarPilha(&ptrP);
        iniciarPilha(ptrP);
        apagarFila(&ptrF);
        iniciarFila(ptrF);
    }
    
    if(faseConcluida){
        nivel++;
        return nivel;
    }else{
        (*player)->vidas--;
        return nivel;
    }

}

void iniciarJogo(void){
    Player* player;
    iniciarPlayer(&player);
    int nivel = 1;

    do{
        switch(nivel){
        case 1:
            nivel = primeiraFase(&player, nivel);                
            break;
        case 2:
            nivel = segundaFase(&player, nivel);
            break;
        case 3:
            nivel = terceiraFase(&player, nivel);
            break;
        default:
            break;
        }
    }while (player->vidas > 0 && nivel < 4);

}


