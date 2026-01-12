#include "funcoes.h"

void alterarMedicamentoIdFornecedor(TipoListaMedicamento *listaMedicamento, TipoListaFornecedor *listaFornecedor, int codigo){
    
    int verificacao;
    ApontadorMedicamento resultado;
    ApontadorFornecedor p_auxiliar;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamento, codigo);   

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO......");

        gotoxy(30,10);
        printf("                   ");

        gotoxy(30,10);
        scanf("%d", &temporaria.id_fornecedor);
        verificacao=0;
        p_auxiliar = listaFornecedor->primeiro;
        while(p_auxiliar != NULL){
            if(temporaria.id_fornecedor == p_auxiliar->conteudo.id){
                verificacao=1;
                break;
            }
            p_auxiliar = p_auxiliar->proximo;
        }


        if(verificacao == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("O ID DE FORNECEDOR INSERIDO NAO EXISTE, INSIRA OUTRO.......");
            getch();
        }

    }while(verificacao != 1);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.id_fornecedor = temporaria.id_fornecedor;
    } else{
        return;
    }   

}