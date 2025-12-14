#include "funcoes.h"

void consultaOrdemMedicamento(TipoListaMedicamento *listaMedicamento){

    ApontadorMedicamento p_auxiliar;
    int i;
    int contador;

    system("cls");

    telaOrdemMedicamento();
    ordenarMedicamento(listaMedicamento);

    i=7;
    p_auxiliar = listaMedicamento->primeiro;
    while(p_auxiliar != NULL){
        gotoxy(3,i);
        printf("%d", p_auxiliar->conteudo.id);

        gotoxy(9,i);
        printf("%s", p_auxiliar->conteudo.nome);

        gotoxy(20,i);
        printf("%s", p_auxiliar->conteudo.principio_ativo);

        gotoxy(30,i);
        printf("%s", p_auxiliar->conteudo.validade);

        gotoxy(38,i);
        printf("%s", p_auxiliar->conteudo.lote);

        gotoxy(53,i);
        printf("%.2f", p_auxiliar->conteudo.preco);

        gotoxy(63,i);
        printf("%d", p_auxiliar->conteudo.quantidade);

        gotoxy(72,i);
        printf("%d", p_auxiliar->conteudo.status);

        contador++;
        i++;
        p_auxiliar = p_auxiliar->proximo;

        if(contador == 7){
            limpa_msg();
            gotoxy(2,23);
            printf("SEGUIR PARA PROXIMA PAGINA.....");
            getch();

            system("cls");
            telaOrdemMedicamento();
            i=7;
            contador=0;
        }
    }

    limpa_msg();
    gotoxy(2,23);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.....");
    getch();
    return;
}