#include <iostream>
#include <string>


class Artista {
    string nome_do_artista;
    int idade_do_artista;
public:
    Artista(const string& n, int i) : nome_do_artista(n), idade_do_artista(i) {}

string get_nome() const {
    return nome_do_artista;
}

void set_nome(const string& n) {
    nome_do_artista = n;
}
int get_idade() const {
    return idade_do_artista;
}

void set_idade(int i) {
    idade_do_artista = i;
}

}

class Evento {
    string nome_do_evento;
    int idade_do_evento;
    vector<Artista> lista_de_artistas;
public:
    Evento(const string& n, int i, const vector<Artista>& a) : nome_do_evento(n), idade_do_evento(i), lista_de_artistas(a) {}
 
 string get_nome() const {
     return nome_do_evento;
 }

 void set_nome(const string& n) {
     nome_do_evento = n;
 }

 int get_idade() const {
    return idade_do_evento;
 }

 void set_idade(const string& i) {
        idade_do_evento = i;
 }

vector<Artista> get_artistas() const {
        return lista_de_artistas;
    }

virtual double calcula_preco() const = 0;

}

class show : public Evento {
    string genero_musical;
    string tipo_de_arte;
public:
    show(const string& g, const string& t) : genero_musical(g), tipo_de_arte(t) {}

    void calcula_preco() const override {
        return
    }

}

class exposicao : public Evento {
    string tipo_de_arte;
public:
    exposicao(const string& t) : tipo_de_arte(t) {}

    void calcula_preco() const override {

    }
}

class gerenciador_de_eventos {
    vector<evento*> lista_de_eventos;
public:
    gerenciador_de_eventos(const vector<evento>& e) : lista_de_eventos(e) {}

void adicionar_evento(evento* e) {
    lista_de_eventos.push_back(e);
}

void remover_evento(evento* e) {
    lista_de_eventos.erase(std::remove(lista_de_eventos.begin(), lista_de_eventos.end(), e), lista_de_eventos.end());
}

void ordenar_eventos() {
    std::sort(lista_de_eventos.begin(), lista_de_eventos.end(), [](evento* a, evento* b) {
        return *a < *b;
    });



}




int main() {


    return 0;
}