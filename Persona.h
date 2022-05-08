#pragma once
#include <iostream>
using namespace std;
class Persona {

protected: string nombres, apellidos, direccion, fecha_na;
		 int telefono = 0;
		 int genero = 0;

		 Persona() {
		 }
		 Persona(string nom, string ape, string dir, int gen, int tel, string fn) {
			 nombres = nom;
			 apellidos = ape;
			 direccion = dir;
			 genero = gen;
			 telefono = tel;
			 fecha_na = fn;

		 }
};

