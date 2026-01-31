#include "funcoes.h"

void telaBalancoMovimentacao(){

    int i, c;

    for(i=1;i<=24;i++){
        gotoxy(1,i);   printf("|");
        gotoxy(79,i);  printf("|");
    }

    for(c=2;c<=78;c++){
        gotoxy(c,1);   printf("-");
        gotoxy(c,22);  printf("-");
        gotoxy(c,24);  printf("-");
    }

    gotoxy(1,1);   printf("+");   gotoxy(79,1);  printf("+");
    gotoxy(1,22);  printf("+");   gotoxy(79,22); printf("+");
    gotoxy(1,24);  printf("+");   gotoxy(79,24); printf("+");

    gotoxy(3,2);  printf("XYZ FARMACIA VIDA+");
    gotoxy(3,3);  printf("CONTROLE DE CUSTOS DA FARMACIA");

    gotoxy(3,5);
    printf("99/99/99");

    gotoxy(20,5); 
    printf("BALANCO DE MOVIMENTACOES");

    gotoxy(5,11);
    printf("TOTAL DE CLIENTES..................: ");

    gotoxy(5,12);
    printf("TOTAL DE MEDICAMENTOS..............: ");

    gotoxy(5,13);
    printf("TOTAL DE VENDAS....................: ");

    gotoxy(5,14);
    printf("TOTAL DE MEDICAMENTOS SEM VENDA....: ");

    gotoxy(55,5); 
    printf("PG 01");


    gotoxy(2, 23);
    printf("MSG:");

}