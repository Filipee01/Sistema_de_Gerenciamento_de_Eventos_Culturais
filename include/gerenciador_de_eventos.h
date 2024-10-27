#ifndef GERENCIADOR_DE_EVENTOS_H
#define GERENCIADOR_DE_EVENTOS_H

#include "evento.h"
#include <vector>

// Classe GerenciadorDeEventos
class GerenciadorDeEventos {
private:
    std::vector<Evento*> lista_de_eventos; // Lista de eventos

public:
    void adicionar_evento(Evento* evento); // Adiciona um evento à lista
    void remover_evento(Evento* evento); // Remove um evento da lista
    void ordenar_eventos(); // Ordena a lista de eventos pela idade
    void listar_eventos() const; // Lista todos os eventos
    std::vector<Evento*>& get_lista_de_eventos(); // Obtém a lista de eventos
};

#endif // GERENCIADOR_DE_EVENTOS_H