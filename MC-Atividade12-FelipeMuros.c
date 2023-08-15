/*Considerando o Sistema abaixo, implemente o algoritmo de Decomposição LU para solucioná-lo.
Devem ser criadas as matrizes A, L e U, além dos vetores x, y e b.
Obs. 1.: Todas as matrizes e vetores utilizados devem ser declarados na função main;
Obs. 2.: Seu algoritmo pode ser testado com outro Sistema;
Obs. 3.: Lembre-se que você terá que utilizar os algoritmos de solução de Sistemas Triangulares Superiores e Inferiores (já estudados) para resolver o Sistema.
A = {{3,2,4}{1,1,2}{4,3,-2}}
b ={1,2,3}*/

//Aluno Felipe Muros

#include <stdio.h>
#include <stdlib.h>
#define N 3

float decomporLUResolverSistema(float A[N][N], float L[N][N], float U[N][N], float b[N], float y[N], float x[N]){
    int i, j, k;
    float soma;

    //Decomposição LU
    for (i = 0; i < N; i++)
    {
        L[i][i] = 1;
        for (j = i; j < N; j++)
        {
            soma = 0;
            for (k = 0; k < i; k++)
            {
                soma = soma + L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - soma;
        }
        for (j = i + 1; j < N; j++)
        {
            soma = 0;
            for (k = 0; k < i; k++)
            {
                soma = soma + L[j][k] * U[k][i];
            }
            L[j][i] = (A[j][i] - soma) / U[i][i];
        }
    }

       //Solução do Sistema Ly = b
    for (i = 0; i < N; i++)
    {
        soma = 0;
        for (j = 0; j < i; j++)
        {
            soma = soma + L[i][j] * y[j];
        }
        y[i] = (b[i] - soma) / L[i][i];
    }

    //Solução do Sistema Ux = y
    for (i = N - 1; i >= 0; i--)
    {
        soma = 0;
        for (j = i + 1; j < N; j++)
        {
            soma = soma + U[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / U[i][i];
    } 
}

void printResultado(float x[N]){
    int i;
    printf("\nResultado:\n");
    for (i = 0; i < N; i++)
    {
        printf("x[%d] = %.0f\n", i, x[i]);
    }
}

int main()
{   
    float A[N][N] = {{3,2,4},{1,1,2},{4,3,-2}};
    float L[N][N];
    float U[N][N];
    float b[N] = {1,2,3};
    float y[N];
    float x[N]; 

    decomporLUResolverSistema(A, L, U, b, y, x);
    printResultado(x);
}