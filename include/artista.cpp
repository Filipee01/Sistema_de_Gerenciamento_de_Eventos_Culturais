#include "artista.h"

/**
 * @brief Define o nome do artista.
 * @param n Nome do artista.
 */
void Artista::set_nome(const string& n) {
   nome_do_artista = n; 
}

/**
 * @brief Obtém o nome do artista.
 * @return Nome do artista.
 */
string Artista::get_nome() const { 
  return nome_do_artista; 
}

/**
 * @brief Define a idade do artista.
 * @param idade Idade do artista.
 * @throw invalid_argument Se a idade for negativa.
 */
void Artista::set_idade(int idade) {
  if (idade < 0)
    throw invalid_argument("Idade nao pode ser negativa");
  idade_do_artista = idade;
}

/**
 * @brief Obtém a idade do artista.
 * @return Idade do artista.
 */
int Artista::get_idade() const {
   return idade_do_artista; 
}

/**
 * @brief Sobrecarga do operador < para comparar artistas pela idade.
 * @param outro Outro artista a ser comparado.
 * @return true se este artista for mais jovem que o outro.
 * @return false caso contrário.
 */
bool Artista::operator<(const Artista& outro) const {
  return idade_do_artista < outro.idade_do_artista;
}

/**
 * @brief Sobrecarga do operador == para comparar artistas.
 * @param outro Outro artista a ser comparado.
 * @return true se os artistas forem iguais.
 * @return false caso contrário.
 */
bool Artista::operator==(const Artista& outro) const {
  return nome_do_artista == outro.nome_do_artista && idade_do_artista == outro.idade_do_artista;
}