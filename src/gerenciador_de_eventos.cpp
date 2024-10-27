#include "gerenciador_de_eventos.h"
#include <algorithm>
#include <iostream>

// Adiciona um evento à lista
void GerenciadorDeEventos::adicionar_evento(Evento* evento) {
    lista_de_eventos.push_back(evento);
    ordenar_eventos();
}

// Remove um evento da lista
void GerenciadorDeEventos::remover_evento(Evento* evento) {
    lista_de_eventos.erase(std::remove(lista_de_eventos.begin(), lista_de_eventos.end(), evento), lista_de_eventos.end());
}

// Ordena a lista de eventos pela idade
void GerenciadorDeEventos::ordenar_eventos() {
    std::sort(lista_de_eventos.begin(), lista_de_eventos.end(), [](Evento* a, Evento* b) {
        return *a < *b;
    });
}

// Lista todos os eventos
void GerenciadorDeEventos::listar_eventos() const {
    for (const auto& evento : lista_de_eventos) {
        std::cout << "Evento: " << evento->get_nome() << ", Idade: " << evento->get_idade() << std::endl;
    }
}

// Obtém a lista de eventos
std::vector<Evento*>& GerenciadorDeEventos::get_lista_de_eventos() {
    return lista_de_eventos;
}