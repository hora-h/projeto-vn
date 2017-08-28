#include "personagem.hpp"
#include "dialogo.hpp"

Flag flag_list;

/*inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}*/

int main(){
	int escolhido;
	Dialogo *d = new Dialogo("Resources/modelos/cena.txt");
	Secao *ptr = d->atual;
	gambi:
	while(!ptr->get_proxima().empty()){
		for(auto it: d->secoes[ptr->get_nome()]->falas){
			//cout << typeid(it).name() << endl;
			if(dynamic_cast<const Escolha*>(it) != nullptr){
				int i = 0;
				printf("Escolha sensata!:\n");
				for(auto opcao: ((Escolha*)it)->opcoes){
					i++;
					cout << i << ") " + opcao.texto << endl;
				}
				cin >> escolhido;
				if(escolhido <= 0 || escolhido > ((Escolha*)it)->opcoes.size()){
					throw "Opcao nao valida!\n";
				}
				
				d->atual = d->secoes[((Escolha*)it)->opcoes[escolhido-1].secao];
				ptr = d->atual;
				goto gambi;
				//break;
			}
			cout << it->nome + ": " + it->mensagem << endl;
		}
		ptr = d->secoes[d->atual->proxima];
	}

    return 0;
}

/*
	Dialogo *d = new Dialogo("Resources/modelos/cena.txt");
	
	for(auto it = d->secoes.begin(); it != d->secoes.end(); it++){
		string secao = it->first;
		cout << "---=== SEÇÃO " + secao + " ===---\n";
		for(long long unsigned int i = 0; i<it->second->falas.size(); i++){
			cout << it->second->falas[i]->mostra();
		}
		cout << "Proxima: " + it->second->proxima << endl;
		cout << "----------------------\n\n";
	}
*/