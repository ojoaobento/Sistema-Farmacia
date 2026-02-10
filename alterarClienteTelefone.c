#include "funcoes.h"

void alterarClienteTelefone(TipoListaCliente *listaCliente, int codigo){


    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;

    resultado = pesquisaCliente(listaCliente, codigo);   

    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO");

        gotoxy(27,13);
        printf("                    ");

        gotoxy(27,13);
        fflush(stdin);
        fgets(temporaria.telefone,20,stdin);
        removerLinha(temporaria.telefone);
        verificacao=0;
        if(strlen(temporaria.nome) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM TELEFONE VALIDO......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);


    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.telefone, temporaria.telefone);
    } else {
        return;
    }              

}