#include "funcoes.h"

void alterarCliente(TipoListaCliente *lista){

    int codigo;
    int opcao;
    ApontadorCliente resultado;

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
        printf("ALTERAR CAMPO(1-NOME,2-CPF,3-TEL,4-EMAIL,5-END,6-DATA,7-STATUS): ");
        scanf("%d", &opcao);


    }




}