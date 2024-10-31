#ifndef EXPOSICAO_H
#define EXPOSICAO_H

#include "evento.h"

using std::string;

/**
 * @class Exposicao
 * @brief Classe derivada de Evento que representa uma exposição.
 */
class Exposicao : public Evento {
private:
  string tipo_de_arte; ///< Tipo de arte da exposição

public:
  /**
   * @brief Construtor da classe Exposicao.
   * @param nome Nome do evento.
   * @param idade Idade do evento.
   * @param tipo Tipo de arte da exposição.
   * @throw invalid_argument Se a idade for negativa.
   */
  Exposicao(const string& nome, int idade, const string& tipo): Evento(nome, idade), tipo_de_arte(tipo) {}

  /**
   * @brief Define o tipo de arte da exposição.
   * @param t Tipo de arte.
   */
  void set_tipo_de_arte(const string& t);

  /**
   * @brief Obtém o tipo de arte da exposição.
   * @return Tipo de arte.
   */
  string get_tipo_de_arte() const;

  /**
   * @brief Calcula o preço da exposição.
   * @return Preço da exposição.
   */
  double calcula_preco() const override;
};

#endif // EXPOSICAO_H