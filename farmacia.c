#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    system("color 02");
    tela();
    menuPrincipal(&listaCliente);

}