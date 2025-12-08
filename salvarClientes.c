#include "funcoes.h"

void salvarClientes(TipoListaCliente listaCliente){
    
    ApontadorCliente p;

    FILE *f = fopen("clientes.dat", "wb");

    p = listaCliente->primeiro;

    while(p != NULL){
        fwrite(&p->conteudo, sizeof(reg_clientes),1,f);
        p = p->proximo;
    }

    fclose(f);
}