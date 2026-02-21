#include "funcoes.h"

void alterarClienteStatus(TipoListaCliente *listaCliente, int codigo){
    
    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;

    resultado = pesquisaCliente(listaCliente, codigo);  

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO..........");

        gotoxy(27,17);
        printf("    ");

        gotoxy(27,17);
        scanf("%d", &temporaria.status);
        verificacao=0;
        if(temporaria.status != 0 && temporaria.status != 1){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM STATUS VALIDO.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO ( S/N ) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        resultado->conteudo.status = temporaria.status;
    } else {
        return;
    }

}