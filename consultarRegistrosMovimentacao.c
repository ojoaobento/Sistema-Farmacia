#include "funcoes.h"

void consultarRegistrosMovimentacao(TipoListaEstoque *listaEstoque){

    ApontadorEstoque p;
    ApontadorEstoque pagina[100];
    int paginaAtual=0;
    char opcao;
    int i;
    int cont;
    int avancar=1;

    if(listaEstoque->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("OS REGISTROS ESTAO VAZIOS, VOLTE AO MENU PRINCIPAL......");
        getch();
        return;
    }

    ordenarRegistros(listaEstoque);
    pagina[0] = listaEstoque->primeiro;

    while(avancar){
        system("cls");
        telaConsultaMovimentacao();

        p = pagina[paginaAtual];
        i=7;
        cont=0;
        while(p != NULL && cont < 10){
            gotoxy(3,i);
            printf("%d", p->conteudo.id_medicamento);

            gotoxy(20,i);
            printf("%d", p->conteudo.tipo_reposicao);

            gotoxy(52,i);
            printf("%d", p->conteudo.quantidade);

            gotoxy(68,i);
            printf("%s", p->conteudo.data);

            p = p->proximo;
            i++;
            cont++;
        }

        limpa_msg();
        gotoxy(2,23);
        printf("[P] PROXIMA - [A] ANTERIOR - [S] SAIR : ");  
        scanf(" %c", &opcao);

        switch(opcao){
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
}