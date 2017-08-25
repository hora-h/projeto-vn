#include "personagem.hpp"
#include "dialogo.hpp"

Flag flag_list;

int main(){
	Dialogo *d = new Dialogo("Resources/modelos/cena.txt");
	
	for(auto it = d->secoes.begin(); it != d->secoes.end(); it++){
		string secao = it->first;
		cout << "---=== SEÇÃO " + secao + " ===---\n";
		for(long long unsigned int i = 0; i<it->second->falas.size(); i++){
			it->second->falas[i].mostra();
		}
		cout << "----------------------\n\n";
	}
	
    return 0;
}