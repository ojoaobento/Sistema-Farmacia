#include "funcoes.h"


int main(){

    TipoListaCliente lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;

    system("color 0B");
    gotoxy();
    tela();

    menuPrincipal(&lista);

}