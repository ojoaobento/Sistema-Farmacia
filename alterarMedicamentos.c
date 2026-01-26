#include "funcoes.h"

void alterarMedicamentos(TipoListaMedicamento *listaMedicamentos, TipoListaFornecedor *listaFornecedor){
    
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
            printf("ALTERAR(1-ID-F,2-ID-M,3-NOME,4-PA,5-VAL,6-LOT,7-PRC,8-QNT,9-STA,0-SAIR): ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:               
                    alterarMedicamentoIdFornecedor(listaMedicamentos, listaFornecedor, codigo);
                    break;
                case 2:
                    alterarMedicamentoId(listaMedicamentos, &codigo);
                    break;
                case 3:
                    alterarMedicamentoNome(listaMedicamentos, codigo);
                    break;
                case 4:
                    alterarMedicamentoPA(listaMedicamentos, codigo);
                    break;
                case 5:
                    alterarMedicamentoValidade(listaMedicamentos, codigo);
                    break;
                case 6:
                    alterarMedicamentoLote(listaMedicamentos, codigo);
                    break;
                case 7:
                    alterarMedicamentoPreco(listaMedicamentos, codigo);
                    break;
                case 8:
                    alterarMedicamentoQuantidade(listaMedicamentos, codigo);
                    break;
                case 9:
                    alterarMedicamentoStatus(listaMedicamentos, codigo);
                    break;
                case 0:
                    return;
                    break;
                default:
                    system("cls");
                    tela();
                    limpa_msg();
                    gotoxy(2,23);
                    printf("OPCAO INVALIDA, TENTE NOVAMENTE......");
                    getch();
                    return;
                    break;
            }
            gotoxy(30,20);
            printf("NOVA ALTERACAO ( S/N ) ? ");
            scanf(" %c", &alteracao);
        }while(alteracao != 'n' && alteracao != 'N');
    }
}