#ifndef SHOW_H
#define SHOW_H

#include "evento.h"

using std::string;

/**
 * @class Show
 * @brief Classe derivada de Evento que representa um show.
 */
class Show : public Evento {
private:
  string genero_musical; ///< Gênero musical do show

public:
  /**
   * @brief Construtor da classe Show.
   * @param nome Nome do evento.
   * @param idade Idade do evento.
   * @param genero Gênero musical do show.
   * @throw invalid_argument Se a idade for negativa.
   */
  Show(const string& nome, int idade, const string& genero): Evento(nome, idade), genero_musical(genero) {}

  /**
   * @brief Define o gênero musical do show.
   * @param g Gênero musical.
   */
  void set_genero_musical(const string& g);

  /**
   * @brief Obtém o gênero musical do show.
   * @return Gênero musical.
   */
  string get_genero_musical() const;

  /**
   * @brief Calcula o preço do show.
   * @return Preço do show.
   */
  double calcula_preco() const override;
};

#endif // SHOW_H