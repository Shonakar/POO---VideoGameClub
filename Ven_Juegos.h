#ifndef VEN_JUEGOS_H
#define VEN_JUEGOS_H
#include "wxfb_project.h"
#include "Administradora.h"

class Ven_Juegos : public V_Juegos {
	
private:
	Administradora *m_Admin;
	bool Todos = true; 
protected:
	void CambiarPrecio( wxCommandEvent& event )  override;
	void MostrarTodos( wxCommandEvent& event )  override;
	void AgregarUno( wxCommandEvent& event )  override;
	void QuitarUno( wxCommandEvent& event )  override;
	void ClickNuevoJ( wxCommandEvent& event )  override;
	void ClickVolverA( wxCommandEvent& event )  override;
	void RefrescarGrilla(bool todos);
public:
	Ven_Juegos(Administradora *admin);
	~Ven_Juegos();
};

#endif

