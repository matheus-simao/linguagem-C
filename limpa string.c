#include <stdio.h>
#include <string.h>

#define N 256 
#define ASCII_SIZE 256 
void str_clean(char str[], char clr[]);

int main() {
    char str[N]; 
    char clr[N]; 
    if (scanf("%[^\n]%*c", str) != 1) return 1;
    if (scanf("%[^\n]%*c", clr) != 1) return 1;
    str_clean(str, clr);
    printf("%s\n", str);
    return 0;
}
/**
 * @brief Remove todos os caracteres de 'clr' da string 'str' (in-place).
 * @param str A string original que será modificada (passada por referência).
 * @param clr A string contendo os caracteres indesejados.
 */
void str_clean(char str[], char clr[]) {
    int i, j, k;
    int indesejados[ASCII_SIZE] = {0};
    for (k = 0; clr[k] != '\0'; k++) {
        indesejados[(unsigned char)clr[k]] = 1; 
    }
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (indesejados[(unsigned char)str[i]] == 0) {
            str[j] = str[i];
            j++;
        } 
    }
    str[j] = '\0';
}