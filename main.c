#include <stdio.h>
#include <stdlib.h>
#include "shows.h"

//COLOCAR LOOP NO CODIGO, PRA CONTINUAR EXECUTANDO DEPOIS DE EXECUTAR UMA FUNCAO

int main() 
{
    int n;
    printf("-------------------------------------------------------\n");
    printf("|             VENDA DE INGRESSOS DE SHOW              |\n");
    printf("-------------------------------------------------------\n");
    printf("|(1) Comprar ingresso                                 |\n");
    printf("|(2) Gerenciar shows                                  |\n");
    printf("|(0) Sair                                             |\n"); //arrumar essa funcionalidade
    printf("-------------------------------------------------------\n\n");
    printf("Selecione a funcao que deseja acessar: ");
    scanf("%d", &n);

    if (n == 1) 
    {
        printf("-------------------------------------------------------\n");
        printf("|             VENDA DE INGRESSOS DE SHOW              |\n");
        printf("-------------------------------------------------------\n");
        listarShows(); // Exibe os shows disponíveis
    } 
    else if (n == 2) 
    {
        int nG;
        printf("-------------------------------------------------------\n"); 
        printf("|              GERENCIAMENTO DE SHOWS                 |\n");
        printf("-------------------------------------------------------\n");
        printf("|SELECIONE A FUNCAO QUE DESEJA:                       |\n");
        printf("|(1) Cadastrar shows                                  |\n");
        printf("|(2) Excluir shows                                    |\n");
        printf("|(3) Alterar shows                                    |\n");
        printf("|(0) Retornar                                         |\n"); //arrumar essa funcionalidade
        printf("-------------------------------------------------------\n");
        printf("Selecione a funcao que deseja acessar: ");
        scanf("%d", &nG);

        switch (nG) 
        {
            case 1:
                cadastrarShow();
                break;
            case 2:
                excluirShow();
                break;
            case 3:
                alterarShow();
                break;
            default:
                printf("Funcao invalida.\n");
        }
    } 
    else 
    {
        printf("Funcao invalida.\n");
    }

    return 0;
}
