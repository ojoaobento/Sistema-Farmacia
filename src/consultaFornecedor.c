#include "funcoes.h"

void consultaFornecedor(TipoListaFornecedor *listaFornecedor){
    
    int codigo;
    ApontadorFornecedor resultado;
    char consulta;

    do {

        if(listaFornecedor->primeiro == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("OS FORNECEDORES ESTAO VAZIOS, VOLTE AO MENU PRINCIPAL.....");
            getch();
            return;
        }

        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO FORNECEDOR QUE DESEJA CONSULTAR: ");
        scanf("%d", &codigo);

        resultado = pesquisaFornecedor(listaFornecedor, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, VOLTE AO MENU PRINCIPAL....");
            getch();
            return;
        }else{
            system("cls");
            tela();
            telaFornecedor();
            dadosFornecedor(listaFornecedor, codigo);
        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA CONSULTA ( S/N ) ? ");
        scanf(" %c", &consulta);

    }while(consulta != 'n' && consulta != 'N');
}