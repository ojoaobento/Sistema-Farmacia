#include "funcoes.h"

void carregarClientes(TipoListaCliente *listaCliente){
    ApontadorCliente p;
    ApontadorCliente novoElemento;
    reg_clientes temporaria;
    FILE *f = fopen("clientes.dat", "rb");

    p = listaCliente->primeiro;

    while(fread(&temporaria, sizeof(reg_clientes), 1, f) == 1){
        novoElemento = (ApontadorCliente) malloc(sizeof(TipoCliente));
        novoElemento->conteudo = temporaria;
        novoElemento->proximo = NULL;

        if(listaCliente->primeiro == NULL){
            listaCliente->primeiro = novoElemento;
            listaCliente->ultimo = novoElemento;
        } else {
            listaCliente->ultimo->proximo = novoElemento;
            listaCliente->ultimo = novoElemento;
        }
    }

    fclose(f);

}