#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void initializeBoard(int board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0; // Preenche o tabuleiro com 0s (vazio)
        }
    }
}

void addShipHorizontal(int board[10][10], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        board[linha][coluna + i] = 3; // Marca a posição do navio
    }
}
void addShipVertical(int tabuleiro[10][10], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna] = 3; // Marca a posição do navio
    }
}
void addShipDiagonal(int board[10][10], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        board[linha + i][coluna + i] = 3; // Marca a posição do navio
    }
}

void showBoard(int board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]); // Exibe o tabuleiro
        }
        printf("\n");
    }
}

void triangleSkill(int tabuleiro[10][10], int linha, int coluna) {
    // Implementar habilidade triangular
    for (int i = 0; i < 3; i++) { // Altura do triângulo limitada a 3
        for (int j = -i; j <= i; j++) { // Largura cresce com a altura
            if (j >= -2 && j <= 2) { // Limita a base a no máximo 5 índices
                if (linha + i < 10 && coluna + j >= 0 && coluna + j < 10) {
                    tabuleiro[linha + i][coluna + j] = 1; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

void crossSkill(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 1 || j == 2) && (linha + i < 10 && coluna + j < 10)) {
                tabuleiro[linha + i][coluna + j] = 1; // Marca a área afetada pela habilidade
            }
        }
    }
}

void octahedronSkill(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 1 || j == 1) && (linha + i < 10 && coluna + j < 10)) {
                tabuleiro[linha + i][coluna + j] = 1; // Marca a área afetada pela habilidade
            }
        }
    }
}

int main() {
    int board[10][10] = {0}; // Matriz para representar o tabuleiro 10x10
    
    initializeBoard(board); // Inicializa o tabuleiro

    // adicionando navios
    addShipHorizontal(board, 0, 0, 3); // Navio horizontal na linha 0, coluna 0
    addShipVertical(board, 1, 1, 3); // Navio vertical na linha 1, coluna 1
    addShipDiagonal(board, 2, 2, 3); // Navio diagonal na linha 2, coluna 2
    addShipDiagonal(board, 2, 4, 3); // Navio diagonal na linha 3, coluna 3

    // Exibe o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    showBoard(board);

    // Exemplo de uso das habilidades:
    int linha = 2; // Linha onde a habilidade será aplicada
    int coluna = 2; // Coluna onde a habilidade será aplicada

    printf("\nTabuleiro Após aplicar a habilidade triangulo:\n");

    // Aplica a habilidade
    crossSkill(board, linha, coluna);

    /**
     * Descomente as linhas abaixo para testar outras habilidades
     * triangleSkill(board, linha, coluna);
     * octahedronSkill(board, linha, coluna);
     */

    // Exibe o tabuleiro após aplicar a habilidade
    showBoard(board); 

    return 0;
}
