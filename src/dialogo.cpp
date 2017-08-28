#include "dialogo.hpp"

Fala::Fala(){}

Fala::Fala(string nome, string mensagem){
    this->nome = nome;
    this->mensagem = mensagem;
}

Fala::Fala(string formato){
    //Nome
    size_t fim;
    this->nome = find_inside(formato, '<', '>', 0, &fim);
    
    //Imagens
	this->bg = find_inside(formato, '<', ';', fim, &fim);
	this->fg = find_inside(formato, ';', '>', fim, &fim);
    
    //Mensagem
	this->mensagem = find_inside(formato, '"', '"', fim, nullptr);
}

string Fala::mostra(){
	string out;
	out = "FALA\n"
		  "nome: " + this->nome + "\n" +
		  "bg: " + this->bg + "\n" + 
		  "fg: " + this->fg + "\n" + 
		  "fala: " + this->mensagem + "\n";
    return out;
}

Opcao::Opcao(string formato){
	string::size_type inicio = 0;
	this->flags_que_depende = split(find_inside(formato, '<', '>', inicio, &inicio), ';');
	this->texto = find_inside(formato, '"', '"', inicio, &inicio);
	this->flags_que_ativa = split(find_inside(formato, '<', '>', inicio, &inicio), ';');
	this->secao = find_inside(formato, '<', '>', inicio, &inicio);
}

string Opcao::mostra(){
	string out;
	out = "OPÇÃO: " + this->texto + "\nfD:\n";
	for(string f: this->flags_que_depende){
		out += "  (" + f + ");";
	}
	out += "\nfA:\n";
	for(string f: this->flags_que_ativa){
		out += "  " + f + ";";
	}
	out+= "\nsecao: " + this->secao + "\n";
    return out;
}

Escolha::Escolha(){
}

void Escolha::add_opcao(const Opcao& opcao){
	this->opcoes.push_back(opcao);
}

string Escolha::mostra(){
	string out = "ESCOLHA:\n";
	for(auto o: this->opcoes){
		out += o.mostra();
	}
	return out;
}

Secao::Secao(string nome){
	this->nome = nome;
}

string Secao::get_nome(){
	return this->nome;
}

void Secao::insere_fala(Fala* fala){
	this->falas.emplace_back(fala);
}

void Secao::link(string proxima){
	this->proxima = proxima;
}

string Secao::get_proxima(){
	return this->proxima;
}

Dialogo::Dialogo(const char *arquivo){
	
	this->atual = nullptr;
	
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
			//cout << line << endl;
            switch(full_line[0]){
                case '@':
					this->atual->insere_fala(new Fala(line));
                    break;
                case '?':
                    if(line == "BEGIN"){
						Escolha *escolha = new Escolha();
                        while(true){
							getline(in, line);
							if(line == "?END"){
								break;
							}
							escolha->add_opcao(Opcao(line));
						}
						this->atual->insere_fala(escolha);
                    }
                    break;
				case '>':
					this->atual->link(line);
					break;
                case '#':
					if(this->atual != nullptr && this->atual->get_proxima().empty()){
						this->atual->link(line);
					}
					this->atual = new Secao(line);
					this->secoes[line] = this->atual;
                    break;
                default:
                    //cout << "INVALIDO: " + line << endl;
                    break;
            }
        }
    }
}
