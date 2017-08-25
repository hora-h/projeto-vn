#ifndef EVENTO_H
#define EVENTO_H

#include "dialogo.hpp"

class Evento{
protected:
	string nome;
	vector<string> flags_que_ativa;
	vector<string> flags_que_depende;
	Data data;
	vector<Cena> cenas;
};

#endif //EVENTO.H
