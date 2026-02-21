#include "funcoes.h"

void dadosFornecedor(TipoListaFornecedor *listaFornecedor, int codigo){
    ApontadorFornecedor resultado;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    gotoxy(21,11);
    printf("%d", resultado->conteudo.id);

    gotoxy(21,12);
    printf("%s", resultado->conteudo.nome);

    gotoxy(21,13);
    printf("%s", resultado->conteudo.cnpj);

    gotoxy(21,14);
    printf("%s", resultado->conteudo.telefone);

    gotoxy(21,15);
    printf("%s", resultado->conteudo.email);

    gotoxy(21,16);
    printf("%d", resultado->conteudo.status);
}