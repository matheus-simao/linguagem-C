#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de interação
typedef struct {
    int num_likes;
    int num_retweets;
    int num_mencoes;
} INTERACAO;

int main() {
    int N, M, i, j;
    int u1, u2, likes, rts, mencoes;
    int totalLikesUser, totalRtsUser, totalMencoesUser;
    double somaLikesGeral = 0, somaRtsGeral = 0, somaMencoesGeral = 0;
    int usuariosAtivos = 0; // Usuários que fizeram interações
    int slotsVazios = 0;
    INTERACAO ***mat; // Matriz de ponteiros para structs

    // Leitura da dimensão N e quantidade de relações M
    scanf("%d", &N);
    scanf("%d", &M);

    // Alocação da matriz de ponteiros (N linhas)
    mat = (INTERACAO ***) malloc(N * sizeof(INTERACAO **));
    if (mat == NULL) exit(1);

    // Alocação das colunas e inicialização com NULL
    for (i = 0; i < N; i++) {
        mat[i] = (INTERACAO **) malloc(N * sizeof(INTERACAO *));
        if (mat[i] == NULL) exit(1);
        
        for (j = 0; j < N; j++) {
            mat[i][j] = NULL; // Garante que começa vazio
        }
    }

    // Leitura das M interações e alocação sob demanda
    for (i = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &u1, &u2, &likes, &rts, &mencoes);

        // Aloca a struct apenas se ainda for NULL
        if (mat[u1][u2] == NULL) {
            mat[u1][u2] = (INTERACAO *) malloc(sizeof(INTERACAO));
            if (mat[u1][u2] == NULL) exit(1);
        }

        // Preenche os dados
        mat[u1][u2]->num_likes = likes;
        mat[u1][u2]->num_retweets = rts;
        mat[u1][u2]->num_mencoes = mencoes;
    }

    // Processamento e Saída por Usuário
    for (i = 0; i < N; i++) {
        totalLikesUser = 0;
        totalRtsUser = 0;
        totalMencoesUser = 0;
        int temInteracao = 0;

        for (j = 0; j < N; j++) {
            if (mat[i][j] != NULL) {
                totalLikesUser += mat[i][j]->num_likes;
                totalRtsUser += mat[i][j]->num_retweets;
                totalMencoesUser += mat[i][j]->num_mencoes;
                temInteracao = 1;
            } else {
                slotsVazios++;
            }
        }

        // Soma aos totais gerais se o usuário teve atividade
        if (temInteracao) {
            printf("Usuario %d num. likes: %d, num. retweets: %d e num. mencoes: %d\n", 
                   i, totalLikesUser, totalRtsUser, totalMencoesUser);
            
            somaLikesGeral += totalLikesUser;
            somaRtsGeral += totalRtsUser;
            somaMencoesGeral += totalMencoesUser;
            usuariosAtivos++;
        }
    }

    // Saída das estatísticas globais
    printf("Slots vazios: %d\n", slotsVazios);
    
    // Evita divisão por zero caso nenhum usuário tenha interagido
    if (usuariosAtivos > 0) {
        printf("Media de likes por usuario: %.2f\n", somaLikesGeral / usuariosAtivos);
        printf("Media de retweets por usuario: %.2f\n", somaRtsGeral / usuariosAtivos);
        printf("Media de mencoes por usuario: %.2f\n", somaMencoesGeral / usuariosAtivos);
    }

    // Liberação de memória
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (mat[i][j] != NULL) {
                free(mat[i][j]); // Libera a struct
            }
        }
        free(mat[i]); // Libera a linha de ponteiros
    }
    free(mat); // Libera o vetor principal

    return 0;
}