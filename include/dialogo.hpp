#ifndef _DIALOGO_H
#define _DIALOGO_H

#include <stdio.h>
#include "personagem.hpp"
#include "cena.hpp"

class Fala {
    protected:
        string nome;
        string mensagem;
        //TODO - info_gui
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

class Dialogo : public Cena {
protected:
    vector<Fala> falas;
    vector<string> flags_que_ativa;
    vector<string> flags_que_depende;
    //TODO - info_gui
};

#endif //_DIALOGO_H