#include "gerenciador_de_eventos.h"
#include "show.h"
#include "exposicao.h"
#include <iostream>

int main() {
    GerenciadorDeEventos gerenciador; // Instancia o gerenciador de eventos
    int opcao; // Variável para armazenar a opção do menu

    do {
        // Exibe o menu interativo
        std::cout << "Menu:\n";
        std::cout << "1. Adicionar Evento\n";
        std::cout << "2. Remover Evento\n";
        std::cout << "3. Listar Eventos\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                int tipo_evento;
                std::cout << "Tipo de Evento (1-Show, 2-Exposicao): ";
                std::cin >> tipo_evento;

                Evento* evento = nullptr;
                if (tipo_evento == 1) {
                    evento = new Show();
                } else if (tipo_evento == 2) {
                    evento = new Exposicao();
                }

                if (evento) {
                    std::string nome;
                    int idade;
                    std::cout << "Nome do Evento: ";
                    std::cin >> nome;
                    std::cout << "Idade do Evento: ";
                    std::cin >> idade;

                    evento->set_nome(nome);
                    evento->set_idade(idade);

                    gerenciador.adicionar_evento(evento);
                }
                break;
            }
            case 2: {
                std::string nome;
                std::cout << "Nome do Evento a remover: ";
                std::cin >> nome;

                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                for (auto& evento : lista_de_eventos) {
                    if (evento->get_nome() == nome) {
                        gerenciador.remover_evento(evento);
                        delete evento;
                        break;
                    }
                }
                break;
            }
            case 3:
                gerenciador.listar_eventos();
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}