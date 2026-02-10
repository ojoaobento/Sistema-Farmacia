#include "funcoes.h"

void alterarClienteEnd(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;


    resultado = pesquisaCliente(listaCliente, codigo);  
    

    do{ 

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO");

        gotoxy(27,15);
        printf("                                                                      ");

        gotoxy(27,15);
        fflush(stdin);
        fgets(temporaria.endereco,60,stdin);
        removerLinha(temporaria.endereco);
        verificacao=0;
        if(strlen(temporaria.endereco) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM ENDERECO VALIDO.....");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);


    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO ( S/N ) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.endereco,temporaria.endereco);
    } else {
        return;
    }

}