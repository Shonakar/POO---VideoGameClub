#ifndef VENE_CLIENTES_H
#define VENE_CLIENTES_H
#include "wxfb_project.h"
#include "Administradora.h"

class VenE_Clientes : public D_Clientes {
	
private:
	Administradora *m_Admin;
	int m_Accion = 0;
	unsigned int m_Pos = 0;
protected:
	void ClickConfirmar( wxCommandEvent& event )  override;
	
public:
	VenE_Clientes(wxWindow *parent, Administradora* admin);
	VenE_Clientes(wxWindow *parent, Administradora* admin, unsigned int pos, int accion);
	~VenE_Clientes();
};

#endif

