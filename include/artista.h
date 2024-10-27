#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>

// Classe Artista
class Artista {
private:
    std::string nome_do_artista; // Nome do artista
    int idade_do_artista; // Idade do artista

public:
    void set_nome(const std::string& nome); // Define o nome do artista
    std::string get_nome() const; // Obtém o nome do artista

    void set_idade(int idade); // Define a idade do artista
    int get_idade() const; // Obtém a idade do artista

    bool operator<(const Artista& outro) const; // Sobrecarga do operador < para comparar artistas pela idade
    bool operator==(const Artista& outro) const; // Sobrecarga do operador == para comparar artistas
};

#endif // ARTISTA_H