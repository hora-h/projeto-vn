#include "dialogo.hpp"

Fala::Fala(string nome, string mensagem){
    this->nome = nome;
    this->mensagem = mensagem;
}

Fala::Fala(string formato){
    //Nome
    size_t inicio = 1;
    size_t fim = formato.find('>', inicio);
    this->nome = formato.substr(1, fim - inicio);
    
    /*
    //Imagem
    inicio = fim + 2;
    fim = formato.find('>', inicio - 1);
    if(fim != string::npos){
        this->imagem = formato.substr(inicio, fim - inicio);
    }else{
        this->imagem = nullptr;
    }
    */
    
    //Mensagem
    inicio = fim + 2; //2 = >"
    this->mensagem = formato.substr(inicio, formato.length() - inicio - 1);
}

void Fala::mostra(){
    cout << "<" + this->nome + ">" << "\"" + this->mensagem + "\"" << endl;
}
