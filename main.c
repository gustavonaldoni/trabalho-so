#include <stdio.h>
#include <stdlib.h>

#define VITORIA 4

#define LINHAS 6
#define COLUNAS 7

#define P1 1
#define P2 2

int tabuleiro[LINHAS][COLUNAS] = {{0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 2},
                                  {0, 1, 1, 0, 0, 2, 0},
                                  {0, 0, 1, 2, 2, 0, 0},
                                  {0, 0, 2, 2, 1, 0, 0},
                                  {0, 2, 1, 2, 2, 1, 0}};

void limpar_tela();

void mostrar_tabuleiro();
int atualizar_tabuleiro(int, int, int);
int jogar(int, int);

int ganhou_horizontal(int);
int ganhou_vertical(int);
int ganhou_diagonal(int);

int main()
{
    mostrar_tabuleiro();

    printf("\n");

    printf("%d ", ganhou_diagonal(P2));

    return 0;
}

void limpar_tela()
{
    system("clear");
}

void mostrar_tabuleiro()
{
    int i, j;

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }
}

int atualizar_tabuleiro(int numero_linha, int numero_coluna, int codigo_jogador)
{
    tabuleiro[numero_linha][numero_coluna] = codigo_jogador;
    return 1;
}

int jogar(int numero_coluna, int codigo_jogador)
{
    int i = 0;

    for (i = 0; i < LINHAS; i++)
    {
        // A coluna inteira está ocupada
        if ((i == 0) && (tabuleiro[i][numero_coluna] != 0))
            return -1;

        // Há pelo menos uma jogada na coluna
        if (tabuleiro[i][numero_coluna] != 0)
        {
            atualizar_tabuleiro(i - 1, numero_coluna, codigo_jogador);
            return 1;
        }

        // Não há nenhuma jogada na coluna
        if ((i == LINHAS - 1) && (tabuleiro[i][numero_coluna] == 0))
        {
            atualizar_tabuleiro(i, numero_coluna, codigo_jogador);
            return 1;
        }
    }

    return 1;
}

int ganhou_horizontal(int codigo_pessoa)
{
    int i, j;
    int contador = 0;

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == codigo_pessoa)
            {
                contador++;

                if (contador == VITORIA)
                    return 1;
            }

            else
                contador = 0;
        }

        contador = 0;
    }

    return 0;
}

int ganhou_vertical(int codigo_pessoa)
{
    int i, j;
    int contador = 0;

    for (j = 0; j < COLUNAS; j++)
    {
        for (i = 0; i < LINHAS; i++)
        {
            if (tabuleiro[i][j] == codigo_pessoa)
            {
                contador++;

                if (contador == VITORIA)
                    return 1;
            }

            else
                contador = 0;
        }

        contador = 0;
    }

    return 0;
}

int ganhou_diagonal(int codigo_pessoa)
{
    int coluna_original;
    int i, j;
    int contador = 0;

    // Diagonal cima pra baixo
    for (coluna_original = 0; coluna_original < COLUNAS; coluna_original++)
    {
        // printf("coluna_original = %d\n", coluna_original);

        j = coluna_original;
        i = LINHAS - 1;

        while (i >= 0 && j >= 0)
        {
            // printf("i = %d\n", i);
            // printf("j = %d\n", j);

            if (tabuleiro[i][j] == codigo_pessoa)
            {
                contador++;
                // printf("contador = %d\n", contador);

                if (contador == VITORIA)
                    return 1;
            }
            else
                contador = 0;

            j--;
            i--;
        }

        contador = 0;
    }

    // Diagonal baixo pra cima
    for (coluna_original = 0; coluna_original < COLUNAS; coluna_original++)
    {
        // printf("coluna_original = %d\n", coluna_original);

        j = coluna_original;
        i = 0;

        while (i >= 0 && j >= 0)
        {
            // printf("i = %d\n", i);
            // printf("j = %d\n", j);

            if (tabuleiro[i][j] == codigo_pessoa)
            {
                contador++;
                // printf("contador = %d\n", contador);

                if (contador == VITORIA)
                    return 1;
            }
            else
                contador = 0;

            j--;
            i++;
        }

        contador = 0;
    }

    for (coluna_original = COLUNAS - 1; coluna_original >= 0; coluna_original--)
    {
        printf("coluna_original = %d\n", coluna_original);

        j = coluna_original;
        i = LINHAS - 1;

        while (i >= 0 && j <= COLUNAS - 1)
        {
            printf("i = %d\n", i);
            printf("j = %d\n", j);

            if (tabuleiro[i][j] == codigo_pessoa)
            {
                contador++;
                printf("contador = %d\n", contador);

                if (contador == VITORIA)
                    return 1;
            }
            else
                contador = 0;

            j++;
            i--;
        }

        contador = 0;
    }

    return 0;
}