#include "funcoes.h"

void consultaCliente(TipoListaCliente *listaCliente){
    
    int codigo;
    ApontadorCliente resultado;
    char consulta;

    do {
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO CLIENTE QUE DESEJA CONSULTAR: ");
        scanf("%d", &codigo);

        resultado = pesquisaCliente(listaCliente, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU..........");
            getch();
            return;
        } else {
            system("cls");
            tela();
            telaCliente();
            dadosCliente(listaCliente, codigo);
        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA CONSULTA ( S/N ) ? ");
        scanf(" %c", &consulta);
    }while(consulta != 'n' && consulta != 'N');
    return;
}