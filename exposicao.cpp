#include "exposicao.h"

/**
 * @brief Define o tipo de arte da exposição.
 * @param t Tipo de arte.
 */
void Exposicao::set_tipo_de_arte(const string& t) {
  tipo_de_arte = t;
}

/**
 * @brief Obtém o tipo de arte da exposição.
 * @return Tipo de arte.
 */
string Exposicao::get_tipo_de_arte() const { 
  return tipo_de_arte; 
}

/**
 * @brief Calcula o preço da exposição.
 * @return Preço da exposição.
 */
double Exposicao::calcula_preco() const {
  return 50.0 + (5.0 * lista_de_artistas.size());
}