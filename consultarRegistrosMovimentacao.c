#include "funcoes.h"

void consultarRegistrosMovimentacao(TipoListaEstoque *listaEstoque){

    ApontadorEstoque p;
    int i;
    int cont;

    if(listaEstoque->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("OS REGISTROS ESTAO VAZIOS, VOLTE AO MENU PRINCIPAL......");
        getch();
        return;
    }

    system("cls");
    telaConsultaMovimentacao();
    ordenarRegistros(listaEstoque);

    p = listaEstoque->primeiro;
    i=7;
    while(p != NULL){
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

        if(cont == 7){
            limpa_msg();
            gotoxy(2,23);
            printf("SEGUIR PARA PROXIMA PAGINA.....");
            getch();
            system("cls");
            telaConsultaMovimentacao();
            i=7;
            cont=0;
        }
    }

    limpa_msg();
    gotoxy(2,23);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.....");
    getch();
    return;

}