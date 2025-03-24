#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Nivel novato

#define TAMANHO 10
#define NAVIO_TAMANHO 3

void inicializartabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
	    tabuleiro[i][j] = 0;
	}
    
    }

}

void posicionarnavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao){
    if(orientacao == 'H' && coluna + NAVIO_TAMANHO <= TAMANHO){
        for(int i = 0; i < NAVIO_TAMANHO; i++){
	    tabuleiro[linha][coluna + i] = 3;
	}
    }else if(orientacao == 'V' && linha + NAVIO_TAMANHO <= TAMANHO){
        for(int i = 0; i < NAVIO_TAMANHO; i++){
	    tabuleiro[linha + i][coluna] = 3;
	}
    }

}

void exibirtabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
	    printf("%d ", tabuleiro[i][j]);
	}
	printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int tabuleiro[TAMANHO][TAMANHO];
    inicializartabuleiro(tabuleiro);

    //Coordenadas 
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 7;

    //Posição do navio
    posicionarnavio(tabuleiro, linhaH, colunaH, 'H');
    posicionarnavio(tabuleiro, linhaV, colunaV, 'V');

    //Exibe o tabuleiro
    exibirtabuleiro(tabuleiro);

    return 0;
}
