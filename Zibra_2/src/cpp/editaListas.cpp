#include "../hpp/contacto.hpp"
#include "../hpp/menu.hpp"
#include "../hpp/introducirDatos.hpp"
#include "../hpp/colores.hpp"
#include <unistd.h>
#include <iostream>


void modificaDireccion (Contacto *c){
  std::list<direccion>direcciones = c->getDireccionesPostales();
  Menu m;
  int bucle = 0;
  int eligeEditarDirecciones = -1;
  int nDirecciones = 0;
  int opcionDirecciones = -1;
  int tipoVia = 0;
  std::string nombreVia;
  std::string numero = "0";
  std::string codigoPostal = "0";
  std::string ciudad;
  std::string provincia;
  std::string buffer;
  if(!(direcciones.empty())){
    if (direcciones.size() > 1){
      // Imprime las Direcciones Postales existentes
      for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
        nDirecciones ++;
        std::cout << tblue;
        std::cout << nDirecciones << "--> " << (*idir).tipoVia << " " << (*idir).nombreVia << " "
        << (*idir).numero << " " << (*idir).ciudad << " "
        << (*idir).provincia << " " << (*idir).codigoPostal << std::endl;
      }

      while ((opcionDirecciones < 1) || (opcionDirecciones > nDirecciones)){
        std::cout << "Elige una dirección para modificarla: ";
        std::cout << tnormal;
        std::cin  >> opcionDirecciones;
        getline(std::cin, buffer);
      }
    }

    while (eligeEditarDirecciones != 0){
      eligeEditarDirecciones = m.mostrarEditarDirecciones ();
      if (direcciones.size() == 1){
        opcionDirecciones = 1;
      }

      if (eligeEditarDirecciones == 1){
        system ("clear");
        tipoVia = m.tipoVia();
        for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
          bucle ++;
          if (bucle == opcionDirecciones){
            if (tipoVia == 1){
              idir->tipoVia = "Calle";
              tipoVia = 0;
            }
            else if (tipoVia == 2){
              idir->tipoVia = "Avenida";
              tipoVia = 0;
            }
            else if (tipoVia == 3){
              idir->tipoVia = "Plaza";
              tipoVia = 0;
            }
            c->setDireccionesPostales (direcciones);
          }
        }
        bucle = 0;
        opcionDirecciones = -1;
      }

      else if (eligeEditarDirecciones == 2){
        system ("clear");
        std::cout << tblue;
        std::cout << "Introduce el nombre: ";
        std::cout << tnormal;
        std::cin  >> nombreVia;
        for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
          bucle ++;
          if (bucle == opcionDirecciones){
            idir->nombreVia = nombreVia;
            c->setDireccionesPostales (direcciones);
          }
        }
      }
      else if (eligeEditarDirecciones == 3){
        system ("clear");
        while (atoi(numero.c_str()) <= 0){
          std::cout << tblue;
          std::cout << "Introduce el número: ";
          std::cout << tnormal;
          std::cin  >> numero;
        }
        for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
          bucle ++;
          if (bucle == opcionDirecciones){
            idir->numero = numero;
            c->setDireccionesPostales (direcciones);
          }
        }
        numero = "0";
      }
      else if (eligeEditarDirecciones == 4){
        system ("clear");
        while (atoi(codigoPostal.c_str()) <= 0){
          std::cout << tblue;
          std::cout << "Introduce el códigoPostal: ";
          std::cout << tnormal;
          std::cin  >> codigoPostal;
        }
        for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
          bucle ++;
          if (bucle == opcionDirecciones){
            idir->codigoPostal = codigoPostal;
            c->setDireccionesPostales (direcciones);
          }
        }
        codigoPostal = "0";

      }
      else if (eligeEditarDirecciones == 5){
        system ("clear");
        std::cout << tblue;
        std::cout << "Introduce la ciudad: ";
        std::cout << tnormal;
        std::cin  >> ciudad;
        for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
          bucle ++;
          if (bucle == opcionDirecciones){
            idir->ciudad = ciudad;
            c->setDireccionesPostales (direcciones);
          }
        }
      }
      else if (eligeEditarDirecciones == 6){
        system ("clear");
        std::cout << tblue;
        std::cout << "Introduce la provincia: ";
        std::cout << tnormal;
        std::cin  >> provincia;
        for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
          bucle ++;
          if (bucle == opcionDirecciones){
            idir->provincia = provincia;
            c->setDireccionesPostales (direcciones);
          }
        }
      }
    }
    eligeEditarDirecciones = -1;
  }
  else{
    system ("clear");
    std::cout << tblue;
    std::cout << "La lista de direcciones está vacía. No se puede modificar.";
    std::cout << tnormal;
    std::cout.flush();  // Funciona como fflush () en C.
    usleep (1600000);
  }
}

void eliminaDireccion  (Contacto *c){
  std::list<direccion>direcciones = c->getDireccionesPostales();
  int bucle = 0;
  int nDirecciones = 0;
  int borrarDireccion = -1;

  if(!(direcciones.empty())){
      // Imprime las Direcciones Postales existentes
      for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
        nDirecciones ++;
        std::cout << tblue;
        std::cout << nDirecciones << "--> " << (*idir).tipoVia << " " << (*idir).nombreVia << " "
        << (*idir).numero << " " << (*idir).ciudad << " "
        << (*idir).provincia << " " << (*idir).codigoPostal << std::endl;
      }

      while ((borrarDireccion < 0) || (borrarDireccion > nDirecciones)){
        std::cout << tblue;
        std::cout << "Elige una dirección para borrarla. Escriba 0 para no borrar ninguna: ";
        std::cout << tnormal;
        std::cin  >> borrarDireccion;
      }

    if (borrarDireccion != 0){
      for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir){
        bucle ++;
        if (bucle == borrarDireccion){
          idir = direcciones.erase (idir);
          c->setDireccionesPostales (direcciones);
        }
      }
      bucle = 0;
      borrarDireccion = -1;
    }
  }
  else{
    std::cout << tblue;
    std::cout << "La lista de direcciones está vacía. No se puede modificar.";
    std::cout << tnormal;
    std::cout.flush();  // Funciona como fflush () en C.
    usleep (1600000);
  }
}

void modificaTelefono  (Contacto *c){
  std::list<unsigned long int> telefonos = c->getTelefonos ();
  int bucle = 0;
  int nTelefonos = 0;
  int opcionTelefonos = -1;
  unsigned long int numero = 0;

  if(!(telefonos.empty())){
    if (telefonos.size() > 1){
      // Imprime los teléfonos existentes
      for (auto itel=telefonos.begin(), jtel=telefonos.end();itel!=jtel;++itel){
        nTelefonos ++;
        std::cout << tblue;
        std::cout << nTelefonos << "--> " << *itel << std::endl;
      }

      while ((opcionTelefonos < 1) || (opcionTelefonos > nTelefonos)){
        std::cout << tblue;
        std::cout << "Elige un teléfono para modificarla: ";
        std::cout << tnormal;
        std::cin  >> opcionTelefonos;
      }
    }

    system ("clear");

    while (numero <= 0){
      std::cout << tblue;
      std::cout << "Introduce el numero: ";
      std::cout << tnormal;
      std::cin  >> numero;
    }

    for (auto itel=telefonos.begin(), jtel=telefonos.end();itel!=jtel;++itel){
      bucle ++;
      if (bucle == opcionTelefonos){
          *itel = numero;
          numero = -1;
        c->setTelefonos (telefonos);
      }
    }
    bucle = 0;
    opcionTelefonos = -1;
  }

  else{
    system ("clear");
    std::cout << tblue;
    std::cout << "La lista de teléfonos está vacía. No se puede modificar.";
    std::cout << tnormal;
    std::cout.flush();  // Funciona como fflush () en C.
    usleep (1600000);
  }
}


void eliminaTelefono (Contacto *c){
  std::list<unsigned long int> telefonos = c->getTelefonos ();
  int bucle = 0;
  int nTelefonos = 0;
  int borrarTelefono = -1;

  if(!(telefonos.empty())){
    // Imprime las Teléfonos existentes
    for (auto itel=telefonos.begin(), jtel=telefonos.end();itel!=jtel;++itel){
      nTelefonos ++;
      std::cout << tblue;
      std::cout << nTelefonos << "--> " << *itel << std::endl;
    }

    while ((borrarTelefono < 0) || (borrarTelefono > nTelefonos)){
      std::cout << tblue;
      std::cout << "Elige un teléfono para borrarlo. Escriba 0 para no borrar ninguna: ";
      std::cout << tnormal;
      std::cin  >> borrarTelefono;
    }

    if (borrarTelefono != 0){
      for (auto itel=telefonos.begin(), jtel=telefonos.end();itel!=jtel;++itel){
        bucle ++;
        if (bucle == borrarTelefono){
          itel = telefonos.erase (itel);
          c->setTelefonos (telefonos);
        }
      }
      bucle = 0;
      borrarTelefono = -1;
    }
  }
  else{
    std::cout << tblue;
    std::cout << "La lista de direcciones está vacía. No se puede modificar.";
    std::cout << tnormal;
    std::cout.flush();  // Funciona como fflush () en C.
    usleep (1600000);
  }
}

void modificaCorreo (Contacto *c){
  std::list<std::string> correos = c->getCorreosElectronicos ();
  int bucle = 0;
  int nCorreos = 0;
  int opcionCorreos = -1;
  std::string correo;

  if(!(correos.empty())){
      // Imprime los teléfonos existentes
      for (auto icor=correos.begin(), jcor=correos.end();icor!=jcor;++icor){
        nCorreos ++;
        std::cout << tblue;
        std::cout << nCorreos << "--> " << *icor << std::endl;
      }

      while ((opcionCorreos < 1) || (opcionCorreos > nCorreos)){
        std::cout << tblue;
        std::cout << "Elige un correo para modificarlo: ";
        std::cout << tnormal;
        std::cin  >> opcionCorreos;
      }

    system ("clear");
    std::cout << tblue;
    std::cout << "Introduce el correo: ";
    std::cout << tnormal;
    std::cin  >> correo;

    for (auto icor=correos.begin(), jcor=correos.end();icor!=jcor;++icor){
      bucle ++;
      if (bucle == opcionCorreos){
        *icor = correo;
        c->setCorreosElectronicos (correos);
      }
    }
    bucle = 0;
    opcionCorreos = -1;
  }

  else{
    system ("clear");
    std::cout << tblue;
    std::cout << "La lista de correos está vacía. No se puede modificar.";
    std::cout << tnormal;
    std::cout.flush();  // Funciona como fflush () en C.
    usleep (1600000);
  }
}

void eliminaCorreo (Contacto *c){
  std::list<std::string> correos = c->getCorreosElectronicos ();
  int bucle = 0;
  int nCorreos = 0;
  int borrarCorreo = -1;
  std::string correo;

  if(!(correos.empty())){
    // Imprime las Teléfonos existentes
    for (auto icor=correos.begin(), jcor=correos.end();icor!=jcor;++icor){
      nCorreos ++;
      std::cout << tblue;
      std::cout << nCorreos << "--> " << *icor << std::endl;
    }

    while ((borrarCorreo < 0) || (borrarCorreo > nCorreos)){
      std::cout << tblue;
      std::cout << "Elige un correo para borrarlo. Escriba 0 para no borrar ninguno: ";
      std::cout << tnormal;
      std::cin  >> borrarCorreo;
    }

    if (borrarCorreo != 0){
      for (auto icor=correos.begin(), jcor=correos.end();icor!=jcor;++icor){
        bucle ++;
        if (bucle == borrarCorreo){
          icor = correos.erase (icor);
          c->setCorreosElectronicos (correos);
        }
      }
      bucle = 0;
      borrarCorreo = -1;
    }
  }
  else{
    std::cout << tblue;
    std::cout << "La lista de correos está vacía. No se puede modificar.";
    std::cout << tnormal;
    std::cout.flush();  // Funciona como fflush () en C.
    usleep (1600000);
  }
}
