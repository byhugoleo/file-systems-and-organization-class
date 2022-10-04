#pragma once

#include <iostream>

using namespace std;

class Buffer {
    char delimiter;     // delimitador usado no arquivo de dados
    string data;    // vetor de dados do buffer
    int nextDataPosition;  // endereco do próximo campo a ser lido ou incluído no buffer
    int size;  // tamanho do buffer ( incluindo os delimitadores)
    int maxSize;

public:
    Buffer(char delimiter = '|', int maxSize = 1024);

    void init(char delimiter, int maxSize = 1024);  // inicializa o buffer definindo o
                                            // delimitador e o tamanho maximo
    void clear();  // limpa o buffer

    bool pack(const string str);  // modifica o próximo campo do buffer
    string unpack();  // lê o próximo campo do buffer de forma circular

    void Print() const;  // exibe na saida padrão os dados do buffer (tam_max e
                         // tamanho atual)
    int getSize() const;    // retorna o tamanho atual do buffer
    bool read(istream &in);  // lê os dados de um arquivo binário no formato
                             // correto ("tamanho do registro"+"registros
                             // separados por delimitador")
    bool write(ostream &out) const;  // escreve os dados em uma arquivo binário
};