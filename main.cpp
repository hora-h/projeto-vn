#include "personagem.hpp"
#include "dialogo.hpp"

Flag flag_list;

int main(){
	Dialogo *d = new Dialogo("Resources/modelos/cena.txt");
	d->secoes["Main"]->falas[1].mostra();
    return 0;
}