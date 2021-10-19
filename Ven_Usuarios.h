#ifndef VEN_USUARIOS_H
#define VEN_USUARIOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class Ven_Usuarios : public V_Usuarios {
	
private:
	Administradora *m_Admin;
	bool Todos = false; 
protected:
	void ClickNuevoU( wxCommandEvent& event )  override;
	void ClickVerEditU( wxCommandEvent& event )  override;
	void ClickAltaBajaU( wxCommandEvent& event )  override;
	void ClickVolverP( wxCommandEvent& event )  override;
	void RefrescarGrilla();
	
public:
	Ven_Usuarios(Administradora *Admin);
	~Ven_Usuarios();
};

#endif

