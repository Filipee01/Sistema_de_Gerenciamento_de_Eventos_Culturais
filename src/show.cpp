#include "show.h"

// Define o gênero musical do show
void Show::set_genero_musical(const std::string& genero) {
    genero_musical = genero;
}

// Obtém o gênero musical do show
std::string Show::get_genero_musical() const {
    return genero_musical;
}

// Calcula o preço do show
double Show::calcula_preco() const {
    return 100.0 + (10.0 * lista_de_artistas.size());
}