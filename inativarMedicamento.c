#include "funcoes.h"

void inativarMedicamento(TipoListaMedicamento *listaMedicamento){
    
    ApontadorMedicamento resultado;
    int codigo;
    char confirmacao;
    char inativacao;


    do {

        if(listaMedicamento->primeiro == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("O CADASTRO DE MEDICAMENTO ESTA VAZIO, VOLTE AO MENU PRINCIPAL.....");
            getch();
            return;
        }


        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA INATIVAR : ");
        scanf("%d", &codigo);

        resultado = pesquisaMedicamento(listaMedicamento, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU PRINCIPAL.....");
            getch();
            return;
        } else{

            if(resultado->conteudo.status == 0){
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("ESSE CODIGO JA ESTA INATIVADO, RETORNE AO MENU PRINCIPAL.....");
                getch();
                return;
            }


            system("cls");
            tela();
            telaMedicamentos();
            dadosMedicamento(listaMedicamento, resultado);

            gotoxy(30,19);
            printf("CONFIRMAR INATIVACAO ( S/N ) ? ");
            scanf(" %c", &confirmacao);

            if(confirmacao == 's' || confirmacao == 'S'){
                resultado->conteudo.status = 0;

                gotoxy(30,17);
                printf("0");
            } else{
                return;
            }
        }

        gotoxy(30,20);
        printf("NOVA INATIVACAO ( S/N ) ? ");
        scanf(" %c", &inativacao);

    }while(inativacao != 'n' && inativacao != 'N');
}