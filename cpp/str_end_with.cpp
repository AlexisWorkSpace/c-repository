#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;


/***********************************************************************************************************************
rbegin() - Iterador al último carácter - Inicio del recorrido en reversa
rend() - Iterador "pasado" el primero - Fin del recorrido en reversa
std::equal() - compara dos rangos elemento por elemento - verifica si los ultimos elementos de str coinciden con str
************************************************************************************************************************/

bool solution(std::string const &str, std::string const &ending) {
    return ending.size() > str.size() ? 
		false :
	 	std::equal(ending.rbegin(), ending.rend(), str.rbegin());
}

int main() {
	std::string str1 = "hola";
	std::string str2 = "ola";
	bool test = solution(str1, str2);
	cout << test << endl;
	
	return 0;
}


