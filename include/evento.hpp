#ifndef _EVENTO_H
#define _EVENTO_H

#include "dialogo.hpp"

class Evento{
protected:
	string nome;
	vector<string> flags_que_ativa;
	vector<string> flags_que_depende;
	Data data;
	vector<Cena> cenas;
};

