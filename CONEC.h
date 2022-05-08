#pragma once
class CONEC
{
#pragma once
#include <mysql.h>
#include <iostream>
	using namespace std;
	class COMEC
	{
	private: MYSQL* conectar;
	public:
		void abrir_conec() {
			conectar = mysql_init(0);
			conectar = mysql_real_connect(conectar, "localhost", "root", "canella", "estudiante", 3306, NULL, 0);
		}
		MYSQL* getConectar() {
			return conectar;
		}
		void cerrar_conec() {
			mysql_close(conectar);
		}
	};
};

