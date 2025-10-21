#ifndef FUNCOES_H
#define FUNCOES_H


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h> 

typedef struct{
    int cd_cliente;
    char nm_cliente[50];
    char nr_documento[20];
    char nr_telefone[15];
    char ds_endereco[50];
    char dt_cadastro[19];
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

#endif
