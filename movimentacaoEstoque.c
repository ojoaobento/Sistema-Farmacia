#include "funcoes.h"

void movimentacaoEstoque(TipoListaMedicamento *listaMedicamento, TipoListaEstoque *listaEstoque){

    int codigo;
    int opcao;
    ApontadorMedicamento resultado;
    ApontadorEstoque estoque;
    reg_medicamentos temporaria;
    char confirmacao;
    int verificacao;
    char novaMovimentacao;

    do {
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA ALTERAR O ESTOQUE : ");
        scanf("%d", &codigo);

        resultado = pesquisaMedicamento(listaMedicamento, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("O ID INSERIDO NAO ESTA REGISTRADO, VOLTE AO MENU PRINCIPAL....");
            getch();
            return;
        }else{
            
            estoque = (ApontadorEstoque) malloc(sizeof(TipoEstoque));
            estoque->proximo = NULL;

            system("cls");
            tela();
            telaMedicamentos();
            dadosMedicamento(listaMedicamento, resultado);

            limpa_msg();
            gotoxy(2,23);
            printf("REALIZAR MOVIMENTACAO DE ESTOQUE(1-AUMENTAR,2-DIMINUIR) : ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                    do {
                        limpa_msg();
                        gotoxy(2,23);
                        printf("MOVIMENTANDO........");

                        gotoxy(30,17);
                        printf("            ");

                        gotoxy(30,17);
                        scanf("%d", &temporaria.quantidade);
                        verificacao=0;
                        if(temporaria.quantidade <= 0){
                            limpa_msg();
                            gotoxy(2,23);
                            printf("INSIRA UM VALOR POSITIVO, POIS ASSIM IRA AUMENTAR A QUANTIDADE.......");
                            verificacao=1;
                            getch();
                        }
                    }while(verificacao != 0);

                    gotoxy(30,17);
                    printf("             ");

                    gotoxy(30,17);
                    printf("%d  +  %d = %d",resultado->conteudo.quantidade,temporaria.quantidade, resultado->conteudo.quantidade + temporaria.quantidade);
                    
                    do {

                        limpa_msg();
                        gotoxy(30,19);
                        printf("                   ");

                        gotoxy(7,19);
                        printf("DATA MOVIMENTACAO....: ");
                        fflush(stdin);
                        fgets(estoque->conteudo.data,11,stdin);
                        removerLinha(estoque->conteudo.data);
                        verificacao=0;
                        if(strlen(estoque->conteudo.data) == 0){
                            limpa_msg();
                            gotoxy(2,23);
                            printf("PREENCHA O CAMPO DATA.......");
                            verificacao=1;
                            getch();
                        }else if(verificacaoData(estoque->conteudo.data) != 1){
                            limpa_msg();
                            gotoxy(2,23);
                            printf("INSIRA UMA DATA VALIDA.......");
                            verificacao=1;
                            getch();
                        }
                    }while(verificacao != 0);

                    limpa_msg();
                    gotoxy(2,23);
                    printf("CONFIRMAR MOVIMENTACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        resultado->conteudo.quantidade += temporaria.quantidade;
                        estoque->conteudo.quantidade = temporaria.quantidade;
                        estoque->conteudo.id_medicamento = resultado->conteudo.id;
                        estoque->conteudo.tipo_reposicao = 1;
                    }else{
                        free(estoque);
                        return;
                    }

                    break;
                case 2:
                    do {
                        limpa_msg();
                        gotoxy(2,23);
                        printf("MOVIMENTANDO........");

                        gotoxy(30,17);
                        printf("          ");

                        gotoxy(30,17);
                        scanf("%d", &temporaria.quantidade);
                        verificacao=0;
                        if(temporaria.quantidade <= 0 || temporaria.quantidade > resultado->conteudo.quantidade){
                            limpa_msg();
                            gotoxy(2,23);
                            printf("INSIRA UM VALOR VALIDO PARA REMOVER A QUANTIDADE......");
                            verificacao=1;
                            getch();
                        }
                    }while(verificacao != 0);

                    gotoxy(30,17);
                    printf("            ");

                    gotoxy(30,17);
                    printf("%d  -  %d = %d",resultado->conteudo.quantidade,temporaria.quantidade, resultado->conteudo.quantidade - temporaria.quantidade);
                    
                    do {

                        limpa_msg();
                        gotoxy(30,19);
                        printf("                   ");

                        gotoxy(7,19);
                        printf("DATA MOVIMENTACAO....: ");
                        fflush(stdin);
                        fgets(estoque->conteudo.data,11,stdin);
                        removerLinha(estoque->conteudo.data);
                        verificacao=0;

                        if(strlen(estoque->conteudo.data) == 0){
                            limpa_msg();
                            gotoxy(2,23);
                            printf("PREENCHA O CAMPO DATA.......");
                            verificacao=1;
                            getch();
                        }else if(verificacaoData(estoque->conteudo.data) != 1){
                            limpa_msg();
                            gotoxy(2,23);
                            printf("INSIRA UMA DATA VALIDA.......");
                            verificacao=1;
                            getch();
                        }
                    }while(verificacao != 0);

                    limpa_msg();
                    gotoxy(2,23);
                    printf("CONFIRMAR REPOSICAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        resultado->conteudo.quantidade -= temporaria.quantidade;
                        estoque->conteudo.quantidade = temporaria.quantidade;
                        estoque->conteudo.id_medicamento = resultado->conteudo.id;
                        estoque->conteudo.tipo_reposicao = 2;
                    }else{
                        free(estoque);
                        return;
                    }
                    break;
                default:
                    system("cls");
                    tela();
                    limpa_msg();
                    gotoxy(2,23);
                    printf("OPCAO INVALIDA, VOLTE AO MENU PRINCIPAL......");
                    getch();
                    return;
                    break;
            }
        }

        if(listaEstoque->primeiro == NULL){
            listaEstoque->primeiro = estoque;
            listaEstoque->ultimo = estoque;
            listaEstoque->ultimo->proximo = NULL;
        }else{
            listaEstoque->ultimo->proximo = estoque;
            listaEstoque->ultimo = estoque;
            listaEstoque->ultimo->proximo = NULL;
        }
        
        limpa_msg();
        gotoxy(2,23);
        printf("NOVA MOVIMENTACAO ( S/N ) ? ");
        scanf(" %c", &novaMovimentacao);
    }while(novaMovimentacao != 'n' && novaMovimentacao != 'N');
}