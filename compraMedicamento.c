#include "funcoes.h"

void compraMedicamento(TipoListaMovimentacao *listaMovimentacao, TipoListaCliente *listaCliente, TipoListaMedicamento *listaMedicamento){

    ApontadorMovimentacao novo;
    reg_movimentacoes temporaria;
    ApontadorCliente p;
    ApontadorMedicamento r;
    ApontadorMedicamento t;
    int verificacao;
    float valorTotal;
    char novaCompra;
    char confirmar;


    if(listaMedicamento->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("NAO EXISTE MEDICAMENTOS CADASTRADOS, VOLTE AO MENU PRINCIPAL.....");
        getch();
        return;
    } else if(listaCliente->primeiro == NULL){
        system("cls");
        tela();
        limpa_msg();
        gotoxy(2,23);
        printf("NAO EXISTE CLIENTES CADASTRADOS, VOLTE AO MENU PRINCIPAL.....");
        getch();
        return;       
    }

    do {

        system("cls");
        tela();
        telaMovimentacao();

        novo = (ApontadorMovimentacao) malloc(sizeof(TipoMovimentacao));
        novo->proximo = NULL;

        do{
            limpa_msg();
            gotoxy(33,10);
            printf("           ");

            gotoxy(33,10);
            scanf("%d", &temporaria.cd_cliente);
            p = listaCliente->primeiro;
            verificacao=0;
            while(p != NULL){
                if(temporaria.cd_cliente == p->conteudo.id_cliente && p->conteudo.status == 1){
                    novo->conteudo.cd_cliente = temporaria.cd_cliente;
                    verificacao=1;
                    gotoxy(38,10);
                    printf(" - %s", p->conteudo.nome);
                    break;
                }
                p = p->proximo;
            }

            if(verificacao == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("O CODIGO INSERIDO NAO EXISTE OU ESTA INATIVO, INSIRA OUTRO........");
                getch();
            }

        }while(verificacao != 1);


        do {

            limpa_msg();
            gotoxy(33,11);
            printf("         ");

            gotoxy(33,11);
            scanf("%d", &temporaria.cd_medicamento);
            verificacao = 0;
            r = listaMedicamento->primeiro;
            while(r != NULL){
                if(temporaria.cd_medicamento == r->conteudo.id && r->conteudo.status == 1 && r->conteudo.quantidade > 0){
                    novo->conteudo.cd_medicamento = temporaria.cd_medicamento;
                    verificacao=1;
                    gotoxy(38,11);
                    printf("- %s", r->conteudo.nome);
                    break;
                }
                r = r->proximo;
            }

            if(verificacao == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("MEDICAMENTO INVALIDO OU SEM ESTOQUE, INSIRA OUTRO......");
                getch();
            }

        }while(verificacao != 1);

        t = pesquisaMedicamento(listaMedicamento, novo->conteudo.cd_medicamento);

        gotoxy(33,12);
        printf("R$ %.2f", t->conteudo.preco);
        novo->conteudo.valor = t->conteudo.preco;

        do {

            limpa_msg();
            gotoxy(33,13);
            printf("           ");

            verificacao=0;
            gotoxy(33,13);
            scanf("%d", &novo->conteudo.quantidade);
            if(novo->conteudo.quantidade > t->conteudo.quantidade){
                limpa_msg();
                gotoxy(2,23);
                printf("NAO EXISTE ESSE QUANTIDADE EM ESTOQUE, INSIRA OUTRA......");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);

        valorTotal = novo->conteudo.quantidade * novo->conteudo.valor;

        novo->conteudo.valor_total = valorTotal;

        gotoxy(33,14);
        printf("R$ %.2f", novo->conteudo.valor_total);

        do {

            limpa_msg();
            gotoxy(33,15);
            printf("                  ");

            gotoxy(33,15);
            fflush(stdin);
            fgets(temporaria.dt_compra,11,stdin);
            removerLinha(temporaria.dt_compra);
            verificacao=0;
            if(strlen(temporaria.dt_compra) == 0){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO DATA.......");
                verificacao=1;
                getch();
            }else if(verificacaoData(temporaria.dt_compra) != 1){
                limpa_msg();
                gotoxy(2,23);
                printf("DATA INVALIDA, INSIRA NOVAMENTE.......");
                verificacao=1;
                getch();            
            }
        }while(verificacao != 0);   
        
        
        strcpy(novo->conteudo.dt_compra,temporaria.dt_compra);

        limpa_msg();
        gotoxy(2,23);
        printf("CONFIRMAR COMPRA ( S/N ) ? ");
        scanf(" %c", &confirmar);

        if(confirmar == 's' || confirmar == 'S'){
            if(listaMovimentacao->primeiro == NULL){
                listaMovimentacao->primeiro = novo;
                listaMovimentacao->ultimo = novo;
            }else{
                listaMovimentacao->ultimo->proximo = novo;
                listaMovimentacao->ultimo = novo;
            }

            t->conteudo.quantidade -= novo->conteudo.quantidade;

        }else{
            free(novo);
            return;
        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA COMPRA ( S/N ) ? ");
        scanf(" %c", &novaCompra);


    }while(novaCompra != 'n' && novaCompra != 'N');

}