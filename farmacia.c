#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    TipoListaMedicamento listaMedicamento;

    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    listaMedicamento.primeiro = NULL;
    listaMedicamento.ultimo = NULL;

    carregarClientes(&listaCliente);
    carregarMedicamentos(&listaMedicamento);

    system("color 02");
    tela();
    menuPrincipal(&listaCliente, &listaMedicamento);

    salvarClientes(listaCliente);
    salvarMedicamenots(listaMedicamento);

}