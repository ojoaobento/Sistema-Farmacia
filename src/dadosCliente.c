#include "funcoes.h"

void dadosCliente(TipoListaCliente *listaCliente, int codigo){

    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);

    gotoxy(27,10);
    printf("%d", resultado->conteudo.id_cliente);

    gotoxy(27,11);
    printf("%s", resultado->conteudo.nome);

    gotoxy(27,12);
    printf("%s", resultado->conteudo.cpf);

    gotoxy(27,13);
    printf("%s", resultado->conteudo.telefone);

    gotoxy(27,14);
    printf("%s", resultado->conteudo.email);

    gotoxy(27,15);
    printf("%s", resultado->conteudo.endereco);

    gotoxy(27,16);
    printf("%s", resultado->conteudo.data_cadastro);

    gotoxy(27,17);
    printf("%d", resultado->conteudo.status);
}