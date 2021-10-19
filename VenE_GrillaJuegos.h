#ifndef VENE_GRILLAJUEGOS_H
#define VENE_GRILLAJUEGOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class VenE_GrillaJuegos : public D_GrillaJ {
	
private:
	Administradora *m_Admin;
protected:
	void ClickElegir( wxCommandEvent& event )  override;
	
public:
	VenE_GrillaJuegos(wxWindow *parent, Administradora *admin);
	~VenE_GrillaJuegos();
};

#endif

