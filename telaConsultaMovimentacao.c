#include "funcoes.h"


void telaConsultaMovimentacao(){

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
    gotoxy(3,5);  printf("ID M");
    gotoxy(20,5); printf("TIPO MOVIMENTACAO");
    gotoxy(52,5); printf("QUANT");
    gotoxy(66,5); printf("DATA");

    gotoxy(52,19);
    printf("TIPO MOVIMENTACAO : ");
    gotoxy(57,20);
    printf("1 - AUMENTAR ESTOQUE");

    gotoxy(57,21);
    printf("2 - DIMINUIR ESTOQUE");

    gotoxy(2, 23);
    printf("MSG:");

}
