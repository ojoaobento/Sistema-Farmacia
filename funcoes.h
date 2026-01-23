#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h> 

typedef struct{
    int id_cliente;
    char nome[50];
    char cpf[15];
    char telefone[20];
    char email[50];
    char endereco[60];
    char data_cadastro[19];
    int status;
}reg_clientes;

typedef struct TipoCliente *ApontadorCliente;

typedef struct TipoCliente{
    ApontadorCliente proximo;
    reg_clientes conteudo;
}TipoCliente;

typedef struct{
    ApontadorCliente primeiro;
    ApontadorCliente ultimo;
}TipoListaCliente;

typedef struct{
    int id;
    int id_fornecedor;
    char nome[50];
    char principio_ativo[50];
    char validade[11];
    char lote[20];
    float preco;
    int quantidade;
    int status;
}reg_medicamentos;

typedef struct TipoMedicamento *ApontadorMedicamento;

typedef struct TipoMedicamento{
    reg_medicamentos conteudo;
    ApontadorMedicamento proximo;
}TipoMedicamento;

typedef struct{
    ApontadorMedicamento primeiro;
    ApontadorMedicamento ultimo;
}TipoListaMedicamento;


typedef struct{
    int id;
    char nome[50];
    char cnpj[15];
    char telefone[20];
    char email[50];
    int status;
}reg_fornecedor;

typedef struct TipoFornecedor *ApontadorFornecedor;

typedef struct TipoFornecedor{
    ApontadorFornecedor proximo;
    ApontadorFornecedor anterior;
    reg_fornecedor conteudo;
}TipoFornecedor;

typedef struct{
    ApontadorFornecedor primeiro;
    ApontadorFornecedor ultimo;
}TipoListaFornecedor;

typedef struct{
    int cd_cliente;
    int cd_medicamento;
    int quantidade;
    float valor;
    float valor_total;
    char dt_compra[11];
}reg_movimentacoes;

typedef struct TipoMovimentacao *ApontadorMovimentacao;

typedef struct TipoMovimentacao{
    reg_movimentacoes conteudo;
    ApontadorMovimentacao proximo;
}TipoMovimentacao;

typedef struct{
    ApontadorMovimentacao primeiro;
    ApontadorMovimentacao ultimo;
}TipoListaMovimentacao;


void gotoxy();

void tela();

void limpa_msg();

void menuPrincipal();

void menuClientes();

void inclusaoCliente();

void telaCliente();

ApontadorCliente pesquisaCliente();

void alterarCliente();

void alterarClienteID();

void alterarClienteNome();

void alterarClienteStatus();

void alterarClienteEnd();

void alterarClienteTelefone();

void alterarClienteEmail();

void alterarClienteCPF();

void alterarClienteData();

void exclusaoCliente();

void consultaCliente();

void dadosCliente();

void telaOrdemCliente();

void consultaOrdemCliente();

void ordenarCliente();

void inativarCliente();

void removerLinha();

void salvarClientes();

void carregarClientes();

void menuMedicamentos();

void inclusaoMedicamentos();

void telaMedicamentos();

void alterarMedicamentos();

ApontadorMedicamento pesquisaMedicamento();

void dadosMedicamento();

void alterarMedicamentoNome();

void alterarMedicamentoPA();

void alterarMedicamentoValidade();

void alterarMedicamentoLote();

void alterarMedicamentoPreco();

void alterarMedicamentoQuantidade();

void alterarMedicamentoStatus();

void alterarMedicamentoId();

void consultarMedicamento();

void consultaOrdemMedicamento();

void telaOrdemMedicamento();

void ordenarMedicamento();

void inativarMedicamento();

void exclusaoMedicamento();

void salvarMedicamentos();

void carregarMedicamentos();

void menuFornecedores();

void telaFornecedor();

void inclusaoFornecedor();

void alterarFornecedor();

ApontadorFornecedor pesquisaFornecedor();

void dadosFornecedor();

void alterarFornecedorId();

void alterarFornecedorNome();

void alterarFornecedorCnpj();

void alterarFornecedorTelefone();

void alterarFornecedorEmail();

void alterarFornecedorStatus();

void consultaFornecedor();

void telaOrdemFornecedor();

void ordenarFornecedor();

void consultaOrdemFornecedor();

void inativarFornecedor();

void exclusaoFornecedor();

void salvarFornecedor();

void carregarFornecedor();

void alterarMedicamentoIdFornecedor();

void menuMovimentacao();

#endif
