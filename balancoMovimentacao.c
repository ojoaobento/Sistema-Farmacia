#include "funcoes.h"

void balancoMovimentacao(TipoListaCliente *listaCliente,TipoListaMedicamento *listaMedicamento, TipoListaMovimentacao *listaMovimentacao, TipoListaRanking *listaRanking){

    ApontadorCliente r;
    ApontadorMedicamento p;
    ApontadorMovimentacao t;
    ApontadorRanking novo;
    int contC=0;
    int contM=0;
    int contV=0;
    int contSV=0;
    int verificacao;
    int quantidade_vendida;

    
    system("cls");
    telaBalancoMovimentacao();

    r = listaCliente->primeiro;
    p = listaMedicamento->primeiro;

    while(r != NULL){
        contC++;
        r = r->proximo;
    }

    while(p != NULL){
        contM++;
        p = p->proximo;
    }

    p = listaMedicamento->primeiro;

    while(p != NULL){
        t = listaMovimentacao->primeiro;
        verificacao=0;
        while(t != NULL){
            contV += t->conteudo.quantidade;
            if(t->conteudo.cd_medicamento == p->conteudo.id){
                verificacao = 1;
            }
            t = t->proximo;
        }
        if(verificacao == 0){
            contSV++;
        }
        p = p->proximo;
    }

    gotoxy(42,11);
    printf("%d", contC);

    gotoxy(42,12);
    printf("%d", contM);

    gotoxy(42,13);
    printf("%d", contV);

    gotoxy(42,14);
    printf("%d", contSV);


    limpa_msg();
    gotoxy(2,23);
    printf("SEGUIR PARA PROXIMA PAGINA....");
    getch();
    system("cls");
    telaRanking();

    p = listaMedicamento->primeiro;
    while(p != NULL){
        t = listaMovimentacao->primeiro;
        quantidade_vendida=0;
        novo = (ApontadorRanking) malloc(sizeof(TipoRanking));
        novo->conteudo.id = p->conteudo.id;
        strcpy(novo->conteudo.nome_medicamento, p->conteudo.nome);

        while(t != NULL){
            if(t->conteudo.cd_medicamento == p->conteudo.id){
                quantidade_vendida += t->conteudo.quantidade;
            }
            t = t->proximo;
        }
        novo->conteudo.quantidade_vendida = quantidade_vendida;

        if(listaRanking->primeiro == NULL){
            listaRanking->primeiro = novo;
            listaRanking->ultimo = novo;
            listaRanking->ultimo->proximo = NULL;
        }else{
            listaRanking->ultimo->proximo = novo;
            listaRanking->ultimo = novo;
            listaRanking->ultimo->proximo = NULL;
        }

        p = p->proximo;
    }

    ordenarRanking(listaRanking);
    
    
    getch();

}