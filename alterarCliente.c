#include "funcoes.h"

void alterarCliente(TipoListaCliente *lista){

    int codigo;
    int opcao;
    int codigoVerificacao;
    int alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    ApontadorCliente p_auxiliar;

    system("cls");
    tela();


    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO CLIENTE QUE DESEJA ALTERAR: ");
    scanf("%d", &codigo);

    resultado = pesquisaCliente(codigo, lista);

    if(resultado == NULL){
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU PRINCIPAL......");

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

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERAR CAMPO(1-ID,2-NOME,3-CPF,4-TEL,5-EMAIL,6-END,7-DATA,8-STATUS,0-SAIR): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:

                do {
                    codigoVerificacao = 0;
                    limpa_msg();
                    gotoxy(11,9);
                    scanf("%d", temporaria.id_cliente);

                    p_auxiliar = lista->primeiro;

                    while(p_auxiliar != NULL){
                        if(p_auxiliar->conteudo.id_cliente == temporaria.id_cliente){

                            limpa_msg();
                            gotoxy(2,23);
                            printf("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO........");
                            codigoVerificacao = 1;
                            getch();

                            break;
                        }

                        p_auxiliar = p_auxiliar->proximo;
                    }
                } while(codigoVerificacao == 1);



                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 0:

                break;
            default:

                break;
        }

    }

}