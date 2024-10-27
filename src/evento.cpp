#include "evento.h"
#include <algorithm>
#include <stdexcept>

// Define o nome do evento
void Evento::set_nome(const std::string& nome) {
    nome_do_evento = nome;
}

// Obtém o nome do evento
std::string Evento::get_nome() const {
    return nome_do_evento;
}

// Define a idade do evento
void Evento::set_idade(int idade) {
    if (idade < 0) throw std::invalid_argument("Idade não pode ser negativa");
    idade_do_evento = idade;
}

// Obtém a idade do evento
int Evento::get_idade() const {
    return idade_do_evento;
}

// Obtém a lista de artistas do evento
std::vector<Artista> Evento::get_artistas() const {
    return lista_de_artistas;
}

// Ordena a lista de artistas pela idade
void Evento::ordenar_artistas() {
    std::sort(lista_de_artistas.begin(), lista_de_artistas.end());
}

// Sobrecarga do operador < para comparar eventos pela idade
bool Evento::operator<(const Evento& outro) const {
    return idade_do_evento < outro.idade_do_evento;
}

// Sobrecarga do operador + para adicionar um artista ao evento
void Evento::operator+(const Artista& artista) {
    lista_de_artistas.push_back(artista);
    ordenar_artistas();
}

// Sobrecarga do operador - para remover um artista do evento
void Evento::operator-(const Artista& artista) {
    lista_de_artistas.erase(std::remove(lista_de_artistas.begin(), lista_de_artistas.end(), artista), lista_de_artistas.end());
}