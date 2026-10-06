#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "xadrez.h"
#include "terminal.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    
    Tabuleiro tabuleiro = criar_tabuleiro();
    if (tabuleiro.casas == NULL){
        return 1;
    }

    imprimir_tabuleiro(&tabuleiro);

}