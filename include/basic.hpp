#ifndef _BASIC_H
#define _BASIC_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

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