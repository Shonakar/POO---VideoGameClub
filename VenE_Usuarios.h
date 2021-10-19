#ifndef VENE_USUARIOS_H
#define VENE_USUARIOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class VenE_Usuarios : public D_Usuarios {
	
private:
	Administradora *m_Admin;
	int m_Accion = 0;
	unsigned int m_Pos = 0;
protected:
	void esAdmin( wxCommandEvent& event )  override;
	void ClickConfirmar( wxCommandEvent& event )  override;
	
public:
	VenE_Usuarios(wxWindow *parent, Administradora* admin);
	VenE_Usuarios(wxWindow *parent, Administradora* admin, unsigned int pos, int accion);
	~VenE_Usuarios();
};

#endif

