#include "funcoes.h"

void consultaOrdemCliente(TipoListaCliente *listaCliente){
    
    ApontadorCliente p_auxiliar;
    ApontadorCliente pagina[100];
    int i;
    int contador=0;
    int paginaAtual=0;
    char opcao;
    int avancar=1;

    if(listaCliente->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("A SUA LISTA ESTA VAZIA RETORNE AO MENU PRINCIPAL......");
        getch();
        return;
    }

    ordenarCliente(listaCliente);

    pagina[0] = listaCliente->primeiro;

    while(avancar){
        system("cls");
        telaOrdemCliente();

        gotoxy(62,3);
        printf("PG %d", paginaAtual+1);

        p_auxiliar = pagina[paginaAtual];
        i=7;
        contador=0;

        while(p_auxiliar != NULL && contador < 12){

            gotoxy(3,i);
            printf("%d", p_auxiliar->conteudo.id_cliente);

            gotoxy(9,i);
            printf("%s", p_auxiliar->conteudo.nome);

            gotoxy(24,i);
            printf("%s", p_auxiliar->conteudo.cpf);

            gotoxy(42,i);
            printf("%s", p_auxiliar->conteudo.telefone);

            gotoxy(62,i);
            printf("%s", p_auxiliar->conteudo.data_cadastro);

            gotoxy(76,i);
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
                return;
                break;
            }
    }       
        
}