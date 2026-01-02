#include "funcoes.h"

void exclusaoFornecedor(TipoListaFornecedor *listaFornecedor){

    ApontadorFornecedor resultado;
    ApontadorFornecedor p_auxiliar;
    ApontadorFornecedor r_auxiliar;
    int codigo;
    char confirmacao;
    char exclusao;
    
    do {
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO FORNECEDOR QUE DESEJA EXCLUIR : ");
        scanf("%d", &codigo);

        resultado = pesquisaFornecedor(listaFornecedor, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, VOLTE AO MENU PRINCIPAL.....");
            getch();
            return;
        }else{
            system("cls");
            tela();
            telaFornecedor();
            dadosFornecedor(listaFornecedor, codigo);

            gotoxy(30,19);
            printf("CONFIRMAR EXCLUSAO ( S/N ) ? ");
            scanf(" %c", &confirmacao);

            if(confirmacao == 's' || confirmacao == 'S'){
                if(resultado->conteudo.id == listaFornecedor->primeiro->conteudo.id){
                    if(listaFornecedor->primeiro == listaFornecedor->ultimo){
                        p_auxiliar = listaFornecedor->primeiro;
                        listaFornecedor->primeiro = NULL;
                        listaFornecedor->ultimo = NULL;
                        free(p_auxiliar);

                        system("cls");
                        tela();
                        limpa_msg();
                        gotoxy(2,23);
                        printf("NAO EXISTE MAIS NENHUMA EXCLUSAO, VOLTE AO MENU PRINCIPAL.....");
                        getch();
                        return;

                    }else{
                        p_auxiliar = listaFornecedor->primeiro;
                        listaFornecedor->primeiro = p_auxiliar->proximo;
                        listaFornecedor->primeiro->anterior = NULL;
                        free(p_auxiliar);
                    }
                }else if(resultado->conteudo.id == listaFornecedor->ultimo->conteudo.id){
                    p_auxiliar = listaFornecedor->ultimo;
                    listaFornecedor->ultimo = p_auxiliar->anterior;
                    listaFornecedor->ultimo->proximo = NULL;
                    free(p_auxiliar);
                }else{
                    p_auxiliar = listaFornecedor->primeiro;
                    r_auxiliar = p_auxiliar->proximo;
                    while(r_auxiliar != NULL && r_auxiliar->conteudo.id != resultado->conteudo.id){
                        p_auxiliar = p_auxiliar->proximo;
                        r_auxiliar = r_auxiliar->proximo;
                    }
                    p_auxiliar->proximo = r_auxiliar->proximo;
                    r_auxiliar->proximo->anterior = p_auxiliar;
                    free(r_auxiliar);
                }
            }
        }

        gotoxy(30,20);
        printf("NOVA EXCLUSAO ( S/N ) ? ");
        scanf(" %c", &exclusao);

    }while(exclusao != 'n' && exclusao != 'N');
}