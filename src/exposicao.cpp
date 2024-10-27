#include "exposicao.h"

// Define o tipo de arte da exposição
void Exposicao::set_tipo_de_arte(const std::string& tipo) {
    tipo_de_arte = tipo;
}

// Obtém o tipo de arte da exposição
std::string Exposicao::get_tipo_de_arte() const {
    return tipo_de_arte;
}

// Calcula o preço da exposição
double Exposicao::calcula_preco() const {
    return 50.0 + (5.0 * lista_de_artistas.size());
}