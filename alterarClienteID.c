#include "funcoes.h"

void alterarClienteID(TipoListaCliente *listaCliente, int codigo){

    int codigo;
    int opcao;
    int codigoVerificacao;
    char alteracao;
    char novaAlteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    ApontadorCliente p_auxiliar;

    resultado = pesquisaCliente(listaCliente, codigo);

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO");

        gotoxy(11,9);
        printf(" ");

        gotoxy(11,9);
        scanf("%d", &temporaria.id_cliente);

        p_auxiliar = listaCliente->primeiro;
        codigoVerificacao = 0;
        while(p_auxiliar != NULL){
            if(p_auxiliar != resultado && p_auxiliar->conteudo.id_cliente == temporaria.id_cliente){

                limpa_msg();
                gotoxy(2,23);
                printf("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO........");
                codigoVerificacao = 1;
                getch();

                break;
            }

            p_auxiliar = p_auxiliar->proximo;
        }
    } while(codigoVerificacao == 1);

    gotoxy(30,19);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        resultado->conteudo.id_cliente = temporaria.id_cliente;
    } else {
        return;
    }

}