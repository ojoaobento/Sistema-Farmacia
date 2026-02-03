#include "funcoes.h"

void exclusaoCliente(TipoListaCliente *listaCliente){

    ApontadorCliente resultado;
    ApontadorCliente p_auxiliar;
    ApontadorCliente r_auxiliar;
    int codigo;
    char exclusao;
    char novaExclusao;

    do {
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO CADASTRO QUE DESEJA EXCLUIR: ");
        scanf("%d", &codigo);

        resultado = pesquisaCliente(listaCliente, codigo);

        if(resultado == NULL){
            system("cls");
            tela();

            limpa_msg();

            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU PRINCIPAL....");

            getch();

            return;
        } else {
            system("cls");
            tela();
            telaCliente();
            dadosCliente(listaCliente, codigo);


            limpa_msg();
            gotoxy(2,23);
            printf("CONFIRMA EXCLUSAO ( S/N ) ? ");
            scanf(" %c", &exclusao);

            if(exclusao == 's' || exclusao == 'S'){

                if(resultado->conteudo.id_cliente == listaCliente->primeiro->conteudo.id_cliente){
                    if(listaCliente->primeiro == listaCliente->ultimo){ 
                        p_auxiliar = listaCliente->primeiro;

                        listaCliente->primeiro = NULL;
                        listaCliente->ultimo = NULL;
                        free(p_auxiliar);

                        limpa_msg();
                        gotoxy(2,23);
                        printf("O SISTEMA DE CADASTRO ESTA VAZIO, RETORNE AO MENU PRINCIPAL....");
                        getch();

                        return;


                    }else {
                        p_auxiliar = listaCliente->primeiro;
                        listaCliente->primeiro = listaCliente->primeiro->proximo;
                        free(p_auxiliar);
                    }           
                } else if(resultado->conteudo.id_cliente == listaCliente->ultimo->conteudo.id_cliente){
                    p_auxiliar = listaCliente->primeiro;
                    r_auxiliar = p_auxiliar->proximo;

                    while(r_auxiliar->proximo != NULL){
                        p_auxiliar = p_auxiliar->proximo;
                        r_auxiliar = r_auxiliar->proximo;
                    }

                    listaCliente->ultimo = p_auxiliar;
                    listaCliente->ultimo->proximo = NULL;
                    free(r_auxiliar);
                } else {
                    p_auxiliar = listaCliente->primeiro;
                    r_auxiliar = p_auxiliar->proximo;

                    while(r_auxiliar != NULL && r_auxiliar->conteudo.id_cliente != resultado->conteudo.id_cliente){
                        p_auxiliar = p_auxiliar->proximo;
                        r_auxiliar = r_auxiliar->proximo;
                    }

                    p_auxiliar->proximo = r_auxiliar->proximo;
                    free(r_auxiliar);
                }

            } else {   
                return;
            }

        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA EXCLUSAO ( S/N ) ? ");
        scanf(" %c", &novaExclusao);
    } while(novaExclusao != 'n' && novaExclusao != 'N');

}