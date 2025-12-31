#include "funcoes.h"

void consultaOrdemFornecedor(TipoListaFornecedor *listaFornecedor){
    
    ApontadorFornecedor p_auxiliar;
    int i;
    int contador;


    system("cls");
    telaOrdemFornecedor();
    ordenarFornecedor(listaFornecedor);

    p_auxiliar = listaFornecedor->primeiro;
    i = 7;
    contador=0;
    while(p_auxiliar != NULL){
        gotoxy(3,i);
        printf("%d", p_auxiliar->conteudo.id);

        gotoxy(9,i);
        printf("%s", p_auxiliar->conteudo.nome);

        gotoxy(20,i);
        printf("%s", p_auxiliar->conteudo.cnpj);

        gotoxy(35,i);
        printf("%s", p_auxiliar->conteudo.telefone);

        gotoxy(48,i);
        printf("%s", p_auxiliar->conteudo.email);

        gotoxy(71,i);
        printf("%d", p_auxiliar->conteudo.status);

        i++;
        contador++;
        p_auxiliar = p_auxiliar->proximo;

        if(contador == 7){
            limpa_msg();
            gotoxy(2,23);
            printf("SEGUIR PROXIMA PAGINA.....");
            system("cls");
            telaOrdemFornecedor();
            i=7;
            contador=0;

        }
    }
    limpa_msg();
    gotoxy(2,23);
    printf("VOLTE AO MENU PRINCIPAL....");
    getch();
    return;
}