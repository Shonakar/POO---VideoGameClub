#ifndef ADMINISTRADORA_H
#define ADMINISTRADORA_H
#include "VideoJuego.h"
#include <vector>
#include "Usuario.h"
#include "Cliente.h"
#include "Alquiler.h"
#include <string>
using namespace std;

class Administradora {
	vector<Usuario> Usuarios;
	vector<Cliente> Clientes;
	vector<VideoJuego> VideoJuegos;
	vector<Alquiler> Alquileres;
	Usuario *UsuarioActivo;
	tm FechaActual;
	int m_idClienteActual = -1;
	int m_idJuegoActual = -1;
public:
	Administradora();
	
	void actualizarHora();
	bool ValidarInicio (const char UsuIni[],const char PassIni[]);
	void GuardarUsuarioActual(unsigned int id);
	Usuario* verUsuarioActivo();
	void NuevoUsuario(Usuario Nuevo);
	void ModificarUsuario(int pos, Usuario mod);
	void EliminarUsuario( unsigned int id);
	int BuscarUsuario( unsigned int id);
	void CargarListaUsuarios();
	void GuardarListaUsuarios();
	size_t CantidadUsuarios();
	void verListaUsuarios();
	
	Usuario& verUsuariosPosVector(int i);
	
	void NuevoCliente(Cliente Nuevo);
	void ModificarCliente(int pos, Cliente mod);
	void CambiarEstadoCliente(unsigned int id);
	int BuscarCliente( unsigned int id);
	void CargarListaClientes();
	void GuardarListaClientes();
	void verListaClientes();
	size_t CantidadClientes();
	Cliente& verClientesPosVector(int i);
	
	void NuevoVideoJuego(VideoJuego Nuevo);
	void ModificarVideoJuego(int pos, VideoJuego mod); //Aca agregariamos cant al stock?
	void CargarListaJuegos();
	void GuardarListaJuegos();
	void verListaJuegos();
	size_t CantidadJuegos();
	VideoJuego& verJuegosPosVector(int i);
	
	void NuevoAlquiler( unsigned int id_clien, unsigned int id_usu, unsigned int id_juego , int dias);
	void TerminarAlquiler(int pos);
	void GuardarListaAlquileres();
	void CargarListaAlquileres();
	void verListaAlquileres();
	size_t CantidadAlquileres();
	Alquiler& verAlquileresPosVector(int i);
	int buscarPosAlquilerPorIds(unsigned int idC, unsigned int idJ);
	
	Cliente* BuscarClientePorId(unsigned int id);
	Usuario* BuscarUsuarioPorId(unsigned int id);
	VideoJuego* BuscarJuegoPorId(unsigned int id);
	
	void idJuegoActual(int pos);
	void idClienteActual(int pos);
	int verIdJuegoActual();
	int verIdUsuarioActual();
	int verIdClienteActual();
	
	string verFechaActual();
};

#endif

