#include "funcoes.h"

void consultaOrdemMedicamento(TipoListaMedicamento *listaMedicamento){

    ApontadorMedicamento p_auxiliar;
    ApontadorMedicamento pagina[100];
    int paginaAtual=0;
    char opcao;
    int i;
    int contador=0;
    int avancar=1;

    if(listaMedicamento->primeiro == NULL){
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("O SEU CADASTRO DE MEDICAMENTO ESTA VAZIO, RETORNE AO MENU PRINCIPAL.....");
        getch();
        return;
    }

    ordenarMedicamento(listaMedicamento);
    pagina[0] = listaMedicamento->primeiro;

    while(avancar){
        system("cls");
        telaOrdemMedicamento();
        i=7;
        contador=0;
        p_auxiliar = pagina[paginaAtual];

        while(p_auxiliar != NULL && contador < 12){

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
        }

        limpa_msg();
        gotoxy(2,23);
        printf("[P] PROXIMA - [A] ANTERIOR - [S] SAIR : ");  
        scanf(" %c", &opcao);

        switch(opcao){
            case 'P':
            case 'p':
                if(p_auxiliar != NULL && paginaAtual < 99){
                    paginaAtual++;
                    pagina[paginaAtual] = p_auxiliar;
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