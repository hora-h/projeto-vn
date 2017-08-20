#include "personagem.hpp"
#include "dialogo.hpp"

Flag flag_list;

int main(){
	Fala *f1 = new Fala("<Moreira><ofodao.jpeg>\"Eu cheguei aqui ontem.\"");
    printf("\n");
    Fala *f2 = new Fala("<Paulo>\"Outra falar na a ver.\"");
    
    f1->mostra();
    f2->mostra();
    return 0;
}