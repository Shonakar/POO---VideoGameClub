#ifndef VEN_CLIENTES_H
#define VEN_CLIENTES_H
#include "wxfb_project.h"
#include "Administradora.h"

class Ven_Clientes : public V_Clientes {
	
private:
	Administradora *m_Admin;
protected:
	void ClickNuevoC( wxCommandEvent& event )  override;
	void ClickVerEditC( wxCommandEvent& event )  override;
	void ClickAltBajC( wxCommandEvent& event )  override;
	void ClickVolverA( wxCommandEvent& event )  override;
	void RefrescarGrilla();
public:
	Ven_Clientes(Administradora *Admin);
	~Ven_Clientes();
};

#endif

