#include "funcoes.h"

void inativarCliente(TipoListaCliente *listaCliente){
    
    ApontadorCliente resultado;
    int codigo;
    char confirmacao;
    char novaInativacao;

    do {
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO CLIENTE QUE DESEJA INATIVAR: ");
        scanf("%d", &codigo);

        resultado = pesquisaCliente(listaCliente, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("ESSE CODIGO NAO EXISTE, RETORNE AO MENU PRINCIPAL...");
            getch();
            return;
        } else {
            if(resultado->conteudo.status == 0){
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("O CODIGO INSERIDO JA ESTA INATIVADO, RETORNE AO MENU PRINCIPAL...");
                getch();
                return;
            }
            system("cls");
            tela();
            telaCliente();
            dadosCliente(listaCliente, codigo);

            limpa_msg();
            gotoxy(2,23);
            printf("CONFIRMAR INATIVACAO ( S/N ) ? ");
            scanf(" %c", &confirmacao);

            if(confirmacao == 's' || confirmacao == 'S'){
                resultado->conteudo.status = 0;
            } else {
                return;
            }
        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA INATIVACAO ( S/N ) ? ");
        scanf(" %c", &novaInativacao);
    }while(novaInativacao != 'n' && novaInativacao != 'N');
}