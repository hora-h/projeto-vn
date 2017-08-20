#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

#include "basic.hpp"

typedef struct{
	int nivel; // 0 a 5
	int subnivel; //-1 a 1
}Afinidade;

class Personagem{
protected:
    string nome;
    string apelido;
    int idade;
    string sala;
    string descricao;
public:
	
};

class Mulher: public Personagem{
protected:
    vector<string> interesses;
	Afinidade afinidade;
	int tesao;
public:
};

class Jogador: public Personagem{
protected:
    vector<Mulher> relacoes;
	int carisma;
	int sorte;
public:
};

#endif //_PERSONAGEM_H