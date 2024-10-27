#ifndef EXPOSICAO_H
#define EXPOSICAO_H

#include "evento.h"

// Classe Exposicao derivada de Evento
class Exposicao : public Evento {
private:
    std::string tipo_de_arte; // Tipo de arte da exposição

public:
    void set_tipo_de_arte(const std::string& tipo); // Define o tipo de arte da exposição
    std::string get_tipo_de_arte() const; // Obtém o tipo de arte da exposição

    double calcula_preco() const override; // Calcula o preço da exposição
};

#endif // EXPOSICAO_H