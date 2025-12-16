#include "funcoes.h"

void exclusaoMedicamento(TipoListaMedicamento *listaMedicamento){
    
    ApontadorMedicamento resultado;
    ApontadorMedicamento p_auxiliar;
    ApontadorMedicamento r_auxiliar;
    int codigo;
    char confirmacao;
    char exclusao;

    do {


        if(listaMedicamento->primeiro == NULL){
            system("cls");
            tela();
            gotoxy(2,23);
            printf("O SEU SISTEMA ESTA VAZIO, VOLTE AO MENU PRINCIPAL.....");
            getch();
            return;
        }

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
            dadosMedicamento(listaMedicamento, resultado);

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

                        limpa_msg();
                        gotoxy(2,23);
                        printf("O SISTEMA DE CADASTRO ESTA VAZIO, VOLTE AO MENU PRINCIPAL.....");
                        getch();
                        return;

                    } else{
                        p_auxiliar = listaMedicamento->primeiro;
                        listaMedicamento->primeiro = p_auxiliar->proximo;
                        free(p_auxiliar);
                    }
                } else if(resultado->conteudo.id == listaMedicamento->ultimo->conteudo.id){
                    p_auxiliar = listaMedicamento->primeiro;
                    r_auxiliar = p_auxiliar->proximo;
                    while(p_auxiliar != NULL){
                        p_auxiliar = p_auxiliar->proximo;
                        r_auxiliar=r_auxiliar->proximo;
                    }

                    listaMedicamento->ultimo = p_auxiliar;
                    listaMedicamento->ultimo->proximo = NULL;
                    free(r_auxiliar);
                } else{
                    p_auxiliar = listaMedicamento->primeiro;
                    r_auxiliar = p_auxiliar->proximo;
                    while(r_auxiliar != NULL && r_auxiliar->conteudo.id != resultado->conteudo.id){
                        p_auxiliar = p_auxiliar->proximo;
                        r_auxiliar = r_auxiliar->proximo;
                    }
                    p_auxiliar->proximo = r_auxiliar->proximo;
                    free(r_auxiliar);
                }
            } else{
                return;
            }
        }
        gotoxy(30,20);
        printf("NOVA EXCLUSAO ( S/N ) ? ");
        scanf(" %c", &exclusao);

    }while(exclusao != 'n' && exclusao != 'N');
}