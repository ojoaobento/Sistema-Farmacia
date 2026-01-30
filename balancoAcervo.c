#include "funcoes.h"

void balancoAcervo(TipoListaMedicamento *listaMedicamento, TipoListaMovimentacao *listaMovimentacao){

    ApontadorMedicamento p;
    ApontadorMovimentacao r;
    int i;
    int cont=0;
    int totalVendido;
    int opcao;

    system("cls");
    telaBalancoAcervo();


    limpa_msg();
    gotoxy(2,23);
    printf("OPCAO : ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:

            limparFiltro();
            if(listaMovimentacao->primeiro == NULL){
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("NAO EXISTE NENHUMA MOVIMENTACAO, LOGO NAO TEREMOS RELATORIOS.........");
                getch();
                return;
            }

            p = listaMedicamento->primeiro;
            i = 7;
            while(p != NULL){

                totalVendido=0;

                gotoxy(3,i);
                printf("%d", p->conteudo.id);

                gotoxy(20,i);
                printf("%s", p->conteudo.nome);

                gotoxy(45,i);
                printf("%d", p->conteudo.quantidade);

                r = listaMovimentacao->primeiro;

                while(r != NULL){
                    if(p->conteudo.id == r->conteudo.cd_medicamento){
                        totalVendido += r->conteudo.quantidade;
                    }
                    r = r->proximo;
                }

                gotoxy(68,i);
                printf("%d", totalVendido);

                p = p->proximo;
                i++;
                cont++;

                if(cont == 7){
                    limpa_msg();
                    gotoxy(2,23);
                    printf("SEGUIR PARA PROXIMA PAGINA......");
                    getch();
                    system("cls");
                    telaBalancoAcervo();
                    i = 7;
                    cont=0;
                }

            }
            break;
        case 2:

            limparFiltro();
            p = listaMedicamento->primeiro;
            i=7;
            cont=0;
            while(p != NULL){
                r = listaMovimentacao->primeiro;
                totalVendido = 0;

                while(r != NULL){
                    if(p->conteudo.id == r->conteudo.cd_medicamento){
                        totalVendido += r->conteudo.quantidade;
                    }
                    r = r->proximo;
                }

                if(totalVendido == 0){
                    gotoxy(3,i);
                    printf("%d", p->conteudo.id);

                    gotoxy(20,i);
                    printf("%s", p->conteudo.nome);

                    gotoxy(45,i);
                    printf("%d", p->conteudo.quantidade);  

                    gotoxy(68,i);
                    printf("%d", totalVendido);

                    i++;
                    cont++;

                    if(cont == 7){
                        limpa_msg();
                        gotoxy(2,23);
                        printf("SEGUIR PARA PROXIMA PAGINA.....");
                        getch();
                        system("cls");
                        telaBalancoAcervo();
                        i=7;
                        cont=0;
                    }
                }
                p = p->proximo;
            }

            break;
        case 0:
            return;
            break;
        default:

            break;
    }

    limpa_msg();
    gotoxy(2,23);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL....");
    getch();
    return;


}