/****       FICHERO PERSISTENCIAFICHERO.HPP       ****/
#ifndef PERSISTENCIAFICHERO_H_
#define PERSISTENCIAFICHERO_H_

#include "gestorPersistencia.hpp"
#include "contacto.hpp"
#include <string>

class persistenciaFichero: public gestorPersistencia{
private:
  std::string nombreFichero_;
public:
  void guardarContactos(std::list<Contacto> listaContactos);
  std::list<Contacto> cargarContactos();
  void setNombreFichero(std::string nombre);
  void almacenaTelefonos(std::list<unsigned long int> listaTelefonos, std::ofstream *fichero);
  void almacenaMail(std::list<std::string> listaMail, std::ofstream *fichero);
  void almacenaDirecciones(std::list<direccion> listaDirecciones, std::ofstream *fichero);
  void almacenaCitas(std::list<cita> listaCitas, std::ofstream *fichero);
};

#endif
