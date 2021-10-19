#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

class VideoJuego {
	char m_Nom[30];
	int m_stock;
	unsigned int m_Id, m_precio, m_prestado = 0;
public:
	VideoJuego(unsigned int id,const char nom[],unsigned int precio, int stock, unsigned int prest);
	char* verNombre();
	unsigned int verPrecio();
	unsigned int verStock();
	unsigned int verPrestados();
	unsigned int verId();
	bool Habilitado();
	void AgregarUno();
	void QuitarUno();
	unsigned int verDisponibles();
	void PrestarUno();
	void DevolverUno();
	void CambiarPrecio( unsigned int precio );

};
#endif

