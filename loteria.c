#include <stdio.h>
void ordenar_bubble(int vetor[], int N);

int main(){
    int num_sorteado[6], apostas[6];
    int N, i, j;
    int quadra = 0, quina = 0, sena = 0, contador = 0;

    for(i = 0; i < 6; i++){
        scanf("%d", &num_sorteado[i]);
    }
    scanf("%d", &N);
    while(N--){
        int contador = 0;
        for(i = 0; i < 6; i++){
            scanf("%d", &apostas[i]);
        }
        ordenar_bubble(num_sorteado, 6);
        ordenar_bubble(apostas, 6);
        for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                if(apostas[i] == num_sorteado[j]){
                    contador++;
                }
            }
        }
        switch(contador){
            case 4:
                quadra++;
                break;
            case 5:
                quina++;
                break;
            case 6:
                sena++;
                break;
        }
    }
    if(sena == 0){
        printf("Nao houve acertador para sena\n");
    } else{
        printf("Houve %d acertador(es) da sena\n", sena);
    }
    if(quina == 0){
        printf("Nao houve acertador para quina\n");
    } else{
        printf("Houve %d acertador(es) da quina\n", quina);
    }
    if(quadra == 0){
        printf("Nao houve acertador para quadra\n");
    } else{
        printf("Houve %d acertador(es) da quadra\n", quadra);
    }

    return 0;
}
void ordenar_bubble(int vetor[], int N) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}