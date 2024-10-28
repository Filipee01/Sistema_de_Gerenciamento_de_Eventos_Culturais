#ifndef ARTISTA_H
#define ARTISTA_H

#include <stdexcept>
#include <string>

using std::invalid_argument;
using std::string;

/**
 * @class Artista
 * @brief Classe que representa um artista.
 */
class Artista {
private:
  string nome_do_artista; ///< Nome do artista
  int idade_do_artista;   ///< Idade do artista

public:
  /**
   * @brief Define o nome do artista.
   * @param n Nome do artista.
   */
  void set_nome(const string& n);

  /**
   * @brief Obtém o nome do artista.
   * @return Nome do artista.
   */
  string get_nome() const;

  /**
   * @brief Define a idade do artista.
   * @param idade Idade do artista.
   * @throw invalid_argument Se a idade for negativa.
   */
  void set_idade(int idade);

  /**
   * @brief Obtém a idade do artista.
   * @return Idade do artista.
   */
  int get_idade() const;

  /**
   * @brief Sobrecarga do operador < para comparar artistas pela idade.
   * @param outro Outro artista a ser comparado.
   * @return true se este artista for mais jovem que o outro.
   * @return false caso contrário.
   */
  bool operator<(const Artista& outro) const;

  /**
   * @brief Sobrecarga do operador == para comparar artistas.
   * @param outro Outro artista a ser comparado.
   * @return true se os artistas forem iguais.
   * @return false caso contrário.
   */
  bool operator==(const Artista& outro) const;
};

#endif // ARTISTA_H