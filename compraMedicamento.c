#include "funcoes.h"

void compraMedicamento(TipoListaMovimentacao *listaMovimentacao, TipoListaCliente *listaCliente, TipoListaMedicamento *listaMedicamento){

    ApontadorMovimentacao novo;
    reg_movimentacoes temporaria;
    ApontadorCliente p;
    int verificacao;

    system("cls");
    tela();
    telaMovimentacao();

    novo = (ApontadorMovimentacao) malloc(sizeof(TipoMovimentacao));

    do{
        limpa_msg();
        gotoxy(33,10);
        printf("           ");

        gotoxy(33,10);
        scanf("%d", &temporaria.cd_cliente);
        p = listaCliente->primeiro;
        verificacao=0;
        while(p != NULL){
            if(temporaria.cd_cliente == p->conteudo.id_cliente && p->conteudo.status == 1){
                novo->conteudo.cd_cliente = temporaria.cd_cliente;
                verificacao=1;
                gotoxy(38,10);
                printf(" - %s", p->conteudo.nome);
                break;
            }
            p = p->proximo;
        }

        if(verificacao == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE OU ESTA INATIVO, INSIRA OUTRO........");
            getch();
        }

    }while(verificacao != 1);

    gotoxy(33,11);
    


}