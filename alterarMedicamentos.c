#include "funcoes.h"

void alterarMedicamentos(TipoListaMedicamento *listaMedicamentos){
    
    int codigo;
    int opcao;
    ApontadorMedicamento resultado;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA CONSULTAR : ");
    scanf("%d", &codigo);

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);

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
        telaMedicamentos();
        dadosMedicamento(listaMedicamentos, resultado);

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERAR (1-ID,2-NOME,3-PA,4-VAL,5-LOTE,6-PRECO,7-QUANT,8-STATUS,0-SAIR): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                
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
            default:

                break;
        }

    }
}