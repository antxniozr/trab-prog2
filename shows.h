#ifndef SHOWS_H
#define SHOWS_H

// Estrutura de dados para armazenar as informações de um show
typedef struct {
    int codigo;
    char nome[50];
    char artista[50];
    char data[20];
    int ingressos;
} Show;

// Funções para gerenciamento dos shows
void cadastrarShow();
void excluirShow();
void alterarShow();
void listarShows();

#endif
