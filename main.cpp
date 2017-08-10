#include "personagem.hpp"

Flag flag_list;

int main(){
	flag_list["evento1"] = true;
	cout<< flag_list["evento1"] << endl;
	return 0;
}