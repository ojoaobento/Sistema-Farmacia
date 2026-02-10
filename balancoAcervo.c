#include "funcoes.h"

void balancoAcervo(TipoListaMedicamento *listaMedicamento, TipoListaMovimentacao *listaMovimentacao){

    ApontadorMedicamento p;
    ApontadorMedicamento pagina[100];
    ApontadorMedicamento outraPagina[100];
    ApontadorMedicamento ultimoSemVenda = NULL;;
    int paginaAtual=0;
    int segundaPagina=0;
    char alternativa;
    ApontadorMovimentacao r;
    int i;
    int cont=0;
    int totalVendido;
    int opcao;
    int todosVendido;
    int avancar=1;

    system("cls");
    telaBalancoAcervo();

    limpa_msg();
    gotoxy(2,23);
    printf("OPCAO : ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            if(listaMovimentacao->primeiro == NULL){
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("NAO EXISTE NENHUMA MOVIMENTACAO, LOGO NAO TEREMOS RELATORIOS.........");
                getch();
                return;
            }

            pagina[0] = listaMedicamento->primeiro;

            while(avancar){
                system("cls");
                telaBalancoAcervo();
                limparFiltro();

                gotoxy(62,3);
                printf("PG %d", paginaAtual+1);

                p = pagina[paginaAtual];
                i = 7;
                cont=0;
                while(p != NULL && cont < 12){

                    totalVendido=0;

                    gotoxy(3,i);
                    printf("%d", p->conteudo.id);

                    gotoxy(20,i);
                    printf("%s", p->conteudo.nome);

                    gotoxy(47,i);
                    printf("%d", p->conteudo.quantidade);

                    r = listaMovimentacao->primeiro;
                    while(r != NULL){
                        if(p->conteudo.id == r->conteudo.cd_medicamento){
                            totalVendido += r->conteudo.quantidade;
                        }
                        r = r->proximo;
                    }
                    gotoxy(71,i);
                    printf("%d", totalVendido);

                    p = p->proximo;
                    i++;
                    cont++;
                }

                limpa_msg();
                gotoxy(2,23);
                printf("[P] PROXIMA - [A] ANTERIOR - [S] SAIR : "); 
                scanf(" %c", &alternativa);

                switch(alternativa){
                    case 'P':
                    case 'p':
                        if(p != NULL && paginaAtual < 99){
                            paginaAtual++;
                            pagina[paginaAtual] = p;
                        }
                        break;
                    case 'A':
                    case 'a':
                        if(paginaAtual > 0){
                            paginaAtual--;
                        }
                        break;
                    case 'S':
                    case 's':
                        return;
                        break;
                    default:
                        limpa_msg();
                        gotoxy(2,23);
                        printf("OPCAO INVALIDA, INSIRA NOVAMENTE......");
                        getch();
                        break;
                }

            }
            break;
        case 2:
            p = listaMedicamento->primeiro;
            while(p != NULL){
                totalVendido=0;
                r = listaMovimentacao->primeiro;
                while(r != NULL){
                    if(p->conteudo.id == r->conteudo.cd_medicamento){
                        totalVendido += r->conteudo.quantidade;
                    }
                    r = r->proximo;
                }

                if(totalVendido == 0){
                    break;
                }

                p = p->proximo;
            }

            if(p == NULL){
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("TODOS MEDICAMENTOS FORAM VENDIDOS, VOLTE AO MENU PRINCIPAL......");
                getch();
                return;
            } else{
                outraPagina[0] = listaMedicamento->primeiro;

                while(avancar){
                    system("cls");
                    telaBalancoAcervo();
                    limparFiltro();

                    gotoxy(62,3);
                    printf("PG %d", segundaPagina+1);

                    p = outraPagina[segundaPagina];
                    i=7;
                    cont=0;
                    while(p != NULL && cont < 12){
                        r = listaMovimentacao->primeiro;
                        totalVendido = 0;

                        while(r != NULL){
                            if(p->conteudo.id == r->conteudo.cd_medicamento){
                                totalVendido += r->conteudo.quantidade;
                            }
                            r = r->proximo;
                        }
                        
                        if(totalVendido == 0){

                            ultimoSemVenda = p;
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
                        }
                        p = p->proximo;
                    }

                    limpa_msg();
                    gotoxy(2,23);
                    printf("[P] PROXIMA - [A] ANTERIOR - [S] SAIR : ");  
                    scanf(" %c", &alternativa);

                    switch(alternativa){
                        case 'P':
                        case 'p':
                            if(p != NULL && segundaPagina < 99 && ultimoSemVenda != NULL){
                                segundaPagina++;
                                outraPagina[segundaPagina] = ultimoSemVenda->proximo;
                            }
                            break;
                        case 'A':
                        case 'a':
                            if(segundaPagina > 0){
                                segundaPagina--;
                            }
                            break;
                        case 'S':
                        case 's':
                            return;
                            break;
                        default:
                            limpa_msg();
                            gotoxy(2,23);
                            printf("OPCAO INVALIDA, INSIRA NOVAMENTE......");
                            getch();
                            break;
                    }
                }
            }
            break;
        case 0:
            return;
            break;
        default:
            limpa_msg();
            gotoxy(2,23);
            printf("OPCAO INVALIDA, INSIRA NOVAMENTE......");
            getch();
            break;
    }
}