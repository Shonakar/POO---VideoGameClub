#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"

class Cliente : public Persona {
	int m_clave_prestamo;
	unsigned int m_id;
	bool habilitado;
	char m_NumTel[10], m_correo[30];
public:
	Cliente(const char nom[], const char ape[], const char dire[],int dni,unsigned int id, int clave, const char tel[], const char cor[]);
	Cliente(const char nom[], const char ape[], const char dire[],int dni,unsigned int id, int clave, const char tel[], const char cor[], bool Estado);
	unsigned int verId();
	int verClave();
	char* verTelefono();
	char* verCorreo();
	bool estaHabilitado();
	void cambiar_estado();
	void modificarTelefono(const char telefono[]);
	void modificarCorreo(const char correo[]);
	void modificarClave(int clave);
};

#endif

