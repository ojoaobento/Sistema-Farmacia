#include "funcoes.h"

void consultaOrdemFornecedor(TipoListaFornecedor *listaFornecedor){
    
    ApontadorFornecedor p_auxiliar;
    ApontadorFornecedor pagina[100];
    int i;
    int contador;
    int paginaAtual=0;
    int avancar=1;
    char opcao;


    if(listaFornecedor->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("OS FORNECEDORES ESTAO VAZIOS, VOLTE AO MENU PRINCIPAL.....");
        getch();
        return;
    }

    ordenarFornecedor(listaFornecedor);

    p_auxiliar = listaFornecedor->primeiro;

    pagina[0] = listaFornecedor->primeiro;

    while(avancar){
        system("cls");
        telaOrdemFornecedor();
        i = 7;
        contador=0;
        p_auxiliar = pagina[paginaAtual];

        while(p_auxiliar != NULL && contador < 12){
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