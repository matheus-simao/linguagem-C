#include <stdio.h>
 
#define MAX_LINE_LENGTH 55 
char custom_toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c; 
}
char custom_tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c; 
}
int custom_isalpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int main() {
    char linha[MAX_LINE_LENGTH];
    while (scanf("%[^\n]%*c", linha) == 1) {
        
        int is_uppercase_next = 1; 
        int i;
        int len = 0;
        while (linha[len] != '\0') {
            len++;
        }
        for (i = 0; i < len; i++) {
            char c = linha[i];
            if (custom_isalpha(c)) {
                
                if (is_uppercase_next) {
                    printf("%c", custom_toupper(c));
                } else {
                    printf("%c", custom_tolower(c));
                }
                is_uppercase_next = !is_uppercase_next;
                
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
 
    return 0;
}