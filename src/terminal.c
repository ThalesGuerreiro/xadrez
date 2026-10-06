#include <stdlib.h>
#include <stdio.h>
#include "terminal.h"
#include "xadrez.h"

void imprimir_tabuleiro(Tabuleiro *tabuleiro){
    int numero = 8;
    for(int i = 0; i < 8; i++){
        printf("\x1b[2m%i \x1b[0m", numero--);
        for(int j = 0; j < 8; j++){

            //Define a cor dos quadrados do tabuleiro
            if((i + j) % 2 != 0){
                printf("\x1b[45m");
            }
            else
                printf("\x1b[47m");

            imprimir_casa(tabuleiro->casas[i][j]);
            printf("\x1b[0m");
        }
        printf("\n");
    }
    printf("\x1b[2m  a b c d e f g h \x1b[0m");
}

void imprimir_casa(Casa casa){

    if(casa.peca == TORRE && casa.cor == PRETO){
        printf("\x1b[30m♜ ");
    }

    else if(casa.peca == CAVALO && casa.cor == PRETO){
        printf("\x1b[30m♞ ");
    }

    else if(casa.peca == BISPO && casa.cor == PRETO){
        printf("\x1b[30m♝ ");
    }

    else if(casa.peca == RAINHA && casa.cor == PRETO){
        printf("\x1b[30m♛ ");
    }

    else if(casa.peca == REI && casa.cor == PRETO){
        printf("\x1b[30m♚ ");
    }

    else if(casa.peca == PEAO && casa.cor == PRETO){
        printf("\x1b[30m♟ ");
    }

    else if(casa.peca == TORRE && casa.cor == BRANCO){
        printf("♖ ");
    }

    else if(casa.peca == CAVALO && casa.cor == BRANCO){
        printf("♘ ");
    }

    else if(casa.peca == BISPO && casa.cor == BRANCO){
        printf("♗ ");
    }

    else if(casa.peca == RAINHA && casa.cor == BRANCO){
        printf("♕ ");
    }

    else if(casa.peca == REI && casa.cor == BRANCO){
        printf("♔ ");
    }

    else if(casa.peca == PEAO && casa.cor == BRANCO){
        printf("♙ ");
    }

    else
        printf("  ");
}