#include "funcoes.h"

void inclusaoCliente(TipoListaCliente *lista){
    
    ApontadorCliente novoCadastro;
    ApontadorCliente p_auxiliar;
    char confirmacao;
    char inclusao;
    int verificacao;

    do {
        novoCadastro = (ApontadorCliente) malloc(sizeof(TipoCliente));

        system("cls");
        tela();

        telaCliente();

        do {
            gotoxy(11,10);
            scanf("%d", &novoCadastro->conteudo.id_cliente);

            p_auxiliar = lista->primeiro;
            verificacao = 0;
            while(p_auxiliar != NULL){
                if(p_auxiliar != novoCadastro && p_auxiliar->conteudo.id_cliente == novoCadastro->conteudo.id_cliente){
                    
                    gotoxy(11,10);
                    printf(" ");
                    
                    limpa_msg();
                    gotoxy("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO.............");
                    getch();

                    verificacao=1;

                    break;
                }
            }
        } while(verificacao == 1);

        gotoxy(31,10);
        fflush(stdin);
        fgets(novoCadastro->conteudo.nome,50,stdin);

        gotoxy(12,12);
        fflush(stdin);
        fgets(novoCadastro->conteudo.cpf,15,stdin);

        gotoxy(55,12);
        fflush(stdin);
        fgets(novoCadastro->conteudo.telefone,20,stdin);

        gotoxy(14,14);
        fflush(stdin);
        fgets(novoCadastro->conteudo.email,50,stdin);

        gotoxy(17,16);
        fflush(stdin);
        fgets(novoCadastro->conteudo.endereco,60,stdin);

        gotoxy(22,18);
        fflush(stdin);
        fgets(novoCadastro->conteudo.data_cadastro,19,stdin);

        gotoxy(53,18);
        scanf("%d", &novoCadastro->conteudo.status);


        gotoxy(30,19);
        printf("CONFIRMA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &inclusao);

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