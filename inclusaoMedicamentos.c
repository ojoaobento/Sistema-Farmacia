#include "funcoes.h"

void inclusaoMedicamentos(TipoListaMedicamento *listaMedicamento){

    ApontadorMedicamento novoElemento;
    ApontadorMedicamento p_auxiliar;
    char confirmacao;
    char inclusao;
    int verificacao;
    
    do {
        system("cls");
        tela();
        telaMedicamentos();

        novoElemento = (ApontadorMedicamento) malloc(sizeof(TipoMedicamento));

        do {

            limpa_msg();

            gotoxy(30,10);
            printf("            ");

            gotoxy(30,10);
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
            gotoxy(30,11);
            printf("                         ");

            gotoxy(30,11);
            fflush(stdin);
            fgets(novoElemento->conteudo.nome,50,stdin);
            verificacao=0;
            removerLinha(novoElemento->conteudo.nome);
            if(strlen(novoElemento->conteudo.nome) == '\0'){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO NOME.....");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);


        do {
            limpa_msg();
            gotoxy(30,12);
            printf("                                                 ");

            gotoxy(30,12);
            fflush(stdin);
            fgets(novoElemento->conteudo.principio_ativo,50,stdin);
            removerLinha(novoElemento->conteudo.principio_ativo);
            verificacao=0;
            if(strlen(novoElemento->conteudo.principio_ativo) == '\0'){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO PRINCIPIO ATIVO.......");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);

        do {
            limpa_msg();
            gotoxy(30,13);
            printf("                                ");

            gotoxy(30,13);
            fflush(stdin);
            fgets(novoElemento->conteudo.validade,11,stdin);
            removerLinha(novoElemento->conteudo.validade);
            verificacao=0;
            if(strlen(novoElemento->conteudo.validade) == '\0'){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO VALIDADE........");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);   

        do {
            limpa_msg();
            gotoxy(30,14);
            printf("                                         ");

            gotoxy(30,14);
            fflush(stdin);
            fgets(novoElemento->conteudo.lote,20,stdin);
            removerLinha(novoElemento->conteudo.lote);
            verificacao=0;
            if(strlen(novoElemento->conteudo.lote) == '\0'){
                limpa_msg();
                gotoxy(2,23);
                printf("PREENCHA O CAMPO LOTE.........");
                verificacao=1;
                getch();
            }
        }while(verificacao != 0);

        gotoxy(30,15);
        scanf("%f", &novoElemento->conteudo.preco);

        gotoxy(30,16);
        scanf("%d", &novoElemento->conteudo.quantidade);

        novoElemento->conteudo.status = 1;

        gotoxy(30,19);
        printf("CONFIRMAR INCLUSAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);

        if(confirmacao == 'S' || confirmacao == 's'){
            if(listaMedicamento->primeiro == NULL){
                novoElemento->proximo = NULL;
                listaMedicamento->primeiro = novoElemento;
                listaMedicamento->ultimo = novoElemento;

                gotoxy(30,17);
                printf("1");

            } else {
                novoElemento->proximo = NULL;
                listaMedicamento->ultimo->proximo = novoElemento;
                listaMedicamento->ultimo = novoElemento;
            }
        } else {
            return;
        }

        gotoxy(30,20);
        printf("NOVA INCLUSAO ( S/N ) ? ");
        scanf(" %c", &inclusao);

    }while(inclusao != 'n' && inclusao != 'N');
}