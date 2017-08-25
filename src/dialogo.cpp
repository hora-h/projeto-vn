#include "dialogo.hpp"

Fala::Fala(string nome, string mensagem){
    this->nome = nome;
    this->mensagem = mensagem;
}

Fala::Fala(string formato){
    //Nome
    size_t fim;
    tie(this->nome, fim) = find_inside(formato, '<', '>', 0);
    
    //Imagens
	tie(this->bg, fim) = find_inside(formato, '<', ';', fim);
	tie(this->fg, fim) = find_inside(formato, ';', '>', fim);
    
    //Mensagem
	tie(this->mensagem, fim) = find_inside(formato, '"', '"', fim);
}

void Fala::mostra(){
	string out;
	out = "nome: " + this->nome + "\n" +
		  "bg: " + this->bg + "\n" + 
		  "fg: " + this->fg + "\n" + 
		  "fala: " + this->mensagem + "\n";
    cout << out;
}

Secao::Secao(string nome){
	this->nome = nome;
}

string Secao::get_nome(){
	return this->nome;
}

void Secao::insere_fala(const Fala& fala){
	this->falas.push_back(fala);
}

Dialogo::Dialogo(const char *arquivo){
    ifstream in(arquivo);
    
    if(!in){
        throw ("Unable to open dialog file.");
    }
    
    string nome;
    getline(in, nome);
    
    string full_line, line;
    while(getline(in, full_line)){
        if(full_line.length() > 1){
            line = full_line.substr(1);
            switch(full_line[0]){
                case '@':
                    //this->secoes[this->atual->get_nome()]->insere_fala(Fala(line));
					this->atual->insere_fala(Fala(line));
                    break;
                case '?':
                    if(line == "BEGIN"){
                        //cout << "Pergunta inicio\n";
                    }else if(line == "END"){
                        //cout << "Pergunta fim\n";
                    }
                    break;
				case '>':
					//this->atual->link()
					break;
                case '#':
					this->atual = new Secao(line);
					this->secoes[line] = this->atual;
                    break;
                case '$':
                    //cout << "variável: " + line << endl;
                    break;
                default:
                    //cout << "INVALIDO: " + line << endl;
                    break;
            }
        }
    }
    
}
