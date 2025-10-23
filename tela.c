#include "funcoes.h"

void tela(){
    int i, c;

    for(i=1;i<=24;i++){
        gotoxy(1,i);   printf("|");
        gotoxy(79,i);  printf("|");
    }

    for(c=2;c<=78;c++){
        gotoxy(c,1);   printf("-");
        gotoxy(c,5);   printf("-");
        gotoxy(c,22);  printf("-");
        gotoxy(c,24);  printf("-");
    }

    gotoxy(1,1);   printf("+");   gotoxy(79,1);  printf("+");
    gotoxy(1,5);   printf("+");   gotoxy(79,5);  printf("+");
    gotoxy(1,22);  printf("+");   gotoxy(79,22); printf("+");
    gotoxy(1,24);  printf("+");   gotoxy(79,24); printf("+");

    gotoxy(3,2);  printf("SISTEMA FARMACIA");
    gotoxy(3,3);  printf("**********");
    gotoxy(3,4);  printf("**********");
    gotoxy(43,2); printf("*********");
    gotoxy(43,3); printf("Joao Victor dos Santos Bento");

    gotoxy(28,6);
    printf("SISTEMA DE GESTAO DE FARMACIA");

    gotoxy(40,7);
    printf("VIDA+");


    gotoxy(2, 23);
    printf("MSG:");

}

