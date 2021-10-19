#ifndef USUARIO_H
#define USUARIO_H
#include "Persona.h"

class Usuario : public Persona {
	char m_nomusu[20], m_pass[20];
	bool m_admin = false;
	unsigned int m_id;
public:
	Usuario(unsigned int id,const char nom[],const char ape[],const char dire[],int dni,const char pass[],bool adm);
	Usuario(char usu[],char pass[],bool adm);
	char* verNombreUsuario();
	char* verContra();
	unsigned int verId();
	bool esAdmin();
	void CambiarContra(const char npass[]);
	void CambiarEstado();
	void CambiarEstado(bool);

};
#endif

