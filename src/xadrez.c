#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

void move_peca(Tabuleiro *tabuleiro, Posicao origem, Posicao destino){

    bool valido = false;

    if(tabuleiro->casas[origem.linha][origem.coluna].peca == PEAO)
        valido = valida_movimento_peao(tabuleiro, origem, destino);
    
    else if(tabuleiro->casas[origem.linha][origem.coluna].peca == TORRE)
        valido = valida_movimento_torre(tabuleiro, origem, destino);

    else if(tabuleiro->casas[origem.linha][origem.coluna].peca == CAVALO)
        valido = valida_movimento_cavalo(tabuleiro, origem, destino);

    else if(tabuleiro->casas[origem.linha][origem.coluna].peca == BISPO)
        valido = valida_movimento_bispo(tabuleiro, origem, destino);

    else if(tabuleiro->casas[origem.linha][origem.coluna].peca == RAINHA)
        valido = valida_movimento_rainha(tabuleiro, origem, destino);

    else if(tabuleiro->casas[origem.linha][origem.coluna].peca == REI)
        valido = valida_movimento_rei(tabuleiro, origem, destino);

    if(valido){
        tabuleiro->casas[destino.linha][destino.coluna].peca = tabuleiro->casas[origem.linha][origem.coluna].peca;
        tabuleiro->casas[destino.linha][destino.coluna].cor = tabuleiro->casas[origem.linha][origem.coluna].cor;
        tabuleiro->casas[origem.linha][origem.coluna].peca = VAZIO;
        return;
    }
    else
        //mostra um vermelhinho de erro
        return;
}

bool valida_movimento_peao(Tabuleiro *tabuleiro, Posicao origem, Posicao destino){

}

bool valida_movimento_torre(Tabuleiro *tabuleiro, Posicao origem, Posicao destino){

    if(origem.linha == destino.linha && origem.coluna == destino.coluna){
        return false;
    }

    else if(origem.linha == destino.linha){
        int dif_coluna = origem.coluna - destino.coluna;
        for(int i = 0; i < abs(dif_coluna)-1; i++){
            if(tabuleiro->casas[origem.linha][origem.coluna-dif_coluna-i].peca != VAZIO)
                return false;
        }     
    }

    else if(origem.coluna == destino.coluna){
        int dif_linha = origem.linha - destino.linha;
        for(int i = 0; i < abs(dif_linha)-1; i++){
            if(tabuleiro->casas[origem.linha-dif_linha-i][origem.coluna].peca != VAZIO)
                return false;
        } 
    }

    if(tabuleiro->casas[destino.linha][destino.coluna].peca != VAZIO 
    && tabuleiro->casas[destino.linha][destino.coluna].cor == tabuleiro->casas[origem.linha][origem.coluna].cor){

        return false;
    }

    else if(origem.linha != destino.linha || origem.coluna != destino.coluna)
        return false;

    else
        return true; 
}