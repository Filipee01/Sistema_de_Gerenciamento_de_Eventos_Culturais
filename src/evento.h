#ifndef EVENTO_H
#define EVENTO_H

#include "artista.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

using std::invalid_argument;
using std::string;
using std::vector;

/**
 * @class Evento
 * @brief Classe abstrata que representa um evento cultural.
 * 
 * A classe Evento gerencia informações básicas sobre um evento, incluindo
 * seu nome, idade e a lista de artistas participantes. Esta classe é abstrata
 * e deve ser derivada para implementar o método calcula_preco().
 */
class Evento {
protected:
    string nome_do_evento; ///< Nome do evento
    int idade_do_evento; ///< Idade do evento (tempo desde a criação)
    vector<Artista> lista_de_artistas; ///< Lista de artistas do evento

public:
    /**
     * @brief Construtor da classe Evento.
     * @param nome Nome do evento.
     * @param idade Idade do evento.
     * @throw invalid_argument Se a idade for negativa.
     */
    Evento(const string& nome, int idade);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Evento() = default;

    /**
     * @brief Define o nome do evento.
     * @param n Nome do evento.
     */
    void set_nome(const string& n);

    /**
     * @brief Obtém o nome do evento.
     * @return Nome do evento.
     */
    string get_nome() const;

    /**
     * @brief Define a idade do evento.
     * @param idade Idade do evento.
     * @throw invalid_argument Se a idade for negativa.
     */
    void set_idade(int idade);

    /**
     * @brief Obtém a idade do evento.
     * @return Idade do evento.
     */
    int get_idade() const;

    /**
     * @brief Obtém a lista de artistas do evento.
     * @return Referência constante à lista de artistas.
     */
    const vector<Artista>& get_artistas() const;

    /**
     * @brief Método virtual puro para calcular o preço do evento.
     * @return Preço do evento.
     */
    virtual double calcula_preco() const = 0;

    /**
     * @brief Ordena a lista de artistas pela idade.
     */
    void ordenar_artistas();

    /**
     * @brief Sobrecarga do operador < para comparar eventos pela idade.
     * @param outro Outro evento a ser comparado.
     * @return true se este evento for mais antigo que o outro.
     * @return false caso contrário.
     */
    bool operator<(const Evento& outro) const;

    /**
     * @brief Sobrecarga do operador + para adicionar um artista ao evento.
     * @param artista Artista a ser adicionado.
     */
    void operator+(const Artista& artista);

    /**
     * @brief Sobrecarga do operador - para remover um artista do evento.
     * @param artista Artista a ser removido.
     */
    void operator-(const Artista& artista);
};

#endif // EVENTO_H