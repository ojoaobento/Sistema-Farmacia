#include "funcoes.h"

void consultaOrdemCliente(TipoListaCliente *listaCliente){
    
    ApontadorCliente p_auxiliar;
    int i;
    int contador=0;

    system("cls");
    tela();
    telaOrdemCliente();

    ordernarCliente(listaCliente);

    p_auxiliar = listaCliente->primeiro;

    i=7;
    while(p_auxiliar != NULL){

        gotoxy(3,i);
        printf("%d", p_auxiliar->conteudo.id_cliente);

        gotoxy(9,i);
        printf("%s", p_auxiliar->conteudo.nome);

        gotoxy(20,i);
        printf("%s", p_auxiliar->conteudo.cpf);

        gotoxy(30,i);
        printf("%s", p_auxiliar->conteudo.telefone);

        gotoxy(38,i);
        printf("%s", p_auxiliar->conteudo.email);

        gotoxy(53,i);
        printf("%s", p_auxiliar->conteudo.endereco);

        gotoxy(63,i);
        printf("%s", p_auxiliar->conteudo.data_cadastro);

        gotoxy(72,i);
        printf("%s", p_auxiliar->conteudo.status);

        i++;
        contador++;
        p_auxiliar = p_auxiliar->proximo;

        if(contador == 7){

            limpa_msg();
            gotoxy(2,23);
            printf("SEGUIR PARA PROXIMA PAGINA....");
            getch();
            system("cls");
            tela();
            telaOrdemCliente();
            i=7;
            contador=0;
        }

        if(contador > 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.....");
            getch();
            return;            
        }
    }

}