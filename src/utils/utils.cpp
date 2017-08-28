#include <tuple>

#include "utils/utils.hpp"

vector<string> split(string str, char delimiter){
	vector<string> strings;
	
	stringstream ss(str);
	string tok;
	
	while(getline(ss, tok, delimiter)){
		strings.push_back(tok);
	}
	
	return strings;
}

string find_inside(string src, char c1, char c2, string::size_type _inicio, string::size_type *_fim){
    string::size_type inicio = src.find(c1, _inicio);
	if(inicio == string::npos){
		if(_fim != nullptr);
		(*_fim) = _inicio;
		return src;
	}else{
		inicio++;
	}
    string::size_type fim = src.find(c2, inicio);
    
	if(_fim != nullptr){
		(*_fim) = fim;
	}
	
    return src.substr(inicio, fim - inicio);
}
