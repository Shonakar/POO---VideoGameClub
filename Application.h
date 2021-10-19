#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Administradora.h"

class Application : public wxApp {
	Administradora m_Admin;
public:
	virtual bool OnInit();
};

#endif
