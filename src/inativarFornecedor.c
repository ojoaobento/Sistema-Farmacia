#include "funcoes.h"

void inativarFornecedor(TipoListaFornecedor *listaFornecedor){

    ApontadorFornecedor resultado;
    int codigo;
    char confirmacao;
    char inativar;

    do {

        if(listaFornecedor->primeiro == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("OS FORNECEDORES ESTAO VAZIOS, VOLTE AO MENU PRINCIPAL....");
            getch();
            return;
        }

        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO FORNECEDOR QUE DESEJA INATIVAR : ");
        scanf("%d", &codigo);

        resultado = pesquisaFornecedor(listaFornecedor, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU PRINCIPAL.....");
            getch();
            return;
        }else{

            if(resultado->conteudo.status == 0){
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("O CODIGO JA ESTA INATIVADO, VOLTE AO MENU PRINCIPAL.....");
                getch();
                return;
            }

            system("cls");
            tela();
            telaFornecedor();
            dadosFornecedor(listaFornecedor, codigo);

            limpa_msg();
            gotoxy(2,23);
            printf("CONFIRMAR INATIVACAO ( S/N ) ? ");
            scanf(" %c", &confirmacao);

            if(confirmacao == 's' || confirmacao == 'S'){
                resultado->conteudo.status = 0;
                
                gotoxy(21,16);
                printf("           ");

                gotoxy(21,16);
                printf("0");
            }else{
                return;
            }

        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA INATIVACAO ( S/N ) ? ");
        scanf(" %c", &inativar);
    }while(inativar != 'n' && inativar != 'N');
}