#include "funcoes.h"

void alterarCliente(TipoListaCliente *lista){

    int codigo;
    int opcao;
    int codigoVerificacao;
    char alteracao;
    char novaAlteracao;
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

        do {
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
        printf("ALTERAR CAMPO(1-ID,2-NOM,3-CPF,4-TEL,5-EMAIL,6-END,7-DATA,8-STA,0-SAIR): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:

                do {
                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO");

                    gotoxy(11,9);
                    printf(" ");

                    gotoxy(11,9);
                    scanf("%d", &temporaria.id_cliente);

                    p_auxiliar = lista->primeiro;
                    codigoVerificacao = 0;
                    while(p_auxiliar != NULL){
                        if(p_auxiliar != resultado && p_auxiliar->conteudo.id_cliente == temporaria.id_cliente){

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

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO (S/N) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    resultado->conteudo.id_cliente = temporaria.id_cliente;
                } else {
                    return;
                }

                break;
            case 2:

                limpa_msg();
                gotoxy(2,23);
                printf("ALTERANDO CAMPO");

                gotoxy(31,9);
                printf("                                                            ");

                gotoxy(31,9);
                fflush(stdin);
                fgets(temporaria.nome,50,stdin);

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO (S/N) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    strcpy(resultado->conteudo.nome, temporaria.nome);
                } else {
                    return;
                }

                break;
            case 3:

                limpa_msg();
                gotoxy(2,23);
                printf("ALTERANDO CAMPO");

                gotoxy(12,11);
                printf("               ");


                gotoxy(12,11);
                fflush(stdin);
                fgets(temporaria.cpf,15,stdin);

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO (S/N) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    strcpy(resultado->conteudo.cpf, temporaria.cpf);
                } else {
                    return;
                }


                break;
            case 4:

                limpa_msg();
                gotoxy(2,23);
                printf("ALTERANDO CAMPO");

                gotoxy(55,11);
                printf("                    ");

                gotoxy(55,11);
                fflush(stdin);
                fgets(temporaria.telefone,20,stdin);

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO (S/N) ? ");
                scanf(" %c", &alteracao);


                if(alteracao == 's' || alteracao == 'S'){
                    strcpy(resultado->conteudo.telefone, temporaria.telefone);
                } else {
                    return;
                }              

                break;
            case 5:

                limpa_msg();
                gotoxy(2,23);
                printf("ALTERANDO CAMPO");

                gotoxy(14,13);
                printf("                                                            ");

                gotoxy(14,13);
                fflush(stdin);
                fgets(temporaria.email,50,stdin);

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO (S/N) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    strcpy(resultado->conteudo.email, temporaria.email);
                } else {
                    return;
                }

                break;
            case 6:

                limpa_msg();
                gotoxy(2,23);
                printf("ALTERANDO CAMPO");

                gotoxy(17,15);
                printf("                                                                      ");

                gotoxy(17,15);
                fflush(stdin);
                fgets(temporaria.endereco,60,stdin);

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO ( S/N ) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    strcpy(resultado->conteudo.endereco,temporaria.endereco);
                } else {
                    return;
                }

                break;
            case 7:

                limpa_msg();
                gotoxy(2,23);
                printf("ALTERANDO CAMPO");

                gotoxy(22,17);
                printf("                   ");               

                gotoxy(22,17);
                fflush(stdin);
                fgets(temporaria.data_cadastro,19,stdin);


                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO ( S/N ) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    strcpy(resultado->conteudo.data_cadastro,temporaria.data_cadastro);
                } else {
                    return;
                }

                break;
            case 8:
                
                limpa_msg();
                gotoxy(2,23);

                gotoxy(53,17);
                printf(" ");

                gotoxy(53,17);
                scanf("%d", &temporaria.status);

                gotoxy(30,19);
                printf("CONFIRMA ALTERACAO ( S/N ) ? ");
                scanf(" %c", &alteracao);

                if(alteracao == 's' || alteracao == 'S'){
                    resultado->conteudo.status = temporaria.status;
                } else {
                    return;
                }

                break;
            case 0:
                return;
                break;
            default:
                system("cls");

                limpa_msg();
                gotoxy(2,23);
                printf("OPCAO INVALIDA, RETORNE AO MENU PRINCIPAL.....");
                getch();

                return;
                break;
        }

        gotoxy(30,20);
        printf("NOVA ALTERACAO ( S/N ) ? ");
        scanf(" %c", &novaAlteracao);

        }while(novaAlteracao != 'n' && novaAlteracao != 'N');
    }
    return;
}