#include "funcoes.h"

void balancoMovimentacao(TipoListaCliente *listaCliente,TipoListaMedicamento *listaMedicamento, TipoListaMovimentacao *listaMovimentacao, TipoListaRanking *listaRanking){

    ApontadorCliente r;
    ApontadorMedicamento p;
    ApontadorMovimentacao t;
    ApontadorRanking novo;
    ApontadorRanking h;
    int contC=0;
    int contM=0;
    int contV=0;
    int contSV=0;
    int i;
    int cont=0;
    int verificacao;
    int quantidade_vendida;
    int paginaAtual=0;
    char alternativa;

    do {
        if(paginaAtual == 0){
            system("cls");
            telaBalancoMovimentacao();

            contC = 0;
            contM = 0;
            contV = 0;
            contSV = 0;

            r = listaCliente->primeiro;
            p = listaMedicamento->primeiro;

            paginaAtual=0;

            while(r != NULL){
                contC++;
                r = r->proximo;
            }

            while(p != NULL){
                contM++;
                p = p->proximo;
            }

            p = listaMedicamento->primeiro;

            while(p != NULL){
                t = listaMovimentacao->primeiro;
                verificacao=0;
                while(t != NULL){
                    contV += t->conteudo.quantidade;
                    if(t->conteudo.cd_medicamento == p->conteudo.id){
                        verificacao = 1;
                    }
                    t = t->proximo;
                }
                if(verificacao == 0){
                    contSV++;
                }
                p = p->proximo;
            }

            gotoxy(42,11);
            printf("%d", contC);

            gotoxy(42,12);
            printf("%d", contM);

            gotoxy(42,13);
            printf("%d", contV);

            gotoxy(42,14);
            printf("%d", contSV);
        }else if (paginaAtual == 1){
            system("cls");
            telaRanking();
            paginaAtual=1;
            p = listaMedicamento->primeiro;
            while(p != NULL){
                t = listaMovimentacao->primeiro;
                quantidade_vendida=0;

                while(t != NULL){
                    if(t->conteudo.cd_medicamento == p->conteudo.id){
                        quantidade_vendida += t->conteudo.quantidade;
                    }
                    t = t->proximo;
                }

                if(quantidade_vendida > 0){
                    novo = (ApontadorRanking) malloc(sizeof(TipoRanking));
                    novo->conteudo.id = p->conteudo.id;
                    strcpy(novo->conteudo.nome_medicamento, p->conteudo.nome);
                    novo->conteudo.quantidade_vendida = quantidade_vendida;

                    if(listaRanking->primeiro == NULL){
                        listaRanking->primeiro = novo;
                        listaRanking->ultimo = novo;
                        listaRanking->ultimo->proximo = NULL;
                    }else{
                        listaRanking->ultimo->proximo = novo;
                        listaRanking->ultimo = novo;
                        listaRanking->ultimo->proximo = NULL;
                    }
                }

                p = p->proximo;
            }

            ordenarRanking(listaRanking);

            
            i=11;
            h = listaRanking->primeiro;
            cont=0;
            while(h != NULL && cont<=10){

                gotoxy(3,i);
                printf("%d", h->conteudo.id);

                gotoxy(32,i);
                printf("%s", h->conteudo.nome_medicamento);

                gotoxy(67,i);
                printf("%d", h->conteudo.quantidade_vendida);

                cont++;
                i++;
                h = h->proximo;
            }

            esvaziarRanking(listaRanking);
        }

        limpa_msg();
        gotoxy(2,23);
        printf("[P] PROXIMA - [A] ANTERIOR - [S] SAIR : ");
        scanf(" %c", &alternativa);

        switch(alternativa){
            case 'P':
            case 'p':
                paginaAtual++;
                if(paginaAtual > 1){
                    paginaAtual--;
                }
                break;
            case 'A':
            case 'a':
                paginaAtual--;
                if(paginaAtual < 0){
                    paginaAtual++;
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


    }while(alternativa != 's' && alternativa != 'S');
}