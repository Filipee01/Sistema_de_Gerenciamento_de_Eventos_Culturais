#include "gerenciador_de_eventos.h"
#include "show.h"
#include "exposicao.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

/**
 * @brief Função principal que implementa o menu interativo para gerenciar eventos culturais.
 * @return int Código de saída do programa.
 */
int main() {
    GerenciadorDeEventos gerenciador; // Instancia o gerenciador de eventos
    int opcao; // Variável para armazenar a opção do menu

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
        cin.ignore(); // Ignora o caractere de nova linha deixado no buffer

        switch (opcao) {
            case 1: {
                int tipo_evento;
                cout << "Tipo de Evento (1-Show, 2-Exposicao): ";
                cin >> tipo_evento;
                cin.ignore(); 

                Evento* evento = nullptr;
                if (tipo_evento == 1) {
                    evento = new Show();
                    string genero_musical;
                    cout << "Genero Musical: ";
                    getline(cin, genero_musical);
                    dynamic_cast<Show*>(evento)->set_genero_musical(genero_musical);
                } else if (tipo_evento == 2) {
                    evento = new Exposicao();
                    string tipo_de_arte;
                    cout << "Tipo de Arte: ";
                    getline(cin, tipo_de_arte);
                    dynamic_cast<Exposicao*>(evento)->set_tipo_de_arte(tipo_de_arte);
                }

                if (evento) {
                    string nome;
                    int idade;
                    cout << "Nome do Evento: ";
                    getline(cin, nome);
                    cout << "Idade do Evento: ";
                    cin >> idade;
                    cin.ignore(); 

                    evento->set_nome(nome);
                    evento->set_idade(idade);

                    gerenciador.adicionar_evento(evento);
                }
                break;
            }
            case 2: {
                string nome;
                cout << "Nome do Evento a remover: ";
                getline(cin, nome);

                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                for (auto it = lista_de_eventos.begin(); it != lista_de_eventos.end(); ++it) {
                    if ((*it)->get_nome() == nome) {
                        gerenciador.remover_evento(*it);
                        delete *it;
                        break;
                    }
                }
                break;
            }
            case 3: {
                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
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
                break;
            }
            case 4: {
                string nome_evento;
                cout << "Nome do Evento: ";
                getline(cin, nome_evento);

                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
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
                        break;
                    }
                }
                break;
            }
            case 5: {
                string nome_evento;
                cout << "Nome do Evento: ";
                getline(cin, nome_evento);

                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                for (auto& evento : lista_de_eventos) {
                    if (evento->get_nome() == nome_evento) {
                        string nome_artista;
                        cout << "Nome do Artista a remover: ";
                        getline(cin, nome_artista);

                        auto& lista_de_artistas = evento->get_artistas();
                        for (auto it = lista_de_artistas.begin(); it != lista_de_artistas.end(); ++it) {
                            if (it->get_nome() == nome_artista) {
                                *evento - *it;
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 6: {
                string nome_evento;
                cout << "Nome do Evento: ";
                getline(cin, nome_evento);

                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
                for (auto& evento : lista_de_eventos) {
                    if (evento->get_nome() == nome_evento) {
                        const auto& lista_de_artistas = evento->get_artistas();
                        for (const auto& artista : lista_de_artistas) {
                            cout << "Artista: " << artista.get_nome() << ", Idade: " << artista.get_idade() << endl;
                        }
                        break;
                    }
                }
                break;
            }
            case 7: { 
                auto& lista_de_eventos = gerenciador.get_lista_de_eventos();
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
                break;
            }
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}