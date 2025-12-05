#include "funcoes.h"

void inclusaoCliente(TipoListaCliente *listaCliente){
    
    ApontadorCliente novoCadastro;
    ApontadorCliente p_auxiliar;
    char confirmacao;
    char inclusao;
    int verificacao;

    do {
        system("cls");
        tela();

        novoCadastro = (ApontadorCliente) malloc(sizeof(TipoCliente));

        telaCliente();

        do {
            limpa_msg();

            gotoxy(27,10);
            scanf("%d", &novoCadastro->conteudo.id_cliente);

            p_auxiliar = listaCliente->primeiro;
            verificacao = 0;
            while(p_auxiliar != NULL){
                if(p_auxiliar != novoCadastro && p_auxiliar->conteudo.id_cliente == novoCadastro->conteudo.id_cliente){
                    
                    gotoxy(11,9);
                    printf(" ");
                    
                    limpa_msg();
                    gotoxy(2,23);
                    printf("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO.............");
                    getch();

                    verificacao=1;

                    break;
                }
                p_auxiliar = p_auxiliar->proximo;
            }
        } while(verificacao == 1);

        do {
            gotoxy(2,23);
            limpa_msg();

            gotoxy(27,11);
            fflush(stdin);
            fgets(novoCadastro->conteudo.nome,50,stdin);
            removerLinha(novoCadastro->conteudo.nome);
            verificacao=0;
            if(strlen(novoCadastro->conteudo.nome) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO DE NOME.....");
                verificacao = 1;
                getch();
            }
        }while(verificacao != 0);

        gotoxy(27,12);
        fflush(stdin);
        fgets(novoCadastro->conteudo.cpf,15,stdin);

        gotoxy(27,13);
        fflush(stdin);
        fgets(novoCadastro->conteudo.telefone,20,stdin);

        gotoxy(27,14);
        fflush(stdin);
        fgets(novoCadastro->conteudo.email,50,stdin);

        gotoxy(27,15);
        fflush(stdin);
        fgets(novoCadastro->conteudo.endereco,60,stdin);

        gotoxy(27,16);
        fflush(stdin);
        fgets(novoCadastro->conteudo.data_cadastro,19,stdin);

        novoCadastro->conteudo.status = 1;

        gotoxy(30,19);
        printf("CONFIRMA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);

        if(confirmacao == 's' || confirmacao == 'S'){

            if(listaCliente->primeiro == NULL){
                listaCliente->primeiro = novoCadastro;
                listaCliente->ultimo = novoCadastro;
                novoCadastro->proximo = NULL;
            } else {
                listaCliente->ultimo->proximo = novoCadastro;
                listaCliente->ultimo = novoCadastro;
                novoCadastro->proximo = NULL;
            }

            gotoxy(27,17);
            printf("1");

        } else {
            return;
        }

        gotoxy(30,20);
        printf("NOVA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &inclusao);


    }while(inclusao != 'n' && inclusao != 'N');

    return;

}