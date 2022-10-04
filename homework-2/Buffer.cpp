#include "Buffer.hpp"
#include <assert.h>
#include <string.h> // biblioteca da linguagem C para manipulação de vetores de char

Buffer::Buffer(char delimiter, int maxSize) {
    Buffer::init(delimiter, maxSize);
}

void Buffer::init(char delimiter, int maxSize) {
    assert(size > 0); // o tamanho deve ser maior que 0
    this->maxSize = maxSize;

    assert(delimiter != 0);   // o delimitador não pode ser vazio
    this->delimiter = delimiter;

    this->size = 0;
    this->nextDataPosition = 0;
}

int Buffer::getSize() const {
    return this->size;
}

void Buffer::clear() {
    this->nextDataPosition = 0;
    this->size = 0;
}


// void Buffer::Print(  ) const 
// // exibe na saída padrão os dados do buffer (tam_max e tamanho atual)
// {
//     if ( tam_dados > 0 )
//     {
//         char * aux = new char[tam_dados+1];
//         strncpy(aux, dados, tam_dados);
//         aux[tam_dados] = '\0';
//         cout << "DADOS: '" << aux <<"'\n";
//         delete []aux;
//     }
//     else
//         cout << "DADOS: <VAZIO>\n";

//     cout<<   " TAMANHO ATUAL DO BUFFER: " << tam_dados
//         << "\nTAMANHO MAXIMO DO BUFFER: " << TAM_MAX << endl;
// }


bool Buffer::read(istream &in) {
    clear();
	in.read((char*)this->data.c_str(), size);
	return in.good();
}

bool Buffer::write(ostream &out) const {
    out.write(this->data.c_str(), size);
    return out.good();
}

bool Buffer::pack(const string str) {
    int strSize = (int)str.size();
    this->nextDataPosition += strSize + 1;
    if (this->nextDataPosition > this->maxSize) {
        return false;
    }
    data += str + delimiter;
    this->size = this->nextDataPosition;
    return true;
}

string Buffer::unpack() {
    size_t idx = data.find_first_of('|', this->nextDataPosition);
    if (idx == string::npos) {
        return (string)NULL;
    }
    idx -= this->nextDataPosition;
    string str = data.substr(this->nextDataPosition, idx);
    this->nextDataPosition += idx + 1;
    if (this->nextDataPosition > maxSize) {
        return (string)NULL;
    }
    return str;
}
