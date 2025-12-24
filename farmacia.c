#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    TipoListaMedicamento listaMedicamento;
    TipoListaFornecedor listaFornecedor;

    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    listaMedicamento.primeiro = NULL;
    listaMedicamento.ultimo = NULL;

    listaFornecedor.primeiro = NULL;
    listaFornecedor.ultimo = NULL;

    carregarClientes(&listaCliente);
    carregarMedicamentos(&listaMedicamento);

    system("color 02");
    tela();
    menuPrincipal(&listaCliente, &listaMedicamento, &listaFornecedor);

    salvarClientes(listaCliente);
    salvarMedicamentos(listaMedicamento);

}