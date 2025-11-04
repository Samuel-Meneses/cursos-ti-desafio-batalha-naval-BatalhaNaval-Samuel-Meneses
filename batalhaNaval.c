#include <stdio.h>

int main()
{

    int i, j;

    // 1️⃣ Tabuleiro 10x10 inicializado com água (0)
    int tabuleiro[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Colocar navios (valor 3) – mesmo estilo anterior
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3; // horizontal
    tabuleiro[6][4] = 3;
    tabuleiro[7][4] = 3;
    tabuleiro[8][4] = 3; // vertical
    tabuleiro[2][5] = 3;
    tabuleiro[3][6] = 3;
    tabuleiro[4][7] = 3; // diagonal ↘
    tabuleiro[7][7] = 3;
    tabuleiro[8][6] = 3;
    tabuleiro[9][5] = 3; // diagonal ↙

    // 3️⃣ Matrizes das habilidades (5x5)
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Preencher Cone dinamicamente
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 0 && j == 2)
                cone[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3)
                cone[i][j] = 1;
            else if (i == 2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Preencher Cruz dinamicamente
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Preencher Octaedro dinamicamente
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if ((i + j >= 2 && i + j <= 6) && (j - i <= 2) && (i - j <= 2))
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // 4️⃣ Pontos de origem no tabuleiro
    int oc = 1, oc2 = 6; // linha, coluna
    int cx = 5, cy = 2;
    int ox = 4, oy = 5;

    // 5️⃣ Aplicar cada habilidade no tabuleiro
    // Aplicar Cone
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (cone[i][j] == 1)
            {
                int x = oc + i;
                int y = oc2 + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10 && tabuleiro[x][y] != 3)
                {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Aplicar Cruz
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (cruz[i][j] == 1)
            {
                int x = cx + i;
                int y = cy + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10 && tabuleiro[x][y] != 3)
                {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Aplicar Octaedro
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (octaedro[i][j] == 1)
            {
                int x = ox + i;
                int y = oy + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10 && tabuleiro[x][y] != 3)
                {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // 6️⃣ Mostrar tabuleiro final
    printf("\n===== TABULEIRO FINAL (NIVEL MESTRE) =====\n\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
