#include "funcoes.h"

void telaOrdemCompras(){
    int i, c;

    for(i=1;i<=24;i++){
        gotoxy(1,i);   printf("|");
        gotoxy(79,i);  printf("|");
    }

    for(c=2;c<=78;c++){
        gotoxy(c,1);   printf("-");
        gotoxy(c,4);   printf("-");
        gotoxy(c,6);   printf("-");
        gotoxy(c,22);  printf("-");
        gotoxy(c,24);  printf("-");
    }

    gotoxy(1,1);   printf("+");   gotoxy(79,1);  printf("+");
    gotoxy(1,6);   printf("+");   gotoxy(79,6);  printf("+");
    gotoxy(1,4);   printf("+");   gotoxy(79,4);  printf("+");
    gotoxy(1,22);  printf("+");   gotoxy(79,22); printf("+");
    gotoxy(1,24);  printf("+");   gotoxy(79,24); printf("+");

    gotoxy(3,2);  printf("XYZ");
    gotoxy(3,3);  printf("FARMACIA");
    gotoxy(3,5);  printf("COD CLIENTE");
    gotoxy(17,5); printf("COD MED");
    gotoxy(30,5); printf("QUANT");
    gotoxy(42,5); printf("VALOR U.");
    gotoxy(57,5); printf("VALOR T.");
    gotoxy(72,5); printf("DATA");



    gotoxy(2, 23);
    printf("MSG:");

}