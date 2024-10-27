#ifndef EVENTO_H
#define EVENTO_H

#include "artista.h"
#include <vector>
#include <string>

// Classe abstrata Evento
class Evento {
protected:
    std::string nome_do_evento; // Nome do evento
    int idade_do_evento; // Idade do evento (tempo desde a criação)
    std::vector<Artista> lista_de_artistas; // Lista de artistas do evento

public:
    virtual ~Evento() = default; // Destrutor virtual

    void set_nome(const std::string& nome); // Define o nome do evento
    std::string get_nome() const; // Obtém o nome do evento

    void set_idade(int idade); // Define a idade do evento
    int get_idade() const; // Obtém a idade do evento

    std::vector<Artista> get_artistas() const; // Obtém a lista de artistas do evento

    virtual double calcula_preco() const = 0; // Método virtual puro para calcular o preço do evento

    void ordenar_artistas(); // Ordena a lista de artistas pela idade

    bool operator<(const Evento& outro) const; // Sobrecarga do operador < para comparar eventos pela idade

    void operator+(const Artista& artista); // Sobrecarga do operador + para adicionar um artista ao evento
    void operator-(const Artista& artista); // Sobrecarga do operador - para remover um artista do evento
};

#endif // EVENTO_H