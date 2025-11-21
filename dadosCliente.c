#include "funcoes.h"

void dadosCliente(TipoListaCliente *listaCliente, int codigo){

    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);

    gotoxy(11,9);
    printf("%d", resultado->conteudo.id_cliente);

    gotoxy(31,9);
    printf("%s", resultado->conteudo.nome);

    gotoxy(12,11);
    printf("%s", resultado->conteudo.cpf);

    gotoxy(55,11);
    printf("%s", resultado->conteudo.telefone);

    gotoxy(14,13);
    printf("%s", resultado->conteudo.email);

    gotoxy(17,15);
    printf("%s", resultado->conteudo.endereco);

    gotoxy(22,17);
    printf("%s", resultado->conteudo.data_cadastro);

    gotoxy(53,17);
    printf("%d", resultado->conteudo.status);
}