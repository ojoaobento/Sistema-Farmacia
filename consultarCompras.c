#include "funcoes.h"


void consultarCompras(TipoListaMovimentacao *listaMovimentacao){

    ApontadorMovimentacao p;
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

    system("cls");
    telaOrdemCompras();
    ordenarCompras(listaMovimentacao);

    p = listaMovimentacao->primeiro;
    i=7;
    while(p != NULL){
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

        if(cont == 12){   
            limpa_msg();
            gotoxy(2,23);
            printf("SIGA PARA PROXIMA PAGINA.....");
            getch();
            system("cls");
            telaOrdemCompras();
            i=7;
            cont=0;
        }
    }

    limpa_msg();
    gotoxy(2,23);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL....");
    getch();
    return;

}