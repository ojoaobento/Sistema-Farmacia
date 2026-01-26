#include "funcoes.h"

void reposicaoEstoque(TipoListaMedicamento *listaMedicamento, TipoListaEstoque *listaEstoque){

    int codigo;
    int opcao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA ALTERAR O ESTOQUE : ");
    scanf("%d", &codigo);

    resultado = pesquisaMedicamento(listaMedicamento, codigo);

    if(resultado == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("O ID INSERIDO NAO ESTA REGISTRADO, VOLTE AO MENU PRINCIPAL....");
        getch();
        return;
    }else{

        system("cls");
        tela();
        telaMedicamentos();
        dadosMedicamento(listaMedicamento, resultado);

        limpa_msg();
        gotoxy(2,23);
        printf("REALIZAR REPOSICAO DE ESTOQUE(1-AUMENTAR,2-DIMINUIR) : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                
                gotoxy(30,17);
                scanf("%d", &temporaria.quantidade);

                limpa_msg();
                gotoxy(30,19);
                printf("CONFIRMAR REPOSICAO ( S/N )");
                scanf(" %c", &confirmacao);

                if(confirmacao == 's' || confirmacao == 'S'){
                    resultado->conteudo.quantidade = temporaria.quantidade;
                }else{
                    return;
                }

                break;
            case 2:

                break;
        }



    }

}