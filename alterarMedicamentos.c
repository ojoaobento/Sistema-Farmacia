#include "funcoes.h"

void alterarMedicamentos(TipoListaMedicamento *listaMedicamentos){
    
    int codigo;
    int opcao;
    int verificacao;
    ApontadorMedicamento resultado;
    ApontadorMedicamento p_auxiliar;
    reg_medicamentos temporaria;
    char confirmacao;
    char alteracao;

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

        do{        
            system("cls");
            tela();
            telaMedicamentos();
            dadosMedicamento(listaMedicamentos, resultado);

            limpa_msg();
            gotoxy(2,23);
            printf("ALTERAR(1-ID,2-NOME,3-PA,4-VAL,5-LOTE,6-PRECO,7-QUANT,8-STATUS,0-SAIR): ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:               
                    
                    break;
                case 2:
                    alterarMedicamentoNome(listaMedicamentos, codigo);
                    break;
                case 3:
                    alterarMedicamentoPA(listaMedicamentos, codigo);
                    break;
                case 4:
                    alterarMedicamentoValidade(listaMedicamentos, codigo);
                    break;
                case 5:
                    alterarMedicamentoLote(listaMedicamentos, codigo);
                    break;
                case 6:
                    alterarMedicamentoPreco(listaMedicamentos, codigo);
                    break;
                case 7:
                    alterarMedicamentoQuantidade(listaMedicamentos, codigo);
                    break;
                case 8:
                    alterarMedicamentoStatus(listaMedicamentos, codigo);
                    break;
                case 0:
                    return;
                    break;
                default:
                    limpa_msg();
                    gotoxy(2,23);
                    printf("OPCAO INVALIDA, TENTE NOVAMENTE......");
                    getch();
                    break;
            }
            gotoxy(30,20);
            printf("NOVA ALTERACAO ( S/N ) ? ");
            scanf(" %c", &alteracao);
        }while(alteracao != 'n' && alteracao != 'N');
    }
}