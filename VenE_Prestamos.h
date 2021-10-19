#ifndef VENE_PRESTAMOS_H
#define VENE_PRESTAMOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class VenE_Prestamos : public D_Prestamos {
	
private:
	Administradora *m_Admin;
protected:
	void ClickBuscarClientes( wxCommandEvent& event )  override;
	void ClickBuscarJuegos( wxCommandEvent& event )  override;
	void ClickCrearA( wxCommandEvent& event )  override;
	
public:
	VenE_Prestamos(wxWindow *parent, Administradora *admin);
	~VenE_Prestamos();
};

#endif

