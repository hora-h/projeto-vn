#ifndef _BASIC_H
#define _BASIC_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * Flags do jogo. Composta por uma string identificadora e um bool que indica se
 * está ativa.
 */
#define Flag map<string,bool>

extern Flag flag_list;

typedef enum Horario{
	MANHA, TARDE, NOITE
}Horario;

typedef struct{
	int dia;
	int mes;
	int ano;
	Horario horario;
}Data;

#endif //_BASIC_H