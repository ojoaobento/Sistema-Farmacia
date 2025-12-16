#include "funcoes.h"

void exclusaoMedicamento(TipoListaMedicamento *listaMedicamento){
    
    ApontadorMedicamento resultado;
    ApontadorMedicamento p_auxiliar;
    ApontadorMedicamento r_auxiliar;
    int codigo;
    char confirmacao;
    char exclusao;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA EXCLUIR : ");
    scanf("%d", &codigo);

    resultado = pesquisaMedicamento(listaMedicamento, codigo);

    if(resultado == NULL){
        system("cls");
        tela();

        gotoxy(2,23);
        printf("O CODIGO INSERIDO NAO EXISTE, VOLTE AO MENU PRINCIPAL......");
        getch();
        return;
    } else{
        system("cls");
        tela();
        telaMedicamentos();
        dadosCliente(listaMedicamento, resultado);

        gotoxy(30,19);
        printf("CONFIRMAR EXCLUSAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);

        if(confirmacao == 's' || confirmacao == 'S'){
            if(resultado->conteudo.id == listaMedicamento->primeiro->conteudo.id){
                if(listaMedicamento->primeiro == listaMedicamento->ultimo){
                    p_auxiliar = listaMedicamento->primeiro;
                    listaMedicamento->primeiro = NULL;
                    listaMedicamento->ultimo = NULL;
                    free(p_auxiliar);
                } else{
                    p_auxiliar = listaMedicamento->primeiro;
                    listaMedicamento->primeiro = p_auxiliar->proximo;
                    free(p_auxiliar);
                }
            } else if(resultado->conteudo.id == listaMedicamento->ultimo->conteudo.id){
                p_auxiliar = listaMedicamento->primeiro;
                r_auxiliar = p_auxiliar->proximo;
                while(p_auxiliar != NULL){
                    
                }
            }
        }
    }

}