# Nome do executável
TARGET = gerenciador_de_eventos

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include

# Compilador e flags
CXX = g++
CXXFLAGS = -I$(SRC_DIR) -std=c++11 -Wall -Wextra

# Arquivos fonte
SOURCES = $(wildcard $(INCLUDE_DIR)/*.cpp)

# Arquivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
    rm -f $(OBJECTS) $(TARGET)

# Regra para executar o programa
run: $(TARGET)
    ./$(TARGET)