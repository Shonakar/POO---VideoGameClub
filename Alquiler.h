#ifndef ALQUILER_H
#define ALQUILER_H
#include <ctime>
#include "VideoJuego.h"
#include "Cliente.h"
#include "Usuario.h"
#include "Utilidades.h"
using namespace std;

class Alquiler {
	int m_dias;
	tm fecha_ini;
	tm fecha_fin;
	tm fechaActual;
	VideoJuego * esteJuego;
	Cliente * esteCliente;
	Usuario * esteUsuario;
	Estado m_estado = Activo;
public:
	//Constructor para alquiler nuevo
	Alquiler(Cliente &clien, Usuario &usua, VideoJuego &juego, int dias);
	//Constructor para cargar del binario
	Alquiler(Cliente &clien, Usuario &usua, VideoJuego &juego, tm ini, tm fin);
	//constructor para cargar el binario 2
	Alquiler(Cliente &clien, Usuario &usua, VideoJuego &juego, tm ini, tm fin, Estado est);
	tm verFechaInicial();
	tm verFechaFinal();
	int verDias();
	
	VideoJuego* verJuegoPrestado();
	Cliente* verCliente();
	Usuario* verUsuario();

	void agregarDias(int dias);
	int verIdCliente();
	int verIdUsuario();
	int verIdJuego();
	Estado verEstado();
	void cambiarEstado(Estado actualizar);
	void finalizarEstado();
};

#endif

