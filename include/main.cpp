#include "gerenciador_de_eventos.h"
#include "show.h"
#include "exposicao.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::invalid_argument;

/**
 * @brief Função principal que implementa o menu interativo para gerenciar eventos culturais.
 * @return int Código de saída do programa.
 */
int main() {
    try {
        GerenciadorDeEventos gerenciador; ///< Instancia o gerenciador de eventos
        int opcao; ///< Variável para armazenar a opção do menu

        do {
            // Exibe o menu interativo
            cout << "-----------------------\n";
            cout << "Menu:\n";
            cout << "1. Adicionar Evento\n";
            cout << "2. Remover Evento\n";
            cout << "3. Listar Eventos\n";
            cout << "4. Adicionar Artista a Evento\n";
            cout << "5. Remover Artista de Evento\n";
            cout << "6. Listar Artistas de Evento\n";
            cout << "7. Listar Eventos com Precos\n"; 
            cout << "0. Sair\n";
            cout << "-----------------------\n";
            cout << "Escolha uma opcao: ";
            cin >> opcao;
            cin.ignore(); ///< Ignora o caractere de nova linha deixado no buffer

            switch (opcao) {
                case 1: {
                    ///< Adicionar Evento
                    int tipo_evento;
                    cout << "Tipo de Evento (1-Show, 2-Exposicao): ";
                    cin >> tipo_evento;
                    cin.ignore(); 

                    Evento* evento = nullptr;
                    string nome;
                    int idade;
                    cout << "Nome do Evento: ";
                    getline(cin, nome);
                    cout << "Idade do Evento: ";
                    cin >> idade;
                    cin.ignore(); 

                    if (idade < 0) {
                        throw invalid_argument("Idade nao pode ser negativa");
                    }

                    if (tipo_evento == 1) {
                        string genero_musical;
                        cout << "Genero Musical: ";
                        getline(cin, genero_musical);
                        evento = new Show(nome, idade, genero_musical);
                    } else if (tipo_evento == 2) {
                        string tipo_de_arte;
                        cout << "Tipo de Arte: ";
                        getline(cin, tipo_de_arte);
                        evento = new Exposicao(nome, idade, tipo_de_arte);
                    } else {
                        throw invalid_argument("Tipo de evento invalido!");
                    }

                    if (evento) {
                        gerenciador.adicionar_evento(evento);
                        cout << "Evento " << nome << " criado!" << endl;
                    }
                    break;
                }
                case 2: {
                    ///< Remover Evento
                    string nome;
                    cout << "Nome do Evento a remover: ";
                    getline(cin, nome);

                    auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                    auto it = std::find_if(lista_de_eventos.begin(), lista_de_eventos.end(),
                                           [&nome](Evento* evento) { return evento->get_nome() == nome; });

                    if (it != lista_de_eventos.end()) {
                        delete *it; // Libera a memória do evento
                        lista_de_eventos.erase(it); // Remove o evento da lista
                        cout << "Evento " << nome << " removido!" << endl;
                    } else {
                        throw invalid_argument("Evento nao encontrado!");
                    }
                    break;
                }
                case 3: {
                    ///< Listar Eventos
                    auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                    if (lista_de_eventos.empty()) {
                        cout << "Nenhum evento cadastrado." << endl;
                    } else {
                        for (const auto& evento : lista_de_eventos) {
                            cout << "Evento: " << evento->get_nome()
                                 << ", Idade: " << evento->get_idade();
                            if (auto show = dynamic_cast<Show*>(evento)) {
                                cout << ", Genero Musical: " << show->get_genero_musical();
                            } else if (auto exposicao = dynamic_cast<Exposicao*>(evento)) {
                                cout << ", Tipo de Arte: " << exposicao->get_tipo_de_arte();
                            }
                            cout << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    ///< Adicionar Artista a Evento
                    string nome_evento;
                    cout << "Nome do Evento: ";
                    getline(cin, nome_evento);

                    auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                    bool evento_encontrado = false;
                    for (auto& evento : lista_de_eventos) {
                        if (evento->get_nome() == nome_evento) {
                            string nome_artista;
                            int idade_artista;
                            cout << "Nome do Artista: ";
                            getline(cin, nome_artista);
                            cout << "Idade do Artista: ";
                            cin >> idade_artista;
                            cin.ignore(); 

                            Artista artista;
                            artista.set_nome(nome_artista);
                            artista.set_idade(idade_artista);

                            *evento + artista;
                            cout << "Artista " << nome_artista << " adicionado ao evento " << nome_evento << "!" << endl;
                            evento_encontrado = true;
                            break;
                        }
                    }
                    if (!evento_encontrado) {
                        throw invalid_argument("Evento nao encontrado!");
                    }
                    break;
                }
                case 5: {
                    ///< Remover Artista de Evento
                    string nome_evento;
                    cout << "Nome do Evento: ";
                    getline(cin, nome_evento);

                    auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                    bool evento_encontrado = false;
                    for (auto& evento : lista_de_eventos) {
                        if (evento->get_nome() == nome_evento) {
                            string nome_artista;
                            cout << "Nome do Artista a remover: ";
                            getline(cin, nome_artista);

                            auto& lista_de_artistas = evento->get_artistas();
                            bool artista_removido = false;
                            for (auto it = lista_de_artistas.begin(); it != lista_de_artistas.end(); ++it) {
                                if (it->get_nome() == nome_artista) {
                                    *evento - *it;
                                    cout << "Artista " << nome_artista << " removido do evento " << nome_evento << "!" << endl;
                                    artista_removido = true;
                                    break;
                                }
                            }
                            if (!artista_removido) {
                                throw invalid_argument("Artista nao encontrado no evento!");
                            }
                            evento_encontrado = true;
                            break;
                        }
                    }
                    if (!evento_encontrado) {
                        throw invalid_argument("Evento nao encontrado!");
                    }
                    break;
                }
                case 6: {
                    ///< Listar Artistas de Evento
                    string nome_evento;
                    cout << "Nome do Evento: ";
                    getline(cin, nome_evento);

                    auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                    bool evento_encontrado = false;
                    for (auto& evento : lista_de_eventos) {
                        if (evento->get_nome() == nome_evento) {
                            const auto& lista_de_artistas = evento->get_artistas();
                            if (lista_de_artistas.empty()) {
                                cout << "Nenhum artista cadastrado no evento " << nome_evento << "." << endl;
                            } else {
                                for (const auto& artista : lista_de_artistas) {
                                    cout << "Artista: " << artista.get_nome() << ", Idade: " << artista.get_idade() << endl;
                                }
                            }
                            evento_encontrado = true;
                            break;
                        }
                    }
                    if (!evento_encontrado) {
                        throw invalid_argument("Evento nao encontrado!");
                    }
                    break;
                }
                case 7: { 
                    ///< Listar Eventos com Preços
                    auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                    if (lista_de_eventos.empty()) {
                        cout << "Nenhum evento cadastrado." << endl;
                    } else {
                        for (const auto& evento : lista_de_eventos) {
                            cout << "Evento: " << evento->get_nome()
                                 << ", Idade: " << evento->get_idade()
                                 << ", Preco: " << evento->calcula_preco();
                            if (auto show = dynamic_cast<Show*>(evento)) {
                                cout << ", Genero Musical: " << show->get_genero_musical();
                            } else if (auto exposicao = dynamic_cast<Exposicao*>(evento)) {
                                cout << ", Tipo de Arte: " << exposicao->get_tipo_de_arte();
                            }
                            cout << endl;
                        }
                    }
                    break;
                }
                case 0:
                    ///< Sair
                    cout << "Saindo...\n";
                    break;
                default:
                    ///< Opção Inválida
                    throw invalid_argument("Opcao invalida!");
            }
        } while (opcao != 0);
    } catch (const std::exception& e) {
        cout << "Erro: " << e.what() << endl;
    }

    return 0;
}