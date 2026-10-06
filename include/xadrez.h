#ifndef XADREZ_H
#define XADREZ_H

typedef enum{
    VAZIO,
    PEAO,
    TORRE,
    CAVALO,
    BISPO,
    RAINHA,
    REI
} Peca;

typedef enum{
    PRETO,
    BRANCO
} Cor;

typedef struct{
    Peca peca;
    Cor cor;
} Casa;

typedef enum {
    JOGANDO,
    VITORIA,
    DERROTA
} EstadoJogo;

typedef struct{
    Casa casas[8][8];
    Cor turno;
    EstadoJogo estado;
} Tabuleiro;

Tabuleiro criar_tabuleiro();

void colocar_pecas_iniciais(Tabuleiro *tabuleiro, int linha, Cor cor);

void colocar_peoes(Tabuleiro *tabuleiro, int linha, Cor cor);

#endif