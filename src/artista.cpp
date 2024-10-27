#include "artista.h"
#include <stdexcept>

// Define o nome do artista
void Artista::set_nome(const std::string& nome) {
    nome_do_artista = nome;
}

// Obtém o nome do artista
std::string Artista::get_nome() const {
    return nome_do_artista;
}

// Define a idade do artista
void Artista::set_idade(int idade) {
    if (idade < 0) throw std::invalid_argument("Idade não pode ser negativa");
    idade_do_artista = idade;
}

// Obtém a idade do artista
int Artista::get_idade() const {
    return idade_do_artista;
}

// Sobrecarga do operador < para comparar artistas pela idade
bool Artista::operator<(const Artista& outro) const {
    return idade_do_artista < outro.idade_do_artista;
}

// Sobrecarga do operador == para comparar artistas
bool Artista::operator==(const Artista& outro) const {
    return nome_do_artista == outro.nome_do_artista && idade_do_artista == outro.idade_do_artista;
}