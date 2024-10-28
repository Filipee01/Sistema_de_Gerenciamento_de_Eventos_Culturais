#include "show.h"

/**
 * @brief Define o gênero musical do show.
 * @param g Gênero musical.
 */
void Show::set_genero_musical(const string& g) {
  genero_musical = g;
}

/**
 * @brief Obtém o gênero musical do show.
 * @return Gênero musical.
 */
string Show::get_genero_musical() const {
   return genero_musical; 
}

/**
 * @brief Calcula o preço do show.
 * @return Preço do show.
 */
double Show::calcula_preco() const {
  return 100.0 + (10.0 * lista_de_artistas.size());
}