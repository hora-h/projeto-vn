#ifndef _LOCAL_H
#define _LOCAL_H
#include "evento.hpp"

class Local{
protected:
	string nome;
	vector<Evento> eventos;
	//TODO - info_gui
};

class Mapa{
protected:
	vector<Local> local;
};


#endif //_LOCAL_H