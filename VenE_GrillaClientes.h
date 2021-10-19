#ifndef VENE_GRILLACLIENTES_H
#define VENE_GRILLACLIENTES_H
#include "wxfb_project.h"
#include "Administradora.h"

class VenE_GrillaClientes : public D_GrillaC {
	
private:
	Administradora *m_Admin;
protected:
	void ClickElegir( wxCommandEvent& event )  override;
	
public:
	VenE_GrillaClientes(wxWindow *parent, Administradora *admin);
	~VenE_GrillaClientes();
};

#endif

