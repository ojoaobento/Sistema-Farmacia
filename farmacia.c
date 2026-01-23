#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    TipoListaMedicamento listaMedicamento;
    TipoListaFornecedor listaFornecedor;
    TipoListaMovimentacao listaMovimentacao;

    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    listaMedicamento.primeiro = NULL;
    listaMedicamento.ultimo = NULL;

    listaFornecedor.primeiro = NULL;
    listaFornecedor.ultimo = NULL;

    listaMovimentacao.primeiro = NULL;
    listaMovimentacao.ultimo = NULL;

    carregarClientes(&listaCliente);
    carregarMedicamentos(&listaMedicamento);
    carregarFornecedor(&listaFornecedor);
    carregarCompras(&listaMovimentacao);

    system("color 02");
    tela();
    menuPrincipal(&listaCliente, &listaMedicamento, &listaFornecedor,&listaMovimentacao);

    salvarClientes(listaCliente);
    salvarMedicamentos(listaMedicamento);
    salvarFornecedor(listaFornecedor);
    salvarCompras(listaMovimentacao);

}