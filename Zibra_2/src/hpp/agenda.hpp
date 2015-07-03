/*

  FICHERO AGENDA.H

*/

#ifndef AGENDA_H_
#define AGENDA_H_

#include <list>
#include <string>
#include "contacto.hpp"


class Agenda{
private:
  std::list<Contacto> contactos_;


public:
  std::list<Contacto> getContactos () {return contactos_;}
  void setContactos (std::list<Contacto> ListContactos) {contactos_ = ListContactos;}
  void insertarContacto(Contacto contacto);
  std::list<Contacto> buscarContacto(std::string apellido);
  bool eliminarContacto(std::string DNI);
  bool imprimirAgenda(int opcion);
  bool cargarCopia();
  bool guardarCopia();
  void mostrarContacto(Contacto* contacto, bool detallado);
};

#endif
