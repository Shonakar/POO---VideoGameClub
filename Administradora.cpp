#include "Administradora.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Usuario Admin("admin", "admin", true);

Administradora::Administradora()
{
	//	Fecha Actual de la pc al iniciar el sistema
	time_t actual;
	time(&actual);
	FechaActual = *localtime(&actual);

	FechaActual.tm_year = FechaActual.tm_year + 1900;
}
void Administradora::NuevoUsuario(Usuario Nuevo)
{
	Usuarios.push_back(Nuevo);
}

void Administradora::ModificarUsuario(int pos, Usuario mod)
{
	Usuarios[pos] = mod;
}

void Administradora::EliminarUsuario(unsigned int id)
{
	for (size_t i = 0; i < Usuarios.size(); i++)
	{
		if (Usuarios[i].verId() == id)
		{
			Usuarios.erase(Usuarios.begin() + i);
		}
	}
}

int Administradora::BuscarUsuario(unsigned int id)
{
	for (size_t i = 0; i < Usuarios.size(); i++)
	{
		if (Usuarios[i].verId() == id)
		{
			return i;
		}
	}
	return -1;
}
bool Administradora::ValidarInicio(const char UsuIni[], const char PassIni[])
{
	if ((strcmp(UsuIni, Admin.verNombreUsuario()) == 0) && (strcmp(PassIni, Admin.verContra()) == 0))
	{
		UsuarioActivo = &Admin;
		return true;
	}

	for (size_t i = 0; i < Usuarios.size(); i++)
	{
		if ((strcmp(UsuIni, Usuarios[i].verNombreUsuario()) == 0) && (strcmp(PassIni, Usuarios[i].verContra()) == 0))
		{
			UsuarioActivo = &Usuarios[i];
			return true;
		}
	}

	return false;
}

void Administradora::NuevoCliente(Cliente Nuevo)
{
	Clientes.push_back(Nuevo);
}

void Administradora::ModificarCliente(int pos, Cliente mod)
{
	Clientes[pos] = mod;
}

void Administradora::CambiarEstadoCliente(unsigned int id)
{
	for (size_t i = 0; i < Clientes.size(); i++)
	{
		if (Clientes[i].verId() == id)
		{
			Clientes[i].cambiar_estado();
		}
	}
}

int Administradora::BuscarCliente(unsigned int id)
{
	for (size_t i = 0; i < Clientes.size(); i++)
	{
		if (Clientes[i].verId() == id)
		{
			return i;
		}
	}
	return -1;
}

void Administradora::NuevoVideoJuego(VideoJuego Nuevo)
{
	VideoJuegos.push_back(Nuevo);
}

void Administradora::ModificarVideoJuego(int pos, VideoJuego mod)
{
	VideoJuegos[pos] = mod;
}

void Administradora::NuevoAlquiler(unsigned int id_clien, unsigned int id_usu, unsigned int id_juego, int dias)
{
	Cliente *esteCliente = BuscarClientePorId(id_clien);
	Usuario *esteUsuario = BuscarUsuarioPorId(id_usu);
	VideoJuego *esteJuego = BuscarJuegoPorId(id_juego);
	Alquiler Nuevo(*esteCliente, *esteUsuario, *esteJuego, dias);
	Alquileres.push_back(Nuevo);
	BuscarJuegoPorId(id_juego)->PrestarUno();
}

void Administradora::TerminarAlquiler(int pos)
{
	Alquileres[pos].cambiarEstado(Terminado);
	BuscarJuegoPorId(Alquileres[pos].verIdJuego())->DevolverUno();
}

void Administradora::CargarListaUsuarios()
{
	Usuarios.clear();
	char nomaux[20], apeaux[20], direaux[50], nomusu[20], pass[20];
	int dniaux = -1, admin = -1, idaux = -1;
	ifstream Arch("ListaUsuarios.dat", ios::binary);
	if (!Arch.is_open())
	{
		cout << "No se encuentra el archivo";
	}
	else
	{
		while (Arch.read(nomaux, sizeof(nomaux)))
		{
			Arch.read(apeaux, sizeof(apeaux));
			Arch.read(direaux, sizeof(direaux));
			Arch.read(reinterpret_cast<char *>(&dniaux), sizeof(dniaux));
			Arch.read(reinterpret_cast<char *>(&nomusu), sizeof(nomusu));
			Arch.read(reinterpret_cast<char *>(&pass), sizeof(pass));
			Arch.read(reinterpret_cast<char *>(&admin), sizeof(admin));
			Arch.read(reinterpret_cast<char *>(&idaux), sizeof(idaux));
			if (admin == 1)
			{
				Usuario usuarioaux(idaux, nomaux, apeaux, direaux, dniaux, pass, true);
				Usuarios.push_back(usuarioaux);
			}
			else
			{
				Usuario usuarioaux(idaux, nomaux, apeaux, direaux, dniaux, pass, false);
				Usuarios.push_back(usuarioaux);
			}
		}
		Arch.close();
	}
	cout << "USUARIOS CARGADOS:" << Usuarios.size() << endl;
}

void Administradora::GuardarListaUsuarios()
{
	char nomaux[20], apeaux[20], direaux[50], nomusu[20], pass[20];
	int dniaux, admin, idaux;
	ofstream Arch("ListaUsuarios.dat", ios::binary | ios::trunc);
	if (!Arch.is_open())
	{
		cout << "No se encuentra el archivo";
	}
	else
	{
		for (size_t i = 0; i < Usuarios.size(); i++)
		{

			strcpy(nomaux, Usuarios[i].verNombre());
			Arch.write(nomaux, sizeof(nomaux));

			strcpy(apeaux, Usuarios[i].verApellido());
			Arch.write(apeaux, sizeof(apeaux));

			strcpy(direaux, Usuarios[i].verDireccion());
			Arch.write(direaux, sizeof(direaux));

			dniaux = Usuarios[i].verDni();
			Arch.write(reinterpret_cast<char *>(&dniaux), sizeof(dniaux));

			strcpy(nomusu, Usuarios[i].verNombreUsuario());
			Arch.write(nomusu, sizeof(nomusu));

			strcpy(pass, Usuarios[i].verContra());
			Arch.write(pass, sizeof(pass));

			if (Usuarios[i].esAdmin() == true)
			{
				admin = 1;
			}
			else
			{
				admin = 0;
			}
			Arch.write(reinterpret_cast<char *>(&admin), sizeof(admin));

			idaux = Usuarios[i].verId();
			Arch.write(reinterpret_cast<char *>(&idaux), sizeof(idaux));
		}
		Arch.close();
	}
	cout << "USUARIOS GUARDADOS...!" << endl;
}

void Administradora::CargarListaClientes()
{
	Clientes.clear();
	char nomaux[20], apeaux[20], direaux[50], telaux[10], coraux[30];
	int dniaux = -1, idaux = -1, claveaux = -1, estado = -1;
	bool boolEstado;
	ifstream Arch("ListaClientes.dat", ios::binary);
	if (!Arch.is_open())
	{
		cout << "No se encuentra el archivo" << endl;
	}
	else
	{
		while (Arch.read(nomaux, sizeof(nomaux)))
		{
			Arch.read(apeaux, sizeof(apeaux));
			Arch.read(direaux, sizeof(direaux));
			Arch.read(reinterpret_cast<char *>(&dniaux), (sizeof(dniaux)));
			Arch.read(reinterpret_cast<char *>(&idaux), (sizeof(idaux)));
			Arch.read(reinterpret_cast<char *>(&claveaux), (sizeof(claveaux)));
			Arch.read(telaux, sizeof(telaux));
			Arch.read(coraux, sizeof(coraux));
			Arch.read(reinterpret_cast<char *>(&estado), sizeof(estado));

			if (estado == 1)
			{
				boolEstado = true;
			}
			else
			{
				boolEstado = false;
			}
			Cliente clienteaux(nomaux, apeaux, direaux, dniaux, idaux, claveaux, telaux, coraux, boolEstado);
			Clientes.push_back(clienteaux);
		}
		Arch.close();
	}
	cout << "CLIENTES CARGADOS:" << Clientes.size() << endl;
}

void Administradora::GuardarListaClientes()
{
	char nomaux[20], apeaux[20], direaux[50], telaux[10], coraux[30];
	int dniaux, idaux, claveaux, estado;
	ofstream Arch("ListaClientes.dat", ios::binary | ios::trunc);
	if (!Arch.is_open())
	{
		cout << "No se encuentra el archivo" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < Clientes.size(); i++)
		{
			strcpy(nomaux, Clientes[i].verNombre());
			Arch.write(nomaux, sizeof(nomaux));

			strcpy(apeaux, Clientes[i].verApellido());
			Arch.write(apeaux, sizeof(apeaux));

			strcpy(direaux, Clientes[i].verDireccion());
			Arch.write(direaux, sizeof(direaux));

			dniaux = Clientes[i].verDni();
			Arch.write(reinterpret_cast<char *>(&dniaux), sizeof(dniaux));

			idaux = Clientes[i].verId();
			Arch.write(reinterpret_cast<char *>(&idaux), sizeof(idaux));

			claveaux = Clientes[i].verClave();
			Arch.write(reinterpret_cast<char *>(&claveaux), sizeof(claveaux));

			strcpy(telaux, Clientes[i].verTelefono());
			Arch.write(telaux, sizeof(telaux));

			strcpy(coraux, Clientes[i].verCorreo());
			Arch.write(coraux, sizeof(coraux));

			if (Clientes[i].estaHabilitado())
			{
				estado = 1;
			}
			else
			{
				estado = 0;
			}
			Arch.write(reinterpret_cast<char *>(&estado), sizeof(estado));
		}
		Arch.close();
	}
	cout << "CLIENTES GUARDADOS...!" << endl;
}

void Administradora::CargarListaJuegos()
{
	VideoJuegos.clear();
	char nomaux[30];
	unsigned int precaux, prestaux, idaux;
	int stockaux;
	ifstream Arch("ListaJuegos.dat", ios::binary);
	if (!Arch.is_open())
	{
		cout << "No se encuentra el archivo" << endl;
	}
	else
	{
		while (Arch.read(nomaux, sizeof(nomaux)))
		{
			Arch.read(reinterpret_cast<char *>(&idaux), sizeof(idaux));
			Arch.read(reinterpret_cast<char *>(&precaux), sizeof(precaux));
			Arch.read(reinterpret_cast<char *>(&stockaux), sizeof(stockaux));
			Arch.read(reinterpret_cast<char *>(&prestaux), sizeof(prestaux));

			VideoJuego JuegoAux(idaux, nomaux, precaux, stockaux, prestaux);
			VideoJuegos.push_back(JuegoAux);
		}
		Arch.close();
	}
	cout << "JUEGOS CARGADOS:" << VideoJuegos.size() << endl;
}

void Administradora::GuardarListaJuegos()
{
	char nomaux[30];
	unsigned int precaux, prestaux, idaux;
	int stockaux;
	ofstream Arch("ListaJuegos.dat", ios::binary | ios::trunc);
	if (!Arch.is_open())
	{
		cout << "Error al abrir el archivo" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < VideoJuegos.size(); i++)
		{

			strcpy(nomaux, VideoJuegos[i].verNombre());
			Arch.write(nomaux, sizeof(nomaux));

			idaux = VideoJuegos[i].verId();
			Arch.write(reinterpret_cast<char *>(&idaux), sizeof(idaux));

			precaux = VideoJuegos[i].verPrecio();
			Arch.write(reinterpret_cast<char *>(&precaux), sizeof(precaux));

			stockaux = VideoJuegos[i].verStock();
			Arch.write(reinterpret_cast<char *>(&stockaux), sizeof(stockaux));

			prestaux = VideoJuegos[i].verPrestados();
			Arch.write(reinterpret_cast<char *>(&prestaux), sizeof(prestaux));
		}
		Arch.close();
	}
	cout << "JUEGOS GUARDADOS...!" << endl;
}

void Administradora::verListaUsuarios()
{
	cout << "Lista Usuarios: " << endl;
	for (size_t i = 0; i < Usuarios.size(); i++)
	{
		cout << "Nombre: " << Usuarios[i].verNombre() << " "
			 << "Apellido: " << Usuarios[i].verApellido() << endl;
	}
}

void Administradora::verListaClientes()
{
	cout << "Lista Clientes: " << endl;
	for (size_t i = 0; i < Clientes.size(); i++)
	{
		cout << "Nombre: " << Clientes[i].verNombre() << " "
			 << "Apellido: " << Clientes[i].verApellido() << endl;
	}
}

void Administradora::verListaJuegos()
{
	cout << "Lista Juegos: " << endl;
	for (size_t i = 0; i < VideoJuegos.size(); i++)
	{
		cout << "Nombre: " << VideoJuegos[i].verNombre() << " "
			 << "Precio: " << VideoJuegos[i].verPrecio() << endl;
	}
}

void Administradora::GuardarListaAlquileres()
{
	tm iniaux, finaux;
	int id_juego, id_cliente, id_usuario, estado = -1;
	ofstream Arch("ListaAlquileres.dat", ios::binary | ios::trunc);
	if (!Arch.is_open())
	{
		cout << "Error al abrir el archivo" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < Alquileres.size(); i++)
		{

			id_cliente = Alquileres[i].verIdCliente();
			Arch.write(reinterpret_cast<char *>(&id_cliente), sizeof(id_cliente));

			id_usuario = Alquileres[i].verIdUsuario();
			Arch.write(reinterpret_cast<char *>(&id_usuario), sizeof(id_usuario));

			id_juego = Alquileres[i].verIdJuego();
			Arch.write(reinterpret_cast<char *>(&id_juego), sizeof(id_juego));
			//Guardamos Fecha Inicial
			iniaux = Alquileres[i].verFechaInicial();

			Arch.write(reinterpret_cast<char *>(&iniaux.tm_year), sizeof(iniaux.tm_year));

			Arch.write(reinterpret_cast<char *>(&iniaux.tm_mon), sizeof(iniaux.tm_mon));

			Arch.write(reinterpret_cast<char *>(&iniaux.tm_mday), sizeof(iniaux.tm_mday));

			finaux = Alquileres[i].verFechaFinal();

			Arch.write(reinterpret_cast<char *>(&finaux.tm_year), sizeof(finaux.tm_year));

			Arch.write(reinterpret_cast<char *>(&finaux.tm_mon), sizeof(finaux.tm_mon));

			Arch.write(reinterpret_cast<char *>(&finaux.tm_mday), sizeof(finaux.tm_mday));
			//			cout<<id_usuario<<" "<<id_cliente<<" "<<id_juego<<endl;
			if (Alquileres[i].verEstado() == Activo)
				estado = 1;
			else if (Alquileres[i].verEstado() == Vencido)
				estado = 2;
			else if (Alquileres[i].verEstado() == Terminado)
				estado = 3;
			Arch.write(reinterpret_cast<char *>(&estado), sizeof(estado));
		}
	}
	Arch.close();
	cout << "Alquileres Guardados" << endl;
}

void Administradora::CargarListaAlquileres()
{
	Alquileres.clear();
	tm iniaux, finaux;
	Cliente *esteCliente;
	Usuario *esteUsuario;
	VideoJuego *esteJuego;
	Estado estado;

	unsigned int id_juego = 0, id_cliente = 0, id_usuario = 0, intEstado;
	ifstream Arch("ListaAlquileres.dat", ios::binary);
	if (!Arch.is_open())
	{
		cout << "No se encuentra el arhivo" << endl;
	}
	else
	{
		while (Arch.read(reinterpret_cast<char *>(&id_cliente), sizeof(id_cliente)))
		{
			Arch.read(reinterpret_cast<char *>(&id_usuario), sizeof(id_usuario));
			Arch.read(reinterpret_cast<char *>(&id_juego), sizeof(id_juego));

			Arch.read(reinterpret_cast<char *>(&iniaux.tm_year), sizeof(iniaux.tm_year));
			Arch.read(reinterpret_cast<char *>(&iniaux.tm_mon), sizeof(iniaux.tm_mon));
			Arch.read(reinterpret_cast<char *>(&iniaux.tm_mday), sizeof(iniaux.tm_mday));

			Arch.read(reinterpret_cast<char *>(&finaux.tm_year), sizeof(finaux.tm_year));
			Arch.read(reinterpret_cast<char *>(&finaux.tm_mon), sizeof(finaux.tm_mon));
			Arch.read(reinterpret_cast<char *>(&finaux.tm_mday), sizeof(finaux.tm_mday));

			esteCliente = BuscarClientePorId(id_cliente);
			esteUsuario = BuscarUsuarioPorId(id_usuario);
			esteJuego = BuscarJuegoPorId(id_juego);

			Arch.read(reinterpret_cast<char *>(&intEstado), sizeof(intEstado));
			if (intEstado == 1)
				estado = Activo;
			else if (intEstado == 2)
				estado = Vencido;
			else if (intEstado == 3)
				estado = Terminado;

			Alquiler aux(*esteCliente, *esteUsuario, *esteJuego, iniaux, finaux, estado);
			Alquileres.push_back(aux);
		};
	}
	Arch.close();
	cout << "ALQUILERES CARGADOS:" << Alquileres.size() << endl;
}

void Administradora::verListaAlquileres()
{
	for (unsigned int i = 0; i < Alquileres.size(); i++)
	{
		cout << "Prestamo: " << endl;
		cout << "Usuario: " << Alquileres[i].verUsuario()->verNombre() << " " << Alquileres[i].verUsuario()->verApellido() << endl;
		cout << "Cliente: " << Alquileres[i].verCliente()->verNombre() << " " << Alquileres[i].verCliente()->verApellido() << endl;
		cout << "Juego: " << Alquileres[i].verJuegoPrestado()->verNombre() << " Id: " << Alquileres[i].verJuegoPrestado()->verId() << endl;
		cout << "Le quedan " << Alquileres[i].verDias() << " dias restantes " << endl;
	}
}

Cliente *Administradora::BuscarClientePorId(unsigned int id)
{
	for (unsigned int i = 0; i < Clientes.size(); i++)
	{
		if (Clientes[i].verId() == id)
		{
			return &Clientes[i];
		}
	}
	return nullptr;
}

Usuario *Administradora::BuscarUsuarioPorId(unsigned int id)
{
	for (unsigned int i = 0; i < Usuarios.size(); i++)
	{
		if (Usuarios[i].verId() == id)
		{
			return &Usuarios[i];
		}
	}
	return nullptr;
}

VideoJuego *Administradora::BuscarJuegoPorId(unsigned int id)
{
	for (unsigned int i = 0; i < VideoJuegos.size(); i++)
	{
		if (VideoJuegos[i].verId() == id)
		{
			return &VideoJuegos[i];
		}
	}
	return nullptr;
}

void Administradora::actualizarHora()
{
	time_t actual;
	time(&actual);
	tm Hora;
	Hora = *localtime(&actual);
	FechaActual.tm_hour = Hora.tm_hour;
	FechaActual.tm_min = Hora.tm_min;
}

void Administradora::GuardarUsuarioActual(unsigned int id)
{
	UsuarioActivo = BuscarUsuarioPorId(id);
}

size_t Administradora::CantidadAlquileres()
{
	return Alquileres.size();
}

Usuario &Administradora::verUsuariosPosVector(int i)
{
	return Usuarios[i];
}

Cliente &Administradora::verClientesPosVector(int i)
{
	return Clientes[i];
}

VideoJuego &Administradora::verJuegosPosVector(int i)
{
	return VideoJuegos[i];
}

Alquiler &Administradora::verAlquileresPosVector(int i)
{
	return Alquileres[i];
}

size_t Administradora::CantidadUsuarios()
{
	return Usuarios.size();
}

size_t Administradora::CantidadClientes()
{
	return Clientes.size();
}

size_t Administradora::CantidadJuegos()
{
	return VideoJuegos.size();
}

Usuario *Administradora::verUsuarioActivo()
{
	return UsuarioActivo;
}
void Administradora::idJuegoActual(int pos)
{
	m_idJuegoActual = pos;
}

void Administradora::idClienteActual(int pos)
{
	m_idClienteActual = pos;
}

int Administradora::verIdJuegoActual()
{
	return m_idJuegoActual;
}

int Administradora::verIdClienteActual()
{
	return m_idClienteActual;
}

int Administradora::verIdUsuarioActual()
{
	return UsuarioActivo->verId();
}

string Administradora::verFechaActual()
{
	stringstream strFecha;
	strFecha << FechaActual.tm_mday << "/" << FechaActual.tm_mon + 1 << "/" << FechaActual.tm_year;
	return strFecha.str();
}

int Administradora::buscarPosAlquilerPorIds(unsigned int idC, unsigned int idJ)
{
	cout << "En la clase buscar" << idC << " " << idJ << endl;
	for (size_t i = 0; i < Alquileres.size(); i++)
	{
		if (Alquileres[i].verIdJuego() == idJ && Alquileres[i].verIdCliente() == idC && (Alquileres[i].verEstado() == Activo || Alquileres[i].verEstado() == Vencido))
		{
			return i;
		}
	}
}
