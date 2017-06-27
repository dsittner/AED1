#include <iostream>
#include "ejercicios.h"
#include <vector>
using namespace std;


/*********************************
 1ER PARTE: SECUENCIAS DE ENTEROS
*********************************/

// EJERCICIO 1

vector <int> mesetaMasLarga (vector <int> vec){
	vector <int> result;
	int desde = 0;
	int hasta = 0;
	int i = 0;
	int mesetaMaxima = 0;
	int mesetaValor = 0;
	bool hayMeseta;
	int largoMeseta;

	while (i < vec.size()-1){
		desde = i;
		hayMeseta = false;
		while (vec[i] == vec[i+1] && i < vec.size()-1){
			i++;
			hayMeseta = true;
		}
		if (hayMeseta){
			hasta = i;
			i--;
			largoMeseta = hasta - desde + 1;
			if (largoMeseta > mesetaMaxima){
				mesetaMaxima = largoMeseta;
				mesetaValor = vec [hasta];
			}
		}
		i++;
	}

	i = 1;
	while (i <= mesetaMaxima){
		result.push_back(mesetaValor);
		i++;
	}

	return result;
}


// EJERCICIO 2
/*
vector <vector <int> > secuenciaDeSecuencia (int n){
	vector <vector <int> > result;

	for (int i = 0; i < 10^n; i++){

	}

	return result;
}
*/


// EJERCICIO 3

vector <int> infrasecuenciaMasLarga (vector <int> vec){
	vector <int> result;
	int longMasLarga = 0;
	int desde = 0;
	int hasta = 0;
	int i = 0;
	int desdeValor = 0;
	bool hayInfrasecuencia = false;

	while (i < vec.size()-1){
		hayInfrasecuencia = false;
		desde = i;
		desdeValor = vec[desde];
		while (vec[i] <= vec[i+1] && i < vec.size()-1){
			i++;
			hayInfrasecuencia = true;
		}
		if (hayInfrasecuencia){
			hasta = i;
			longMasLarga = hasta - desde;
		}
		i++;
	}

	i = 1;
	while (i <= longMasLarga){
		result.push_back(vec[desdeValor]);
		desdeValor++;
		i++;
	}

	return result;
}



// EJERCICIO 4

vector <pair <int, int> > productoCartesiano (vector <int> vec, vector <int> vec2){
	vector <pair <int, int> > result;
	int i = 0;
	int j;

	while (i < vec.size()){
		j = 0;
		while (j < vec2.size()){
			result.push_back(make_pair(vec[i],vec2[j]));
			j++;
		}
		i++;
	}
	return result;
}


// AUX PERTENECE

bool pertenece (vector <int> vec, int e){
	bool pert = false;

	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == e){
			pert = true;
		}
	}

	return pert;
}


// EJERCICIO 5

int distanciaDeHamming (vector <int> vec1, vector <int> vec2){
	int result = 0;
	for (int i = 0; i < vec1.size(); i++){
		if (vec1[i] != vec2[i]){
			result++;
		}
	}
	return result;
}


// EJERCICIO 6

int quickSelect (vector<int> vec, int k){
	vector <int> minimos;
	int min = vec[0];
	int indiceMin = 0;
	int max = vec[0];
	int i = 1;

	for (int j = 0; j < vec.size(); j++){
		if (vec[j] > max){
			max = vec[j];
		}
	}

	if (k <= vec.size()){
		while (i < k){
			for (int j = 0; j < vec.size(); j++){
				if (vec[j] < min){
					min = vec [j];
					indiceMin = j;
				}
			}
			vec[indiceMin] = max;
			min = max;
			i++;
		}
		for (int j = 0; j < vec.size(); j++){
			if (vec[j] < min){
				min = vec [j];
			}
		}
	}

	return min;
}


// AUX SUMA

int sumar (vector <int> vec, int desde, int hasta){
	int suma = 0;
	for (int i = desde; i <= hasta; i++){
		suma = suma + vec[i];
	}
	return suma;
}

// EJERCICIO 7

int indiceSumasIguales (vector <int> vec){

	int i = 0;

	while (sumar(vec,0,i-1) != sumar (vec,i+1,vec.size()-1) && i < vec.size()-1){
		i++;
	}

	return i;
}

// EJERCICIO 8

vector < vector <int> > compresionDeSecuencias (vector <int> vec){
	vector <vector <int> > result;
	int i = 0;
	int desde;
	int cont;

	while (i < vec.size()){
		vector <int> aux;
		desde = vec[i];
		cont = 1;
		while (i < vec.size() -1 && vec[i] + 1 == vec[i+1]){
			i++;
			cont++;
		}
		aux.push_back(desde);
		aux.push_back(cont);
		result.push_back(aux);
		i++;

	}

	return result;
}


/*********************************
       2DA PARTE: STRINGS
*********************************/

// EJERCICIO 9

bool esSubsecuencia (string s1, string s2){

	int i = 0;
	int j = 0;

	if (s1.size() < s2.size()){
		while (i < s2.size() && j < s1.size()){
			j = 0;
			if (s2[i] == s1[j]){
				while (i < s2.size() && j < s1.size() && s1[j] == s2[i]){
					j++;
					i++;
				}
				i--;
			}
			i++;
		}
	}

	return j == s1.size();
}


//  EJERCICIO 10

string subsecComunMasLarga (string s1, string s2){
	string result ="";
	int i = 0;
	int j = 0;
	int cont;
	int masLarga = 0;

	while (i < s1.size()){
		j = 0;
		while (j < s2.size()){
			if (s1[i] == s2[j]){
				cont = 0;
				string aux="";
				while (s1[i] == s2[j] && i < s1.size() && j < s2.size()){
					aux = aux + s1[i];
					i++;
					j++;
					cont++;
				}
				if (cont > masLarga){
					result = aux;
					masLarga = cont;
				}
			}
			i++;
			j++;
		}
		i++;
	}


	return result;
}


// EJERCICIO 11

string substringL (string s, int l){
	string result = "";
	char minimo = s[0];
	int indiceMin = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] < minimo && s.size()-i >= l){
			minimo = s[i];
			indiceMin = i;
		}
	}

	for (int i = indiceMin; i < indiceMin + l; i++){
		result = result + s[i];
	}

	return result;
}


// EJERCICIO 12

string ordenInverso (string s){
	string result="";
	string aux = "";

	for (int i = s.size()-1; i >= 0; i--){
		if (s[i] != '#'){
			aux = aux + s[i];
		}else{
			for (int j = i; j >= 0; j--){
				result = result + aux[j];
			}
			result = result + s[i];
			aux = "";
		}
	}
	for (int j = aux.size()-1; j >= 0; j--){
		result = result + aux[j];
	}

	return result;
}


// EJERCICIO 13



// EJERCICIO 14

vector <string> partirEnLineas (string s, int c){
	vector <string> result;
	int i = 0;
	int cont;
	string aux = "";
	string aux2 = "";
	int cont2;
	int j;

	while (i < s.size()){
		cont = 0;
		while (i < s.size() && cont <= c && s[i] != '#'){
			aux = aux + s[i];
			cont++;
			i++;
		}
		if (s[i] == '#'){
			int j = i+1;
			aux2 = "";
			cont2 = 0;
			while (j < s.size() && s[j] != '#'){
				aux2 = aux2 + s[j];
				j++;
				cont2++;
			}
			if ((cont + cont2) < c){
				aux = aux + "#" + aux2;
				i = j;
			}
		}
		result.push_back (aux);
		i++;
		aux = "";
	}

	return result;
}