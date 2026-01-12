#include "funcoes.h"

void dadosMedicamento(TipoListaMedicamento *listaMedicamento, ApontadorMedicamento resultado){

    gotoxy(30,10);
    printf("%d", resultado->conteudo.id_fornecedor);

    gotoxy(30,11);
    printf("%d", resultado->conteudo.id);

    gotoxy(30,12);
    printf("%s", resultado->conteudo.nome);

    gotoxy(30,13);
    printf("%s", resultado->conteudo.principio_ativo);

    gotoxy(30,14);
    printf("%s", resultado->conteudo.validade);

    gotoxy(30,15);
    printf("%s", resultado->conteudo.lote);

    gotoxy(30,16);
    printf("%.2f", resultado->conteudo.preco);

    gotoxy(30,17);
    printf("%d", resultado->conteudo.quantidade);

    gotoxy(30,18);
    printf("%d", resultado->conteudo.status);  
}