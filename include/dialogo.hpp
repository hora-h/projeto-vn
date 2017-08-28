#ifndef _DIALOGO_H
#define _DIALOGO_H

#include <memory>
#include <fstream>
#include "personagem.hpp"
#include "cena.hpp"
#include "utils/utils.hpp"

class Fala {
    public:
        string nome;
        string mensagem;
        string bg;
		string fg;
    public:
		Fala();
        Fala(string nome, string mensagem);
        Fala(string formato);
        virtual string mostra();
};

class Opcao{
	protected:
		string texto;
		vector<string> flags_que_depende;
		vector<string> flags_que_ativa;
		string secao;
	public:
		Opcao(string formato);
		string mostra();
};

class Escolha : public Fala {
	protected:
		vector<Opcao> opcoes;
	public:
		Escolha();
		void add_opcao(const Opcao& opcao);
		string mostra();
};

class Secao {
	public:
		string nome;
		vector<unique_ptr<Fala>> falas;
		Secao *proxima;
	public:
		Secao(string nome);
		string get_nome();
		void insere_fala(unique_ptr<Fala> fala);
		void link(Secao *proxima);
};

class Dialogo : public Cena {
	public:
		Secao *atual;
		map<string, Secao *> secoes;
		vector<string> flags_que_ativa;
		vector<string> flags_que_depende;
		//TODO - info_gui
	public:
		Dialogo(const char *arquivo);
};

#endif //_DIALOGO_H