#include "funcoes.h"

void inclusaoMedicamentos(TipoListaMedicamento *listaMedicamento, TipoListaFornecedor *listaFornecedor){

    ApontadorMedicamento novoElemento;
    ApontadorMedicamento p_auxiliar;
    ApontadorFornecedor r_auxiliar;
    reg_medicamentos temporaria;
    char confirmacao;
    char inclusao;
    int verificacao;
    
    do {

        if(listaFornecedor->primeiro == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("OS FORNECEDORES ESTAO VAZIOS, EFETIVE O CADASTRO DELES PARA PROSSEGUIR.....");
            getch();
            return;
        }

        system("cls");
        tela();
        telaMedicamentos();

        novoElemento = (ApontadorMedicamento) malloc(sizeof(TipoMedicamento));

        do {

            limpa_msg();

            gotoxy(30,10);
            printf("            ");

            gotoxy(30,10);
            scanf("%d", &temporaria.id_fornecedor);
            r_auxiliar = listaFornecedor->primeiro;
            verificacao = 0;
            while(r_auxiliar != NULL){
                if(r_auxiliar->conteudo.id == temporaria.id_fornecedor){
                    novoElemento->conteudo.id_fornecedor = temporaria.id_fornecedor;
                    gotoxy(32,10);
                    printf(" - %s", r_auxiliar->conteudo.nome);
                    verificacao=1;
                    break;
                }
                r_auxiliar = r_auxiliar->proximo;
            }

            if(verificacao == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("O ID INSERIDO NAO EXISTE, TENTE OUTRO.....");
                getch();
            }

        }while(verificacao != 1);

        do {

            limpa_msg();

            gotoxy(30,11);
            printf("            ");

            gotoxy(30,11);
            scanf("%d", &novoElemento->conteudo.id);

            verificacao=0;
            p_auxiliar = listaMedicamento->primeiro;
            while(p_auxiliar != NULL){
                if(p_auxiliar != novoElemento && p_auxiliar->conteudo.id == novoElemento->conteudo.id){
                    limpa_msg();
                    gotoxy(2,23);
                    printf("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO.......");
                    verificacao=1;
                    getch();
                    break;
                }
                p_auxiliar = p_auxiliar->proximo;
            }
        }while(verificacao != 0);     

        do {
            limpa_msg();
            gotoxy(30,12);
            printf("                         ");

            gotoxy(30,12);
            fflush(stdin);
            fgets(novoElemento->conteudo.nome,14,stdin);
            verificacao=0;
            removerLinha(novoElemento->conteudo.nome);
            if(strlen(novoElemento->conteudo.nome) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO NOME.....");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);


        do {
            limpa_msg();
            gotoxy(30,13);
            printf("                                                 ");

            gotoxy(30,13);
            fflush(stdin);
            fgets(novoElemento->conteudo.principio_ativo,20,stdin);
            removerLinha(novoElemento->conteudo.principio_ativo);
            verificacao=0;
            if(strlen(novoElemento->conteudo.principio_ativo) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO PRINCIPIO ATIVO.......");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);

        do {
            limpa_msg();
            gotoxy(30,14);
            printf("                                ");

            gotoxy(30,14);
            fflush(stdin);
            fgets(novoElemento->conteudo.validade,11,stdin);
            removerLinha(novoElemento->conteudo.validade);
            verificacao=0;
            if(strlen(novoElemento->conteudo.validade) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO VALIDADE........");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);   

        do {
            limpa_msg();
            gotoxy(30,15);
            printf("                                         ");

            gotoxy(30,15);
            fflush(stdin);
            fgets(novoElemento->conteudo.lote,20,stdin);
            removerLinha(novoElemento->conteudo.lote);
            verificacao=0;
            if(strlen(novoElemento->conteudo.lote) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO LOTE.........");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);

        gotoxy(30,16);
        scanf("%f", &novoElemento->conteudo.preco);

        gotoxy(30,17);
        scanf("%d", &novoElemento->conteudo.quantidade);

        novoElemento->conteudo.status = 1;

        limpa_msg();
        gotoxy(2,23);
        printf("CONFIRMAR INCLUSAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);

        if(confirmacao == 'S' || confirmacao == 's'){
            if(listaMedicamento->primeiro == NULL){
                novoElemento->proximo = NULL;
                listaMedicamento->primeiro = novoElemento;
                listaMedicamento->ultimo = novoElemento;

                gotoxy(30,18);
                printf("1");

            } else {
                novoElemento->proximo = NULL;
                listaMedicamento->ultimo->proximo = novoElemento;
                listaMedicamento->ultimo = novoElemento;
            }
        } else {
            free(novoElemento);
            return;
        }
        limpa_msg();
        gotoxy(2,23);
        printf("NOVA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &inclusao);

    }while(inclusao != 'n' && inclusao != 'N');
}