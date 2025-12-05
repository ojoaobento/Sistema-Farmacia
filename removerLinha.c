#include "funcoes.h"

void removerLinha(char *letra) {
    size_t len = strlen(letra);

    if(len > 0 && letra[len-1] == '\n'){
        letra[len-1] = '\0';
    }
}