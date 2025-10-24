#include "funcoes.h"

void inclusaoCliente(TipoListaCliente *lista){
    
    ApontadorCliente novoCadastro;

    novoCadastro = (ApontadorCliente) malloc(sizeof(TipoCliente));



    
    system("cls");
    tela();

    telaCliente();

    getch();



}