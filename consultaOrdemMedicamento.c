#include "funcoes.h"

void consultaOrdemMedicamento(TipoListaMedicamento *listaMedicamento){

    ApontadorMedicamento p_auxiliar;
    int i;
    int contador=0;


    if(listaMedicamento->primeiro == NULL){
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("O SEU CADASTRO DE MEDICAMENTO ESTA VAZIO, RETORNE AO MENU PRINCIPAL.....");
        getch();
        return;
    }

    system("cls");

    telaOrdemMedicamento();
    ordenarMedicamento(listaMedicamento);

    i=7;
    p_auxiliar = listaMedicamento->primeiro;
    while(p_auxiliar != NULL){

        gotoxy(3,i);
        printf("%d", p_auxiliar->conteudo.id_fornecedor);

        gotoxy(8,i);
        printf("%d", p_auxiliar->conteudo.id);

        gotoxy(15,i);
        printf("%s", p_auxiliar->conteudo.nome);

        gotoxy(23,i);
        printf("%s", p_auxiliar->conteudo.principio_ativo);

        gotoxy(32,i);
        printf("%s", p_auxiliar->conteudo.validade);

        gotoxy(43,i);
        printf("%s", p_auxiliar->conteudo.lote);

        gotoxy(53,i);
        printf("%.2f", p_auxiliar->conteudo.preco);

        gotoxy(64,i);
        printf("%d", p_auxiliar->conteudo.quantidade);

        gotoxy(75,i);
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