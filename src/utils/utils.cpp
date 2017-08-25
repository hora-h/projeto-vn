#include <tuple>

#include "utils/utils.hpp"


tuple<string, string::size_type> find_inside(string src, char c1, char c2, string::size_type _inicio = 0){
    string::size_type inicio = src.find(c1, _inicio);
	if(inicio == string::npos){
		return make_tuple(src, _inicio);
	}else{
		inicio++;
	}
    string::size_type fim = src.find(c2, inicio);
    
    return make_tuple(src.substr(inicio, fim - inicio), fim);
}
