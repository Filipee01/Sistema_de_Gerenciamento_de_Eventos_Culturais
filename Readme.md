# Sistema de Gerenciamento de Eventos Culturais

Informações Gerais:

Este projeto implementa um sistema de gerenciamento de eventos culturais em C++, seguindo os requisitos específicos para o gerenciamento de informações sobre artistas e eventos culturais, com a possibilidade de ordenar tanto os artistas quanto os eventos com base em seus atributos.

## Estrutura do Projeto

**src** -> `artista.h, evento.h, exposicao.h, gerenciador_de_eventos.h, show.h`

**include** -> `artista.cpp, evento.cpp, exposicao.cpp, gerenciador_de_eventos.cpp, main.cpp, show.cpp`

**MakeFile**

**Readme.md**

## Como Compilar e Executar

### Usando MinGW (g++)

1. **Compile o projeto**:
   - Abra o terminal (Prompt de Comando ou PowerShell).
   - Navegue até o diretório do seu projeto.
   - Compile todos os arquivos `.cpp` e gere o executável, especificando os diretórios dos arquivos `.h` e `.cpp`:

     ```sh
     g++ -I src -o gerenciador_de_eventos include/*.cpp
     ```

2. **Execute o programa**:
   - Após a compilação bem-sucedida, execute o programa gerado:

     ```sh
     ./gerenciador_de_eventos
     ```

### Usando o Makefile

1. **Compile o projeto**:
   - Abra o terminal (Prompt de Comando ou PowerShell).
   - Navegue até o diretório do seu projeto.
   - Compile o projeto usando o Makefile:

     ```sh
     make
     ```

2. **Execute o programa**:
   - Após a compilação bem-sucedida, execute o programa gerado:

     ```sh
     ./gerenciador_de_eventos
     ```

3. **Limpeza dos arquivos gerados**:
   - Para limpar os arquivos compilados, execute:

     ```sh
     make clean
     ```

## Funcionalidades do Projeto

O programa permite o cadastro e exibição de eventos e artistas. Você pode:

- Adicionar novos eventos (Show ou Exposição).
- Remover eventos existentes.
- Listar todos os eventos cadastrados.
- Adicionar artistas a eventos específicos.
- Remover artistas de eventos específicos.
- Listar todos os artistas de um evento específico.
- Listar eventos juntamente com seus preços calculados.

## Menu de Opções

O programa oferece o seguinte menu de opções:

1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Preços
0. Sair

## Observação

O sistema armazena os dados usando ponteiros para o gerenciamento de recursos de memória de forma segura e eficiente.

Mensagens de criação e destruição dos objetos são exibidas via `cout`.

## Comentários e Estrutura

Fiz comentários no código para facilitar o entendimento, destacando as implementações de encapsulamento, composição, agregação, além do uso de métodos construtores e destrutores.

## Resultado Esperado

Ao executar o programa, as mensagens de criação e destruição dos objetos serão exibidas, mostrando a gestão de memória e a ordem de execução dos destrutores.

### Exemplo de Saída Esperada:

`-----------------------`


Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 1
Tipo de Evento (1-Show, 2-Exposicao): 1
Nome do Evento: Rock in Rio
Idade do Evento: 22
Genero Musical: rock
Evento Rock in Rio criado!

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 4
Nome do Evento: Rock in Rio
Nome do Artista: Iron Maiden
Idade do Artista: 44
Artista Iron Maiden adicionado ao evento Rock in Rio!

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 3
Evento: Rock in Rio, Idade: 22, Genero Musical: rock

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 6
Nome do Evento: Rock in Rio
Artista: Iron Maiden, Idade: 44

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 5
Nome do Evento: Rock in Rio
Nome do Artista a remover: Iron Maiden
Artista Iron Maiden removido do evento Rock in Rio!

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 6
Nome do Evento: Rock in Rio
Nenhum artista cadastrado no evento Rock in Rio.

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 2
Nome do Evento a remover: Rock in Rio
Evento Rock in Rio removido!

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 3
Nenhum evento cadastrado.

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

Escolha uma opcao: 7
Nenhum evento cadastrado.

`-----------------------`

Menu:
1. Adicionar Evento
2. Remover Evento
3. Listar Eventos
4. Adicionar Artista a Evento
5. Remover Artista de Evento
6. Listar Artistas de Evento
7. Listar Eventos com Precos
0. Sair

`-----------------------`

`caso coloque uma idade negativa`

Escolha uma opcao: 1
Tipo de Evento (1-Show, 2-Exposicao): 1
Nome do Evento: Show time
Idade do Evento: -27
Genero Musical: rock
Erro: Idade nao pode ser negativa


## Autor

Luiz Filipe Santos de Souza  
Matrícula: 20230102493