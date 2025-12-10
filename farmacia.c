#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    TipoListaMedicamento listaMedicamento;

    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    listaMedicamento.primeiro = NULL;
    listaMedicamento.ultimo = NULL;

    carregarClientes(&listaCliente);

    system("color 02");
    tela();
    menuPrincipal(&listaCliente, &listaMedicamento);

    salvarClientes(listaCliente);

}