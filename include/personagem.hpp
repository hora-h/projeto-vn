#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H
#include "basic.hpp"

typedef struct{
	int nivel; // 0 a 5
	int subnivel; //-1 a 1
}Afinidade;

class Personagem{
protected:
	int idade;
	string sala;
	string nome;
	string descricao;
public:
	
};

class Mulher: public Personagem{
protected:
	Afinidade afinidade;
	int tesao;
	float altura;
	string apelido;
	vector<string> interesse;
public:
};

class Jogador: public Personagem{
protected:
	int carisma;
	int sorte;
	vector<Mulher> conhecidos;
public:
};

#endif //_PERSONAGEM_H