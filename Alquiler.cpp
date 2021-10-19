#include "Alquiler.h"
#include <ctime>
#include <iostream>
using namespace std;

Alquiler::Alquiler(Cliente &clien, Usuario &usua, VideoJuego &juego, int dias) {
	
	esteJuego = &juego;
	esteCliente = &clien;
	esteUsuario = &usua;
	m_estado = Activo;
	
	time_t actual;
	time(&actual);
	fecha_ini = *localtime(&actual);
	fechaActual = *localtime(&actual);
	//Le sumo a los meses y anios para que muestre la fecha actual
	fecha_ini.tm_year = fecha_ini.tm_year + 1900; 
	fechaActual.tm_year = fechaActual.tm_year + 1900; 
	cout<<endl<<fecha_ini.tm_year<<" "<<fecha_ini.tm_mon<<" "<<fecha_ini.tm_mday<<endl;
	cout<<endl<<"Fecha inicial: "<<fecha_ini.tm_mday<<" "<<fecha_ini.tm_mon<<" "<<fecha_ini.tm_year<<endl;

	
	//Aca me empieza a tirar el error, antes lo tenia como esta comentado arrib 
	fecha_fin = fecha_ini;
	agregarDias(dias);
	cout<<"Fecha final: "<<fecha_fin.tm_mday<<" "<<fecha_fin.tm_mon<<" "<<fecha_fin.tm_year<<endl;
	
	
	
	cout<<"Prestamo: "<<endl;
	cout<<"Usuario: "<<esteUsuario->verNombre()<<" "<<esteUsuario->verApellido()<<endl;
	cout<<"Cliente: "<<esteCliente->verNombre()<<" "<<esteCliente->verApellido()<<endl;
	cout<<"Juego: "<<esteJuego->verNombre()<<" Id: "<<esteJuego->verId()<<endl;
	cout<<"Le quedan "<<verDias()<<" dias restantes "<<endl;
	cout<<"Estado: "<<m_estado<<endl;
	
}


tm Alquiler::verFechaInicial ( ) {
	return fecha_ini;
}

tm Alquiler::verFechaFinal ( ) {
	return fecha_fin;
}
//Ver como hacer que esto se vaya actualizando
int Alquiler::verDias() {
	if ( fechaActual.tm_mday <= fecha_fin.tm_mday && fechaActual.tm_mon == fecha_fin.tm_mon)  
		return ((fecha_fin.tm_mday)-(fechaActual.tm_mday)); 
	else if( fechaActual.tm_mday > fecha_fin.tm_mday && fechaActual.tm_mon < fecha_fin.tm_mon){
		if ((fechaActual.tm_mon == 0) || (fechaActual.tm_mon == 2) || (fechaActual.tm_mon == 4) || (fechaActual.tm_mon == 6) || (fechaActual.tm_mon == 7) || (fechaActual.tm_mon == 9) || (fechaActual.tm_mon == 11)){
			return ((31 - fechaActual.tm_mday)+fecha_fin.tm_mday);
		}
		else if ((fechaActual.tm_mon == 3) || (fechaActual.tm_mon == 5) || (fechaActual.tm_mon == 8) || (fechaActual.tm_mon == 10)){
			return ((30 - fechaActual.tm_mday)+fecha_fin.tm_mday);
		}
		else if ( fechaActual.tm_mon == 1 ){
			return ((28 - fechaActual.tm_mday)+fecha_fin.tm_mday);
		}
	}else{
		return -1;
	}
}

Cliente * Alquiler::verCliente ( ) {
	return esteCliente;
}

Usuario * Alquiler::verUsuario ( ) {
	return esteUsuario;
}

VideoJuego * Alquiler::verJuegoPrestado ( ) {
	return esteJuego;
}

void Alquiler::agregarDias ( int dias ) {
	switch (fecha_ini.tm_mon){
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:{
			if ( (fecha_ini.tm_mday+dias) > 31 ){
				fecha_fin.tm_mon++;
				fecha_fin.tm_mday = ((fecha_ini.tm_mday + dias)-31);
				if(fecha_ini.tm_mon == 12){
					fecha_fin.tm_mon = 1;
					fecha_fin.tm_year++;
				}
			}
			else{
				fecha_fin.tm_mday = fecha_fin.tm_mday + dias;
			}
			break;
		}
		case 3:
		case 5:
		case 8:
		case 10:{
			if( (fecha_ini.tm_mday+dias) > 30){
				fecha_fin.tm_mon++;
				fecha_fin.tm_mday = ((fecha_ini.tm_mday + dias)-30);
			}
			else{
				fecha_fin.tm_mday = fecha_fin.tm_mday + dias;
			}
			break;
		}
		case 1:{
			if( (fecha_ini.tm_mday+dias) > 28){
				fecha_fin.tm_mon++;
				fecha_fin.tm_mday = ((fecha_ini.tm_mday + dias)-28);
			}
			else{
				fecha_fin.tm_mday = fecha_fin.tm_mday + dias;
			}
			break;
		}
	}
}

int Alquiler::verIdCliente ( ) {
	return esteCliente->verId();
}

int Alquiler::verIdUsuario ( ) {
	return esteUsuario->verId();
}

int Alquiler::verIdJuego ( ) {
	return esteJuego->verId();
}


Alquiler::Alquiler (Cliente & clien, Usuario & usua, VideoJuego & juego, tm ini, tm fin) {
	esteJuego = &juego;
	esteCliente = &clien;
	esteUsuario = &usua;
	
	fecha_ini = ini;
	fecha_fin = fin;
}

void Alquiler::cambiarEstado ( Estado actualizar ) {
	m_estado = actualizar;
}

Estado Alquiler::verEstado ( ) {
	return m_estado;
}

void Alquiler::finalizarEstado ( ) {
	m_estado = Terminado;
}


Alquiler::Alquiler (Cliente & clien, Usuario & usua, VideoJuego & juego, tm ini, tm fin, Estado est) {
	esteJuego = &juego;
	esteCliente = &clien;
	esteUsuario = &usua;
	
	fecha_ini = ini;
	fecha_fin = fin;
	
	time_t actual;
	time(&actual);
	fechaActual = *localtime(&actual);
	m_estado = est;
	int dias = verDias();
	if ( dias < 0 && m_estado == Activo){
		m_estado = Vencido;
	}
}

