#include "funcoes.h"


int main(){

    TipoListaCliente listaCliente;
    TipoListaMedicamento listaMedicamento;
    TipoListaFornecedor listaFornecedor;
    TipoListaMovimentacao listaMovimentacao;
    TipoListaEstoque listaEstoque;
    TipoListaRanking listaRanking;

    listaCliente.primeiro = NULL;
    listaCliente.ultimo = NULL;

    listaMedicamento.primeiro = NULL;
    listaMedicamento.ultimo = NULL;

    listaFornecedor.primeiro = NULL;
    listaFornecedor.ultimo = NULL;

    listaMovimentacao.primeiro = NULL;
    listaMovimentacao.ultimo = NULL;

    listaEstoque.primeiro = NULL;
    listaEstoque.ultimo = NULL;

    listaRanking.primeiro = NULL;
    listaRanking.ultimo = NULL;

    carregarClientes(&listaCliente);
    carregarMedicamentos(&listaMedicamento);
    carregarFornecedor(&listaFornecedor);
    carregarCompras(&listaMovimentacao);
    carregarEstoque(&listaEstoque);

    system("color 02");
    tela();
    menuPrincipal(&listaCliente, &listaMedicamento, &listaFornecedor,&listaMovimentacao, &listaEstoque, &listaRanking);

    salvarClientes(listaCliente);
    salvarMedicamentos(listaMedicamento);
    salvarFornecedor(listaFornecedor);
    salvarCompras(listaMovimentacao);
    salvarEstoque(listaEstoque);

}