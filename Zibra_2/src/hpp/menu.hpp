#ifndef MENU_H_
#define MENU_H_
#include "contacto.hpp"
#include "agenda.hpp"

class Menu {
private:

public:
  int mostrarMenuPrincipal ();
  int mostrarEditarContacto (Contacto contacto);
  int mostrarEditarDirecciones ();
  int tipoVia();
  Contacto encontrarContacto (Agenda a);
};
#endif
