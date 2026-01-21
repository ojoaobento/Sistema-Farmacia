#include "funcoes.h"

void inclusaoFornecedor(TipoListaFornecedor *listaFornecedor){

    ApontadorFornecedor novoElemento;
    ApontadorFornecedor p_auxiliar;
    char confirmacao;
    char inclusao;
    int verificacao;
    int outraVerificacao;

    do {
        system("cls");
        tela();
        telaFornecedor();
        novoElemento = (ApontadorFornecedor) malloc(sizeof(TipoFornecedor));

        do {
            limpa_msg();
            gotoxy(21,11);
            printf("             ");
            gotoxy(21,11);
            scanf("%d", &novoElemento->conteudo.id);
            p_auxiliar = listaFornecedor->primeiro;
            verificacao = 0;
            while(p_auxiliar != NULL){
                if(p_auxiliar->conteudo.id == novoElemento->conteudo.id){
                    limpa_msg();
                    gotoxy(2,23);
                    printf("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO......");
                    verificacao = 1;
                    getch();
                }
                p_auxiliar = p_auxiliar->proximo;
            }
        }while(verificacao != 0);

        do{ 
            limpa_msg();
            gotoxy(21,12);
            fflush(stdin);
            fgets(novoElemento->conteudo.nome,50,stdin);
            removerLinha(novoElemento->conteudo.nome);
            verificacao = 0;
            if(strlen(novoElemento->conteudo.nome) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO NOME.....");
                verificacao = 1;
                getch();
            }

        }while(verificacao != 0);   

        do {

            gotoxy(21,13);
            printf("                                ");

            limpa_msg();
            gotoxy(21,13);
            fflush(stdin);
            fgets(novoElemento->conteudo.cnpj,15,stdin);
            removerLinha(novoElemento->conteudo.cnpj);
            verificacao = 0;
            outraVerificacao=0;
            if(strlen(novoElemento->conteudo.cnpj) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO CNPJ....");
                verificacao = 1;
                getch();
            }else if(strlen(novoElemento->conteudo.cnpj) != 14){
                limpa_msg();
                gotoxy(2,23);
                printf("CNPJ INVALIDO, INSIRA NOVAMENTE.........");
                outraVerificacao=1;
                getch();
            }
        }while(verificacao != 0 || outraVerificacao != 0);

        do{ 
            limpa_msg();
            gotoxy(21,14);
            fflush(stdin);
            fgets(novoElemento->conteudo.telefone,20,stdin);
            removerLinha(novoElemento->conteudo.telefone);
            verificacao=0;
            if(strlen(novoElemento->conteudo.telefone) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO TELEFONE......");
                verificacao = 1;
                getch();
            }
        }while(verificacao != 0);

        do {
            limpa_msg();
            gotoxy(21,15);
            fflush(stdin);
            fgets(novoElemento->conteudo.email,50,stdin);
            removerLinha(novoElemento->conteudo.email);
            verificacao = 0;
            if(strlen(novoElemento->conteudo.email) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO EMAIL.....");
                verificacao = 1;
                getch();
            }
        }while(verificacao != 0) ;  

        novoElemento->conteudo.status = 1;

        gotoxy(30,19);
        printf("CONFIRMAR INCLUSAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);

        if(confirmacao == 'S' || confirmacao == 's'){
            if(listaFornecedor->primeiro == NULL){
                novoElemento->proximo = NULL;
                novoElemento->anterior = NULL;
                listaFornecedor->primeiro = novoElemento;
                listaFornecedor->ultimo = novoElemento;


            }else{
                novoElemento->proximo = NULL;
                novoElemento->anterior = listaFornecedor->ultimo;
                listaFornecedor->ultimo->proximo = novoElemento;
                listaFornecedor->ultimo = novoElemento;   
            }

            gotoxy(21,16);
            printf("1");
            
        }
        gotoxy(30,20);
        printf("NOVA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &inclusao);
    }while(inclusao != 'n' && inclusao != 'N');
}