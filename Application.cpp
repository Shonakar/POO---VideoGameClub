#include <wx/image.h>
#include "Application.h"
#include "Ven_Inicio.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	Ven_Inicio *win = new Ven_Inicio(&m_Admin);
	win->Show();

	return true;
}

