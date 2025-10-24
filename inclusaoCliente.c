#include "funcoes.h"

void inclusaoCliente(TipoListaCliente *lista){
    
    ApontadorCliente novoCadastro;

    novoCadastro = (ApontadorCliente) malloc(sizeof(TipoCliente));

    system("cls");
    tela();

    telaCliente();

    gotoxy(9,10);
    scanf("%d", &novoCadastro->conteudo.id_cliente);

    gotoxy(50,10);
    fflush(stdin);
    fgets(novoCadastro->conteudo.nome,50,stdin);

    gotoxy(15,12);
    fflush(stdin);
    fgets(novoCadastro->conteudo.cpf,15,stdin);

    gotoxy(55,12);
    fflush(stdin);
    fgets(novoCadastro->conteudo.telefone,20,stdin);

    gotoxy(15,14);
    fflush(stdin);
    fgets(novoCadastro->conteudo.email,50,stdin);

    gotoxy(17,16);
    fflush(stdin);
    fgets(novoCadastro->conteudo.endereco,80,stdin);

    gotoxy(17,18);
    fflush(stdin);
    fgets(novoCadastro->conteudo.data_cadastro,19,stdin);

    gotoxy(55,18);
    scanf("%d", &novoCadastro->conteudo.status);

}