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


void gotoxy();

void tela();

void limpa_msg();

void menuPrincipal();

void menuClientes();

void inclusaoCliente();

void telaCliente();

ApontadorCliente pesquisaCliente();

void alterarCliente();




#endif
