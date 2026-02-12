#include "funcoes.h"

void alterarClienteNome(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;

    resultado = pesquisaCliente(listaCliente, codigo);   


    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.............");

        gotoxy(27,11);
        printf("                                                            ");

        gotoxy(27,11);
        fflush(stdin);
        fgets(temporaria.nome,16,stdin);
        removerLinha(temporaria.nome);
        verificacao=0;
        if(strlen(temporaria.nome) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPO NOME.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);


    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.nome, temporaria.nome);
    } else {
        return;
    }

}