#include <iostream>
#include "Estudiante.h"
int main()
{
	int opc;
	cout << "-------------Seleccione la accion que desea realizar-------------" << endl;
	cout << "1-Crear un estudiante" << endl;
	cout << "2-Csonsultar un estudiante" << endl;
	cout << "3-Modificar un estudiante" << endl;
	cout << "4-Eliminar un estudiante" << endl;
	cout << "5. Salir" << endl << endl;
	cin >> opc;
	Estudiante c = Estudiante();
	switch (opc) {
	case 1: c.crear();
		; break;
	case 2: c.leer(); 
		; break;
	case 3: c.actualizar(); 
		; break;
	case 4: c.borrar(); 
		; break;
	case 5: exit(-1); 
		; break;
	default:cout << "Numero inexistente";
	}
	system("pause");
}

