#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    carregarClientes(&listaCliente);

    system("color 02");
    tela();
    menuPrincipal(&listaCliente);

    salvarClientes(listaCliente);

}