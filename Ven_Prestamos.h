#ifndef VEN_PRESTAMOS_H
#define VEN_PRESTAMOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class Ven_Prestamos : public V_Prestamos {
	
private:
	Administradora *m_Admin;
	bool todos = false;
protected:
	void MostraTodos( wxCommandEvent& event )  override;
	void ClickCerrarSesion( wxCommandEvent& event )  override;
	void ClickNuevoA( wxCommandEvent& event )  override;
	void ClickFinalizarA( wxCommandEvent& event )  override;
	void ClickInfUsuarioA( wxCommandEvent& event )  override;
	void ClickInfClienA( wxCommandEvent& event )  override;
	void ClickListaJuegos( wxCommandEvent& event )  override;
	void ClickListaClientes( wxCommandEvent& event )  override;
	void ClickListaUsuarios( wxCommandEvent& event )  override;
	void RefrescarGrilla( bool todos );
public:
	Ven_Prestamos(Administradora *Admin);
};

#endif

