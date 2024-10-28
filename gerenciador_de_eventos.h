#ifndef GERENCIADOR_DE_EVENTOS_H
#define GERENCIADOR_DE_EVENTOS_H

#include "evento.h"
#include <vector>


/**
 * @class GerenciadorDeEventos
 * @brief Classe que gerencia uma lista de eventos culturais.
 */
class GerenciadorDeEventos {
private:
  std::vector<Evento *> lista_de_eventos; ///< Lista de eventos

public:
  /**
   * @brief Adiciona um evento à lista.
   * @param evento Evento a ser adicionado.
   */
  void adicionar_evento(Evento *evento);

  /**
   * @brief Remove um evento da lista.
   * @param evento Evento a ser removido.
   */
  void remover_evento(Evento *evento);

  /**
   * @brief Ordena a lista de eventos pela idade.
   */
  void ordenar_eventos();

  /**
   * @brief Lista todos os eventos.
   */
  void listar_eventos() const;

  /**
   * @brief Obtém a lista de eventos.
   * @return Lista de eventos.
   */
  std::vector<Evento *> &get_lista_de_eventos();
};

#endif // GERENCIADOR_DE_EVENTOS_H