#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Nivel aventureiro

#define TAMANHO 10
#define NAVIO_TAMANHO 3
#define NAVIOS 4

void inicializartabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
	    tabuleiro[i][j] = 0;
	}
    
    }

}


int podeposicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcaolinha, int direcaocoluna){

    for(int i = 0; i < NAVIO_TAMANHO; i++){
        int novalinha = linha + (i * direcaolinha);
	int novacoluna = coluna + (i * direcaocoluna);

	if(novalinha < 0 || novalinha >= TAMANHO || novacoluna < 0 || novacoluna >= TAMANHO){
	    return 0;
	
	}
	if(tabuleiro[novalinha][novacoluna] != 0){
	    return 0;
	}
    }
    return 1;


}

void posicionarnavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcaolinha, int direcaocoluna){
    for(int i = 0; i < NAVIO_TAMANHO; i++){
        tabuleiro[linha + (i * direcaolinha)][coluna + (i * direcaocoluna)] = 3;
    
    }
}

void exibirtabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    printf("\nTabuleiro\n");
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
	    printf("%d", tabuleiro[i][j]);
	}
	printf("\n");
    }

}

int main() {
    setlocale(LC_ALL, "portuguese");

    int tabuleiro[TAMANHO][TAMANHO];
    inicializartabuleiro(tabuleiro);

    int navios[4][4] = {
        {2, 4, 0, 1},
	{5, 7, 1, 0},
	{1, 1, 1, 1},
	{2, 8, 1, -1}
    
    };

    for(int i = 0; i < NAVIOS; i++){
        int linha = navios[i][0];
	int coluna = navios[i][1];
	int direcaolinha = navios[i][2];
	int direcaocoluna = navios[i][3];

	if(podeposicionar(tabuleiro, linha, coluna, direcaolinha, direcaocoluna)){
	    posicionarnavio(tabuleiro, linha, coluna, direcaolinha, direcaocoluna);
	
	}else{
	    printf("Erro ao posicionar o navio %d. Coordenadas inválidas!\n", i + 1);
	}
    
    }

    exibirtabuleiro(tabuleiro);

    return 0;
}
