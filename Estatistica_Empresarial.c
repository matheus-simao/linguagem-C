#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura conforme enunciado
typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;

int main() {
    int n, i;
    double somaIdade = 0, somaFilhos = 0;
    double mediaIdade, mediaFilhos;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0; // Contadores para as 4 respostas
    double rendaPerCapita;
    FUNCIONARIO *funcionarios;

    // Leitura da quantidade de funcionários
    scanf("%d", &n);

    // Alocação dinâmica
    funcionarios = (FUNCIONARIO *) malloc(n * sizeof(FUNCIONARIO));
    if (funcionarios == NULL) {
        exit(1);
    }

    // Leitura dos dados e acumulação para médias
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %c %lf", 
            &funcionarios[i].matricula, 
            &funcionarios[i].idade, 
            &funcionarios[i].numFilhos, 
            &funcionarios[i].sexo, 
            &funcionarios[i].salario);

        somaIdade += funcionarios[i].idade;
        somaFilhos += funcionarios[i].numFilhos;
    }

    // Cálculo das médias gerais
    mediaIdade = somaIdade / n;
    mediaFilhos = somaFilhos / n;

    // Processamento das condições solicitadas
    for (i = 0; i < n; i++) {
        // Renda per capita (Salário / (Filhos + Pai/Mãe))
        rendaPerCapita = funcionarios[i].salario / (funcionarios[i].numFilhos + 1);

        // Condição 1: Idade > média E Salário > 3 * 1200
        if (funcionarios[i].idade > mediaIdade && funcionarios[i].salario > 3600.00) {
            q1++;
        }

        // Condição 2: Mulheres com filhos > média
        if (funcionarios[i].sexo == 'F' && funcionarios[i].numFilhos > mediaFilhos) {
            q2++;
        }

        // Condição 3: Homens com filhos > média
        if (funcionarios[i].sexo == 'M' && funcionarios[i].numFilhos > mediaFilhos) {
            q3++;
        }

        // Condição 4: > 47 anos E renda per capita < 2 * 1200
        if (funcionarios[i].idade > 47 && rendaPerCapita < 2400.00) {
            q4++;
        }
    }

    // Saída dos resultados
    printf("%d\n%d\n%d\n%d\n", q1, q2, q3, q4);

    // Liberação de memória
    free(funcionarios);

    return 0;
}