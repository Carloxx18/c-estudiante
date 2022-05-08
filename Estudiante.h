#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "Persona.h"
#include "CONEC.h"
using namespace std;
class Estudiante : Persona {
private: string email;
	   string carnet;
public:
	Estudiante() {
	}
	Estudiante(string nom, string ape, string dir, int gen, string car, int tel, string fn, string em) : Persona(nom, ape, dir, tel, gen, fn) {
		email = em;
		carnet = car;
	}
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setGenero(int gen) { genero = gen; }
	void setEmail(string em) { email = em; }
	void setTelefono(int tel) { telefono = tel; }
	void setFehca_Nacimiento(string fn) { fecha_na = fn; }
	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	int getTelefono() { return telefono; }
	string getFehca_Nac() { return fecha_na; }
	void crear() {
		int q_estado;
		CONEC cn = CONEC();
		cn.abrir_conec();
		string t = to_string(telefono);
		string g = to_string(genero);
		cout << "Ingrese el narnet: ";
		cin >> carnet;
		cout << "Ingrese el nombre: ";
		cin >> nombres;
		cout << "Ingrese el apellido: ";
		cin >> apellidos;
		cout << "Ingrese la direccion: ";
		cin >> direccion;
		cout << "Ingrese el Genero: ";
		cin >> genero;
		cout << "Ingrese el email: ";
		cin >> email;
		cout << "Ingrese el telefono: ";
		cin >> telefono;
		cout << "Ingrese la Fecha de nacimiento: ";
		cin >> fecha_na;
		if (cn.getConectar()) {
			string insert = "insert into estudiantes.ba_estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) values('" + carnet + "','" + nombre + "', '" + apellido + "','" + direccion + "','" + telefono + "'," + genero + ", '" + email + "','" + fecha_na + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingresos Exitosos" << endl;
			}
			else {
				cout << "Error al Ingresar" << endl;
			}
		}
		else {
			cout << "ERROR EN LA CONEXION..." << endl;
		}
		cn.cerrar_conexion();
		system("pause");	system("cls");
	}

	void leer() {
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		CONEC cn = CONEC();
		cn.abrir_coneC();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM estudiantes.ba_estudiante";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << "  |  " << fila[7] << "  |  " << fila[8] << endl;
				}
			}
			else {
				cout << "fallo al consultar : " << mysql_error(cn.getConectar()) << endl;
			}
			if (cn.getConectar()) {

			}
		}
		else {
			cout << "error al conectar" << endl;
		}
		cn.cerrar_conc();
		system("pause");	system("cls");
	}

	void actualizar() {
		int q_estado;
		CONEC cn = CONEC();
		cn.abrir_conec();
		string idestudiante;
		string telefono = to_string(telefono);
		string genero = to_string(genero);
		cout << "Ingrese id del estudiante: ";
		cin >> idestudiante;
		cout << "Ingrese el carnet: ";
		cin >> carnet;
		cout << "Ingrese el nombre: ";
		cin >> nombres;
		cout << "Ingrese el apellido: ";
		cin >> apellidos;
		cout << "Ingrese la direccion: ";
		cin >> direccion;
		cout << "Ingrese el genero: ";
		cin >> genero;
		cout << "Ingrese el email: ";
		cin >> email;
		cout << "Ingrese el telefono: ";
		cin >> telefono;
		cout << "Ingrese la Fecha de nacimiento: ";
		cin >> fecha_na;
		if (cn.getConectar()) {
			string update = "update estudiantes.ba_estudiante set carnet =('" + carnet + "'), nombre =('" + nombres + "'), apellido =('" + apellidos + "'), direccion=('" + direccion + "'), genro=(" + genero + "), emial=('" + email + "'), telefono=('" + telefono + "'), fecha_nacimiento('" + fecha_nac + "') where id_estudiente = ('" + idestudiante + "')  ";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se modifico exitosamente" << endl;
			}
			else {
				cout << "Error al modificar" << endl;
			}
		}
		else {
			cout << "error al conectar" << endl;
		}
		cn.cerrar_conec();
		system("pause");	system("cls");
	}

	void borrar() {
		int q_estado;
		CONEC cn = CONEC();
		cn.abrir_conec();
		string idestudiante;
		cout << "Ingrese el id" << endl;
		cin >> idestudiante;
		if (cn.getConectar()) {
			string borrar = "delete from estudiantes.ba_estudiante where idestudiante = ('" + idestudiante + "')";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se elimino correctamente" << endl;
			}
			else {
				cout << "No se elimino correctamente" << endl;
			}
		}
		else {
			cout << "fallo la conexion" << endl;
		}
		cn.cerrar_conec();
		system("pause");	system("cls");
	}
};