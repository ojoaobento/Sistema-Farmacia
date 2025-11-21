#include "funcoes.h"

void alterarCliente(TipoListaCliente *listaCliente){

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

    resultado = pesquisaCliente(listaCliente, codigo);

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
        dadosCliente(listaCliente, codigo);

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERAR CAMPO(1-ID,2-NOM,3-CPF,4-TEL,5-EMAIL,6-END,7-DATA,8-STA,0-SAIR): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                alterarClienteID(listaCliente, codigo);
                break;
            case 2:
                alterarClienteNome(listaCliente, codigo);
                break;
            case 3:
                alterarClienteCPF(listaCliente, codigo);
                break;
            case 4: 
                alterarClienteTelefone(listaCliente, codigo);
                break;
            case 5:
                alterarClienteEmail(listaCliente, codigo);
                break;
            case 6:
                alterarClienteEnd(listaCliente, codigo);
                break;
            case 7:
                alterarClienteData(listaCliente, codigo);
                break;
            case 8:
                alterarClienteStatus(listaCliente, codigo);
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