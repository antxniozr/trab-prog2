#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shows.h"

#define ARQUIVO "shows.txt"

// Função para cadastrar um show
void cadastrarShow() 
{
    FILE *arquivo = fopen(ARQUIVO, "a"); // Abre para adicionar no final do arquivo
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Show show;
    printf("Codigo do Show: ");
    scanf("%d", &show.codigo);
    getchar(); // Limpa o buffer

    printf("Nome do Show: ");
    fgets(show.nome, sizeof(show.nome), stdin);
    strtok(show.nome, "\n"); // Remove a nova linha

    printf("Artista/Banda: ");
    fgets(show.artista, sizeof(show.artista), stdin);
    strtok(show.artista, "\n");

    printf("Data do Show: ");
    fgets(show.data, sizeof(show.data), stdin);
    strtok(show.data, "\n");

    printf("Quantidade de ingressos disponiveis: ");
    scanf("%d", &show.ingressos);

    fprintf(arquivo, "%d | %s | %s | %s | %d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
    fclose(arquivo);
    printf("Show cadastrado com sucesso!\n");
}

// Função para excluir um show
void excluirShow() 
{
    int codigo;
    printf("Codigo do Show para excluir: ");
    scanf("%d", &codigo);

    FILE *arquivo = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Show show;
    int encontrado = 0;
    while (fscanf(arquivo, "%d | %49[^|] | %49[^|] | %19[^|] | %d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) {
        if (show.codigo != codigo) 
        {
            fprintf(temp, "%d | %s | %s | %s | %d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
        } 
        else 
        {
            encontrado = 1;
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);

    if (encontrado == 1) 
    {
        printf("Show excluido com sucesso!\n");
    } 
    else 
    {
        printf("Show nao encontrado.\n");
    }
}

// Função para alterar um show
void alterarShow() 
{
    int codigo;
    printf("Codigo do Show para alterar: ");
    scanf("%d", &codigo);

    FILE *arquivo = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Show show;
    int encontrado = 0;
    while (fscanf(arquivo, "%d% | 49[^|] | %49[^|] | %19[^|] | %d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) 
    {
        if (show.codigo == codigo) 
        {
            encontrado = 1;
            printf("Novo Nome do Show: ");
            getchar();
            fgets(show.nome, sizeof(show.nome), stdin);
            strtok(show.nome, "\n");

            printf("Novo Artista/Banda: ");
            fgets(show.artista, sizeof(show.artista), stdin);
            strtok(show.artista, "\n");

            printf("Nova Data do Show: ");
            fgets(show.data, sizeof(show.data), stdin);
            strtok(show.data, "\n");

            printf("Nova Quantidade de ingressos disponiveis: ");
            scanf("%d", &show.ingressos);
        }
        fprintf(temp, "%d | %s | %s | %s | %d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
    }

    fclose(arquivo);
    fclose(temp);
    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);

    if (encontrado) 
    {
        printf("Show alterado com sucesso!\n");
    } 
    else 
    {
        printf("Show nao encontrado.\n");
    }
}

// Função para listar todos os shows
void listarShows() 
{
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) 
    {
        printf("Nenhum show cadastrado.\n");
        return;
    }

    Show show;
    printf("LISTA DE SHOWS DISPONIVEIS:\n");
    printf("-------------------------------------------------------\n");
    while (fscanf(arquivo, "%d | %49[^|] | %49[^|] | %19[^|] | %d\n", &show.codigo, show.nome, show.artista, show.data, &show.ingressos) != EOF) 
    {
        printf("Codigo: %d\nNome: %s\nArtista/Banda: %s\nData: %s\nIngressos: %d\n", show.codigo, show.nome, show.artista, show.data, show.ingressos);
        printf("-------------------------------------------------------\n");
    }
    fclose(arquivo);
}
