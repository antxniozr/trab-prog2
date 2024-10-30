#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("-------------------------------------------------------\n");
    printf("|             VENDA DE INGRESSOS DE SHOW              |\n");
    printf("-------------------------------------------------------\n");
    printf("|(1) Comprar ingresso                                 |\n");
    printf("|(2) Gerenciar shows                                  |\n");
    printf("-------------------------------------------------------\n\n");
    printf("Selecione a funcao que deseja acessar: ");
    scanf("%d", &n);

    if(n == 1)
    {
        printf("-------------------------------------------------------\n");
        printf("|             VENDA DE INGRESSOS DE SHOW              |\n");
        printf("-------------------------------------------------------\n");
        printf("|SELECIONE O SHOW QUE DESEJA:                         |\n");
        //exibir todos os shows disponíveis
    }
    else if(n == 2)
    {
        int nG;
        printf("-------------------------------------------------------\n"); 
        printf("|              GERENCIAMENTO DE SHOWS                 |\n");
        printf("-------------------------------------------------------\n");
        printf("|SELECIONE A FUNCAO QUE DESEJA:                       |\n");
        printf("|(1) Cadastrar shows                                  |\n");
        printf("|(2) Excluir shows                                    |\n");
        printf("|(3) Alterar shows                                    |\n");
        printf("-------------------------------------------------------\n");
        printf("Selecione a funcao que deseja acessar: ");
        scanf("%d", &nG);
        if(nG == 1)
        {
            printf("CADASTRAR SHOW\n");
            printf("Nome do Show: ");
            //fgets();
            printf("Artista/Banda: ");
            //fgets();
            printf("Data do Show: ");
            //fgets();
            printf("Quantidade de ingressos disponiveis: ");
            //fgets();
            //Alocar esses dados no arquivo txt
        }
        else if(nG == 2)
        {
            printf("EXCLUIR SHOW\n");
            printf("Codigo do Show: ");
            //fgets();
            //Excluir o show do arquivo txt
        }
        else if(nG == 3)
        {
            printf("ALTERAR DADOS DE UM SHOW");
            printf("Codigo do Show: ");
            //fgets();
            //Encontrar o show no arquivo txt
        }
        else
        {
            printf("Funcao invalida");
        }
    }
    else
    {
        printf("Funcao invalida.");
    }

    return 0;
}