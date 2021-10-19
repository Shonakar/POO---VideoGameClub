#include "VideoJuego.h"
#include <cstring>
using namespace std;

VideoJuego::VideoJuego (unsigned int id,const char  nom[], unsigned int precio, int stock, unsigned int prest) {
	m_Id = id;
	strcpy(m_Nom,nom);
	m_precio = precio;
	m_stock = stock;
	m_prestado = prest;
}

char * VideoJuego::verNombre ( ) {
	return m_Nom;
}

unsigned int VideoJuego::verPrecio ( ) {
	return m_precio;
}

unsigned int VideoJuego::verStock ( ) {
	return m_stock;
}

bool VideoJuego::Habilitado ( ) {
	if (m_stock >= 0 ) 
		return true;
	else 
		return false;
}

unsigned int VideoJuego::verPrestados ( ) {
	return m_prestado;
}

unsigned int VideoJuego::verId ( ) {
	return m_Id;
}

void VideoJuego::AgregarUno ( ) {
	m_stock++;
}

void VideoJuego::QuitarUno ( ) {
	if (m_stock>=m_prestado){
		m_stock--;
	}
}

unsigned int VideoJuego::verDisponibles ( ) {
	return m_stock-m_prestado;
}
void VideoJuego::PrestarUno ( ) {
	if (verDisponibles()>0)
		m_prestado++;
}


void VideoJuego::CambiarPrecio (unsigned int precio) {
	m_precio = precio;
}

void VideoJuego::DevolverUno ( ) {
	if(m_prestado>0)
		m_prestado--;
}

