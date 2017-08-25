#ifndef _DIALOGO_H
#define _DIALOGO_H

#include <fstream>
#include "personagem.hpp"
#include "cena.hpp"
#include "utils/utils.hpp"

class Fala {
    protected:
        string nome;
        string mensagem;
        string bg;
		string fg;
    public:
        Fala(string nome, string mensagem);
        Fala(string formato);
        void mostra();
};

/*class Escolha : public Fala {
protected:
    vector<string> opcoes;
    vector<string> flags_que_ativa;
};*/

class Secao {
	public:
		string nome;
		vector<Fala> falas;
		Secao *proxima;
	public:
		Secao(string nome);
		string get_nome();
		void insere_fala(const Fala& fala);
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