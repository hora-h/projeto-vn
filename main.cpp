#include "personagem.hpp"
#include "dialogo.hpp"

Secao* exibe_escolhas(Dialogo *dialogo, Escolha *escolha){
	int i = 0, escolhido;
	while(true){
		for(auto opcoes: escolha->opcoes){
			i++;
			cout << "\t" << i << ")" << opcoes.texto << endl;
		}
		cin >> escolhido;
		if(escolhido <= 0 || escolhido > escolha->opcoes.size()){
			cout << "Escolha nao valida!" << endl;
			i=0;
		}else{
			break;
		}
	}
	string secao = escolha->opcoes[escolhido-1].secao;
	cout << "Secao exbEsc:" + dialogo->secoes[secao]->get_nome() << endl;
	if(secao.empty()){
		return NULL;
	}
	return dialogo->secoes[secao];
}

void pega_escolha(Dialogo *dialogo){
	for(auto fala: dialogo->atual->falas){
		if(instanceof(Escolha*,fala)){
			auto secao = exibe_escolhas(dialogo,((Escolha*)fala));
			cout <<"pega_escolha: " + secao->get_nome() << endl;
			if(secao == NULL){
				continue;
			}else{
				dialogo->atual = secao;
				return;
			}
		}
		cout << "\t" << fala->nome << ": " << fala->mensagem << endl;
	}
	dialogo->atual = dialogo->secoes[dialogo->atual->proxima];
}

int main(){
	Dialogo *cena = new Dialogo("Resources/modelos/cena.txt");
	/**/
	while(true){
		//cout << ptr->nome << endl; <- Nome da sessão
		pega_escolha(cena);
		/*if((cena->atual->get_proxima().empty() || 
		cena->atual->get_proxima() == "EXIT")){
			break;
		}*/
	}/**/
	return 0;
}