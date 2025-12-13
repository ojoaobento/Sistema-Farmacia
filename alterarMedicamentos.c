#include "funcoes.h"

void alterarMedicamentos(TipoListaMedicamento *listaMedicamentos){
    
    int codigo;
    int opcao;
    int verificacao;
    ApontadorMedicamento resultado;
    ApontadorMedicamento p_auxiliar;
    reg_medicamentos temporaria;
    char confirmacao;
    char alteracao;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA CONSULTAR : ");
    scanf("%d", &codigo);

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);

    if(resultado == NULL){
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU PRINCIPAL......");
        getch();
        return;
    } else {

        do{        
            system("cls");
            tela();
            telaMedicamentos();
            dadosMedicamento(listaMedicamentos, resultado);

            limpa_msg();
            gotoxy(2,23);
            printf("ALTERAR(1-ID,2-NOME,3-PA,4-VAL,5-LOTE,6-PRECO,7-QUANT,8-STATUS,0-SAIR): ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:               
                    do {
                        limpa_msg();
                        gotoxy(2,23);
                        printf("ALTERANDO CAMPO......");
                        
                        gotoxy(30,10);
                        printf("                   ");
                        
                        gotoxy(30,10);
                        scanf("%d", &temporaria.id);
                        verificacao=0;
                        p_auxiliar = listaMedicamentos->primeiro;
                        while(p_auxiliar != NULL){
                            if(temporaria.id == p_auxiliar->conteudo.id){
                                limpa_msg();
                                gotoxy(2,23);
                                printf("ESSE ID JA EXISTE, INSIRA OUTRO.....");
                                verificacao=1;
                                getch();
                                break;
                            }
                            p_auxiliar = p_auxiliar->proximo;
                        }

                    }while(verificacao != 0);
                    
                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        resultado->conteudo.id = temporaria.id;
                    } else{
                        return;
                    }
                    break;
                case 2:

                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO......");

                    gotoxy(30,11);
                    printf("                                              ");

                    gotoxy(30,11);
                    fflush(stdin);
                    fgets(temporaria.nome,50,stdin);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        strcpy(resultado->conteudo.nome, temporaria.nome);
                    } else {
                        return;
                    }

                    break;
                case 3:
                    
                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO......");

                    gotoxy(30,12);
                    printf("                                                         ");

                    gotoxy(30,12);
                    fflush(stdin);
                    fgets(temporaria.principio_ativo,50,stdin);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        strcpy(resultado->conteudo.principio_ativo, temporaria.principio_ativo);
                    } else{
                        return;
                    }
                    break;
                case 4:

                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO.....");

                    gotoxy(30,13);
                    printf("                                 ");
                    
                    gotoxy(30,13);
                    fflush(stdin);
                    fgets(temporaria.validade,11,stdin);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        strcpy(resultado->conteudo.validade, temporaria.validade);
                    } else{
                        return;
                    }
                    break;
                case 5:
                    
                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO......");

                    gotoxy(30,14);
                    printf("                                   ");

                    gotoxy(30,14);
                    fflush(stdin);
                    fgets(temporaria.lote,20,stdin);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        strcpy(resultado->conteudo.lote, temporaria.lote);
                    } else {
                        return;
                    }

                    break;
                case 6:
                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO.....");

                    gotoxy(30,15);
                    printf("                  ");

                    gotoxy(30,15);
                    scanf("%f", &temporaria.preco);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        resultado->conteudo.preco = temporaria.preco;
                    } else{
                        return;
                    }
                    break;
                case 7:
                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO.......");

                    gotoxy(30,16);
                    printf("              ");

                    gotoxy(30,16);
                    scanf("%d", &temporaria.quantidade);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        resultado->conteudo.quantidade = temporaria.quantidade;
                    } else{
                        return;
                    }
                    break;
                case 8:
                    limpa_msg();
                    gotoxy(2,23);
                    printf("ALTERANDO CAMPO......");

                    gotoxy(30,17);
                    printf("                     ");

                    gotoxy(30,17);
                    scanf("%d", &temporaria.status);

                    gotoxy(30,19);
                    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
                    scanf(" %c", &confirmacao);

                    if(confirmacao == 's' || confirmacao == 'S'){
                        resultado->conteudo.status = temporaria.status;
                    } else {
                        return;
                    }

                    break;
                case 0:
                    return;
                    break;
                default:
                    limpa_msg();
                    gotoxy(2,23);
                    printf("OPCAO INVALIDA, TENTE NOVAMENTE......");
                    getch();
                    break;
            }
            gotoxy(30,20);
            printf("NOVA ALTERACAO ( S/N ) ? ");
            scanf(" %c", &alteracao);
        }while(alteracao != 'n' && alteracao != 'N');
    }
}