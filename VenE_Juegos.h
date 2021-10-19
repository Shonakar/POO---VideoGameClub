#ifndef VENE_JUEGOS_H
#define VENE_JUEGOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class VenE_Juegos : public D_Juegos {
	
private:
	Administradora *m_Admin;
	int m_Accion=0;
	unsigned int m_Pos=0;
protected:
	void ClickConfirmar( wxCommandEvent& event )  override;
	
public:
	//Constructor para crear nuevo
	VenE_Juegos(wxWindow *parent, Administradora* admin);
	//Constructor para ver
	VenE_Juegos(wxWindow *parent, Administradora *admin,unsigned int pos, int accion);
};

#endif

