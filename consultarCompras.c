#include "funcoes.h"


void consultarCompras(TipoListaMovimentacao *listaMovimentacao){

    ApontadorMovimentacao p;
    ApontadorMovimentacao pagina[100];
    int paginaAtual=0;
    int avancar=1;
    char opcao;
    int i;
    int cont;

    if(listaMovimentacao->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("AS COMPRAS ESTAO VAZIAS, VOLTE AO MENU PRINCIPAL......");
        getch();
        return;
    }
    ordenarCompras(listaMovimentacao);

    pagina[0] = listaMovimentacao->primeiro;

    while(avancar){

        system("cls");
        telaOrdemCompras();
        
        gotoxy(62,3);
        printf("PG %d", paginaAtual+1);

        p = pagina[paginaAtual];

        i=7;
        cont = 0;
        while(p != NULL && cont < 12){
            gotoxy(3,i);
            printf("%d", p->conteudo.cd_cliente);

            gotoxy(17,i);
            printf("%d", p->conteudo.cd_medicamento);

            gotoxy(30,i);
            printf("%d", p->conteudo.quantidade);

            gotoxy(42,i);
            printf("R$ %.2f", p->conteudo.valor);

            gotoxy(57,i);
            printf("R$ %.2f", p->conteudo.valor_total);

            gotoxy(72,i);
            printf("%s", p->conteudo.dt_compra);

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