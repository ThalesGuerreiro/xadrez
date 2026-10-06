#include <stdlib.h>
#include <stdio.h>
#include "xadrez.h"

Tabuleiro criar_tabuleiro(){

    Tabuleiro tabuleiro;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tabuleiro.casas[i][j].peca = VAZIO;
        }
    }

    tabuleiro.turno = BRANCO;
    tabuleiro.estado = JOGANDO;

    colocar_pecas_iniciais(&tabuleiro, 0, PRETO);
    colocar_peoes(&tabuleiro, 1, PRETO);
    colocar_peoes(&tabuleiro, 6, BRANCO);
    colocar_pecas_iniciais(&tabuleiro, 7, BRANCO);

    return tabuleiro;
}

void colocar_pecas_iniciais(Tabuleiro *tabuleiro, int linha, Cor cor){

    tabuleiro->casas[linha][0].peca = TORRE;
    tabuleiro->casas[linha][0].cor = cor;

    tabuleiro->casas[linha][1].peca = CAVALO;
    tabuleiro->casas[linha][1].cor = cor;

    tabuleiro->casas[linha][2].peca = BISPO;
    tabuleiro->casas[linha][2].cor = cor;

    tabuleiro->casas[linha][3].peca = RAINHA;
    tabuleiro->casas[linha][3].cor = cor;

    tabuleiro->casas[linha][4].peca = REI;
    tabuleiro->casas[linha][4].cor = cor;

    tabuleiro->casas[linha][5].peca = BISPO;
    tabuleiro->casas[linha][5].cor = cor;

    tabuleiro->casas[linha][6].peca = CAVALO;
    tabuleiro->casas[linha][6].cor = cor;

    tabuleiro->casas[linha][7].peca = TORRE;
    tabuleiro->casas[linha][7].cor = cor;
}

void colocar_peoes(Tabuleiro *tabuleiro, int linha, Cor cor){
    
    for(int j = 0; j < 8; j++){
        tabuleiro->casas[linha][j].peca = PEAO;
        tabuleiro->casas[linha][j].cor = cor;
    }
}