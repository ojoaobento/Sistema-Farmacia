#include "funcoes.h"

void exclusaoCliente(TipoListaCliente *lista){

    ApontadorCliente resultado;
    ApontadorCliente p_auxiliar;
    ApontadorCliente r_auxiliar;
    int codigo;
    char exclusao;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO CADASTRO QUE DESEJA EXCLUIR: ");
    scanf("%d", &codigo);


    resultado = pesquisaCliente(codigo, lista);

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

        gotoxy(11,9);
        printf("%d", resultado->conteudo.id_cliente);

        gotoxy(31,9);
        printf("%s", resultado->conteudo.nome);

        gotoxy(12,11);
        printf("%s", resultado->conteudo.cpf);

        gotoxy(55,11);
        printf("%s", resultado->conteudo.telefone);

        gotoxy(14,13);
        printf("%s", resultado->conteudo.email);

        gotoxy(17,15);
        printf("%s", resultado->conteudo.endereco);

        gotoxy(22,17);
        printf("%s", resultado->conteudo.data_cadastro);

        gotoxy(53,17);
        printf("%d", resultado->conteudo.status);


        gotoxy(30,19);
        printf("CONFIRMA EXCLUSAO ( S/N ) ?");
        scanf(" %c", &exclusao);

        if(exclusao == 's' || exclusao == 'S'){

            if(resultado->conteudo.id_cliente == lista->primeiro->conteudo.id_cliente){
                if(lista->primeiro == lista->ultimo){ 
                    p_auxiliar = lista->primeiro;

                    lista->primeiro = NULL;
                    lista->ultimo = NULL;
                    free(p_auxiliar);
                }else {
                    p_auxiliar = lista->primeiro;
                    lista->primeiro = lista->primeiro->proximo;
                    free(p_auxiliar);
                }           
            } else if(resultado->conteudo.id_cliente == lista->ultimo){
                p_auxiliar = lista->primeiro;

            }




        } else {   
            return;
        }

    }

}