/***      FICHERO GESTORPERSISTENCIA.HPP         ***/

#ifndef GESTORPERSISTENCIA_H_
#define GESTORPERSISTENCIA_H_

#include <list>
#include "contacto.hpp"

class gestorPersistencia{
private:
public:
  gestorPersistencia() {};
  virtual void guardarContactos(std::list<Contacto> listaContactos) = 0;
  virtual std::list<Contacto> cargarContactos() = 0;
};

#endif
