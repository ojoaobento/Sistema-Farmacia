#include "funcoes.h"

void alterarFornecedor(TipoListaFornecedor *listaFornecedor){

    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    ApontadorFornecedor p_auxiliar;
    int codigo;
    int opcao;
    int verificacao;
    char confirmacao;
    char alteracao;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO FORNECEDOR QUE DESEJA ALTERAR : ");
    scanf("%d", &codigo);

    resultado = pesquisaFornecedor(&listaFornecedor, codigo);

    if(resultado == NULL){
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("O CODIGO INSERIDO NAO EXISTE, VOLTE AO MENU PRINCIPAL.....");
        getch();
        return;
    } else{

        do {
            system("cls");
            tela();
            telaFornecedor();
            dadosFornecedor(listaFornecedor, codigo);

            limpa_msg();
            gotoxy(2,23);
            printf("ALTERAR CAMPO(1-ID,2-NOME,3-CNPJ,4-TEL,5-EMAIL,6-STATUS,0-SAIR): ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                    alterarFornecedorId(listaFornecedor, &codigo);
                    break;
                case 2:
                    alterarFornecedorNome(listaFornecedor, codigo);
                    break;
                case 3:
                    alterarFornecedorCnpj(listaFornecedor, codigo);
                    break;
                case 4:
                    alterarFornecedorTelefone(listaFornecedor, codigo);
                    break;
                case 5:
                    alterarFornecedorEmail(listaFornecedor, codigo);
                    break;
                case 6:
                    alterarFornecedorStatus(listaFornecedor, codigo);
                    break;
                case 0:
                    return;
                    break;
                default:
                    system("cls");
                    tela();
                    limpa_msg();
                    gotoxy(2,23);
                    printf("OPCAO INVALIDA, VOLTE AO MENU PRINCIPAL.....");
                    getch();
                    return;
                    break;
            }

            limpa_msg();
            gotoxy(2,23);
            printf("NOVA ALTERACAO ( S/N ) ? ");
            scanf(" %c", &alteracao);

        }while(alteracao != 'n' && alteracao != 'N');        
    }

}