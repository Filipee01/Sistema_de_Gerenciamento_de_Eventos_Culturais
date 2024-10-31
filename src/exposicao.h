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