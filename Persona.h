#ifndef PERSONA_H
#define PERSONA_H

class Persona {
	char m_nom[20], m_ape[20], m_direccion[50];
	int m_dni;
public:
	Persona(const char nom[],const char ape[], const char dire[], int dni);
	char* verNombre();
	char* verApellido();
	int verDni();
	char* verDireccion();
	void modificarNombre(const char nom[]);
	void modificarApellido(const char ape[]);
	void modificarDireccion(const char dire[]);
	void modificarDni(int dni);
	
};
#endif

