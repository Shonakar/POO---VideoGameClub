#ifndef VEN_INICIO_H
#define VEN_INICIO_H
#include "wxfb_project.h"
#include "Administradora.h"

class Ven_Inicio : public V_InicioS {
private:
	Administradora *m_Admin;
protected:
	void ClickCerrar( wxCommandEvent& event )  override;
	void ClickIniciar( wxCommandEvent& event )  override;
public:
	Ven_Inicio(Administradora *Admin);
};

#endif

