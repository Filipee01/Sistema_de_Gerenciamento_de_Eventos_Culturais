#include "gerenciador_de_eventos.h"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief Adiciona um evento à lista.
 * @param evento Evento a ser adicionado.
 */
void GerenciadorDeEventos::adicionar_evento(Evento *evento) {
  lista_de_eventos.push_back(evento);
  ordenar_eventos();
}

/**
 * @brief Remove um evento da lista.
 * @param evento Evento a ser removido.
 */
void GerenciadorDeEventos::remover_evento(Evento *evento) {
  lista_de_eventos.erase(
      std::remove(lista_de_eventos.begin(), lista_de_eventos.end(), evento),
      lista_de_eventos.end());
}

/**
 * @brief Ordena a lista de eventos pela idade.
 */
void GerenciadorDeEventos::ordenar_eventos() {
  std::sort(lista_de_eventos.begin(), lista_de_eventos.end(),
            [](Evento *a, Evento *b) { return *a < *b; });
}

/**
 * @brief Lista todos os eventos.
 */
void GerenciadorDeEventos::listar_eventos() const {
  for (const auto &evento : lista_de_eventos) {
    cout << "Evento: " << evento->get_nome()
         << ", Idade: " << evento->get_idade() << endl;
  }
}

/**
 * @brief Obtém a lista de eventos.
 * @return Lista de eventos.
 */
std::vector<Evento *> &GerenciadorDeEventos::get_lista_de_eventos() {
  return lista_de_eventos;
}

/**
 * @brief Sobrecarga do operador + para adicionar um evento à lista.
 * @param evento Evento a ser adicionado.
 */
void GerenciadorDeEventos::operator+(Evento *evento) {
  adicionar_evento(evento);
}

/**
 * @brief Sobrecarga do operador - para remover um evento da lista.
 * @param evento Evento a ser removido.
 */
void GerenciadorDeEventos::operator-(Evento *evento) {
  remover_evento(evento);
}