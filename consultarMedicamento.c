#include "funcoes.h"

void consultarMedicamento(TipoListaMedicamento *listaMedicamento){
    
    int codigo;
    ApontadorMedicamento resultado;
    char consulta;

    do {
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("INSIRA O CODIGO DO MEDICAMENTO QUE DESEJA BUSCAR : ");
        scanf("%d", &codigo);

        resultado = pesquisaMedicamento(listaMedicamento, codigo);

        if(resultado == NULL){
            system("cls");
            tela();
            limpa_msg();
            gotoxy(2,23);
            printf("O CODIGO INSERIDO NAO EXISTE, RETORNE AO MENU PRINCIPAL......");
            getch();
            return;
        } else{
            system("cls");
            tela();
            telaMedicamentos();
            dadosMedicamento(listaMedicamento, resultado);
        }

        limpa_msg();
        gotoxy(2,23);
        printf("NOVA CONSULTA ( S/N ) ? ");
        scanf(" %c", &consulta);

    }while(consulta != 'n' && consulta != 'N'); 
    return;
}