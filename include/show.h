#ifndef SHOW_H
#define SHOW_H

#include "evento.h"

// Classe Show derivada de Evento
class Show : public Evento {
private:
    std::string genero_musical; // Gênero musical do show

public:
    void set_genero_musical(const std::string& genero); // Define o gênero musical do show
    std::string get_genero_musical() const; // Obtém o gênero musical do show

    double calcula_preco() const override; // Calcula o preço do show
};

#endif // SHOW_H