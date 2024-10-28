#include "evento.h"
#include <algorithm>
#include <stdexcept>

using std::invalid_argument;
using std::string;


/**
 * @brief Define o nome do evento.
 * @param n Nome do evento.
 */
void Evento::set_nome(const string& n) {
    nome_do_evento = n;
}

/**
 * @brief Obtém o nome do evento.
 * @return Nome do evento.
 */
string Evento::get_nome() const {
    return nome_do_evento;
}

/**
 * @brief Define a idade do evento.
 * @param idade Idade do evento.
 * @throw std::invalid_argument Se a idade for negativa.
 */
void Evento::set_idade(int idade) {
    if (idade < 0) throw invalid_argument("Idade não pode ser negativa");
    idade_do_evento = idade;
}

/**
 * @brief Obtém a idade do evento.
 * @return Idade do evento.
 */
int Evento::get_idade() const {
    return idade_do_evento;
}

/**
 * @brief Obtém a lista de artistas do evento.
 * @return Referência constante à lista de artistas.
 */
const std::vector<Artista>& Evento::get_artistas() const {
    return lista_de_artistas;
}

/**
 * @brief Ordena a lista de artistas pela idade.
 */
void Evento::ordenar_artistas() {
    std::sort(lista_de_artistas.begin(), lista_de_artistas.end());
}

/**
 * @brief Sobrecarga do operador < para comparar eventos pela idade.
 * @param outro Outro evento a ser comparado.
 * @return true se este evento for mais antigo que o outro.
 * @return false caso contrário.
 */
bool Evento::operator<(const Evento& outro) const {
    return idade_do_evento < outro.idade_do_evento;
}

/**
 * @brief Sobrecarga do operador + para adicionar um artista ao evento.
 * @param artista Artista a ser adicionado.
 */
void Evento::operator+(const Artista& artista) {
    lista_de_artistas.push_back(artista);
    ordenar_artistas();
}

/**
 * @brief Sobrecarga do operador - para remover um artista do evento.
 * @param artista Artista a ser removido.
 */
void Evento::operator-(const Artista& artista) {
    lista_de_artistas.erase(std::remove(lista_de_artistas.begin(), lista_de_artistas.end(), artista), lista_de_artistas.end());
}