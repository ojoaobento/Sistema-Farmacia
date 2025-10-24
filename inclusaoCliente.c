#include "funcoes.h"

void inclusaoCliente(TipoListaCliente *lista){
    
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

            gotoxy(11,9);
            scanf("%d", &novoCadastro->conteudo.id_cliente);

            p_auxiliar = lista->primeiro;
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

        gotoxy(31,9);
        fflush(stdin);
        fgets(novoCadastro->conteudo.nome,50,stdin);

        gotoxy(12,11);
        fflush(stdin);
        fgets(novoCadastro->conteudo.cpf,15,stdin);

        gotoxy(55,11);
        fflush(stdin);
        fgets(novoCadastro->conteudo.telefone,20,stdin);

        gotoxy(14,13);
        fflush(stdin);
        fgets(novoCadastro->conteudo.email,50,stdin);

        gotoxy(17,15);
        fflush(stdin);
        fgets(novoCadastro->conteudo.endereco,60,stdin);

        gotoxy(22,17);
        fflush(stdin);
        fgets(novoCadastro->conteudo.data_cadastro,19,stdin);

        gotoxy(53,17);
        scanf("%d", &novoCadastro->conteudo.status);


        gotoxy(30,19);
        printf("CONFIRMA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);

        if(confirmacao == 's' || confirmacao == 'S'){

            if(lista->primeiro == NULL){
                lista->primeiro = novoCadastro;
                lista->ultimo = novoCadastro;
                novoCadastro->proximo = NULL;
            } else {
                lista->ultimo->proximo = novoCadastro;
                lista->ultimo = novoCadastro;
                novoCadastro->proximo = NULL;
            }

        } else {
            return;
        }

        gotoxy(30,20);
        printf("NOVA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &inclusao);


    }while(inclusao != 'n' && inclusao != 'N');

    return;

}