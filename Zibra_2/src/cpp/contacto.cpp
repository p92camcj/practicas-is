#include "../hpp/contacto.hpp"

void Contacto::conmutarFavorito() {
  if(getFavorito() == false) {
    setFavorito(true);
  } else {
    setFavorito(false);
  }
}

Contacto::Contacto(std::string initDNI, std::string initNombre, std::string initApellido1,
                   std::string initApellido2, std::string anotaciones, bool favorito) {
                     DNI_ = initDNI;
                     nombre_ = initNombre;
                     apellido1_ = initApellido1;
                     apellido2_ = initApellido2;
                     anotaciones_ = anotaciones;
                     favorito_ = favorito;
                     uso_ = 0;
                     redesSociales_.Twitter = "";
                     redesSociales_.Facebook = "";
                     fechaNacimiento_.dia=1;
                     fechaNacimiento_.mes=1;
                     fechaNacimiento_.anyo=1900;
                  }
