#include "funcoes.h"

void alterarClienteData(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;

    resultado = pesquisaCliente(listaCliente, codigo);


    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO..........");

        gotoxy(27,16);
        printf("                          ");               

        gotoxy(27,16);
        fflush(stdin);
        fgets(temporaria.data_cadastro,12,stdin);
        removerLinha(temporaria.data_cadastro);
        verificacao=0;
        if(strlen(temporaria.data_cadastro) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPO DATA........");
            verificacao=1;
            getch();
        }else if (verificacaoData(temporaria.data_cadastro) != 1){
            limpa_msg();
            gotoxy(2,23);
            printf("DATA INVALIDA, INSIRA NOVAMENTE........");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);   

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO ( S/N ) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.data_cadastro,temporaria.data_cadastro);
    } else {
        return;
    }

}