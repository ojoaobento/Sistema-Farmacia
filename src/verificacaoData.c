#include "funcoes.h"

int verificacaoData(char *str){

    if(strlen(str) != 10){
        return 0;
    }

    if(str[2] != '/' || str[5] != '/'){
        return 0;
    }

    return 1;

}