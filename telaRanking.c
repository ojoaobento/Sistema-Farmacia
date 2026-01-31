#include "funcoes.h"

void telaRanking(){

    int i, c;

    for(i=1;i<=24;i++){
        gotoxy(1,i);   printf("|");
        gotoxy(79,i);  printf("|");
    }

    for(c=2;c<=78;c++){
        gotoxy(c,1);   printf("-");
        gotoxy(c,6);   printf("-");
        gotoxy(c,8);   printf("-");
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

    gotoxy(55,5); 
    printf("PG 02");


    gotoxy(25,7);
    printf("TOP 10 MEDICAMENTOS MAIS VENDIDOS");

    gotoxy(3,9);
    printf("ID");

    gotoxy(32,9);
    printf("MEDICAMENTO");

    gotoxy(67,9);
    printf("QUANTIDADE");

    gotoxy(2, 23);
    printf("MSG:");

}