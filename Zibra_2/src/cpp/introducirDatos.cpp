#include "../hpp/colores.hpp"
#include <string>
#include <iostream>
#include "../hpp/contacto.hpp"
#include <unistd.h> //Para usleep
#include <cstring>
#include <cstdlib>

void introduceDNI (Contacto *c){
  std::string camposContacto;
  std::string buffer;
  std::cout << tblue;
  std::cout << "DNI: ";
  std::cout << tnormal;
  std::cin  >> camposContacto;
  getline(std::cin, buffer);
  if (camposContacto != "-1"){
    c->setDNI(camposContacto);
  }
}

void introduceNombre (Contacto *c){
  std::string camposContacto;
  std::cout << tblue;
  std::cout << "Nombre: ";
  std::cout << tnormal;
  getline(std::cin, camposContacto);
  if (camposContacto != "-1"){
    c->setNombre(camposContacto);
  }
}
void introduceApellido1 (Contacto *c){
  std::string camposContacto;
  std::cout << tblue;
  std::cout << "Apellido 1: ";
  std::cout << tnormal;
  getline(std::cin, camposContacto);
  if (camposContacto != "-1"){
    c->setApellido1(camposContacto);
  }
}
void introduceApellido2 (Contacto *c){
  std::string camposContacto;
  std::cout << tblue;
  std::cout << "Apellido 2: ";
  std::cout << tnormal;
  getline(std::cin, camposContacto);
  if (camposContacto != "-1"){
    c->setApellido2(camposContacto);
  }
}

void introduceAnotacion (Contacto *c){
  std::string camposContacto;
  std::cout << tblue;
  std::cout << "Anotación: ";
  std::cout << tnormal;
  getline(std::cin, camposContacto);
  if (camposContacto != "-1"){
    c->setAnotaciones(camposContacto);
  }
}

void introduceFavorito (Contacto *c){
  int favorito = -1;
  std::string buffer;
  while ((favorito != 0) && (favorito != 1)){
    std::cout << tblue;
    std::cout << "¿Es un contacto favorito?\n";
    std::cout << "    1. Sí.\n";
    std::cout << "    0. No.\n";
    std::cout << "  Elija: ";
    std::cout << tnormal;
    std::cin  >> favorito;
    getline(std::cin, buffer);
    if (favorito == 0){
      c->setFavorito(false);
    }
    else if (favorito == 1){
      c->setFavorito(true);
    }
  }
}

void introduceTelefonos (Contacto *c){
  long int telefonoContacto = 0;
  std::string buffer;
  std::list<unsigned long int>ListaTelefonosContacto;
  int i = 0;
  std::cout << tblue;
  std::cout << "Telefonos:\n";
  while (telefonoContacto != -1){
    i++;
    std::cout << tblue;
    std::cout << "  Teléfono " << i << ": ";
    std::cout << tnormal;
    std::cin  >> telefonoContacto;
    getline(std::cin, buffer);
    if(telefonoContacto != -1){
      ListaTelefonosContacto.push_back (telefonoContacto);
    }
  }
  c->setTelefonos (ListaTelefonosContacto);
}

void introduceCorreo (Contacto *c){
  std::string camposContacto = "0";
  std::string buffer;
  std::list<std::string>ListaCorreosContacto;
  int i = 0;
  std::cout << tblue;
  std::cout << "Correos Electrónicos:\n";
  while (camposContacto != "-1"){
    i ++;
    std::cout << tblue;
    std::cout << "  Correo Electrónico " << i << ": ";
    std::cout << tnormal;
    std::cin  >> camposContacto;
    getline(std::cin, buffer);
    if(camposContacto != "-1"){
      ListaCorreosContacto.push_back (camposContacto);
    }
  }
  c->setCorreosElectronicos (ListaCorreosContacto);
}

void introduceDirecciones (Contacto *c){
  std::string camposContacto;
  std::string buffer;
  struct direccion structListaDirecciones;
  std::string tipoVia = "0";
  std::string nVia = "0";
  std::string cPostal = "0";
  std::list<direccion>listaDireccionesContacto;
  int i = 0;
  std::cout << tblue;
  std::cout << "Direcciones Postales:\n";
  while (tipoVia != "-1"){
    i ++;
    while ((tipoVia != "-1") && (tipoVia != "1") && (tipoVia != "2") && (tipoVia != "3")){
      std::cout << tblue;
      std::cout << "Vía " << i << ":\n";
      std::cout << "    1. Calle.\n";
      std::cout << "    2. Avenida.\n";
      std::cout << "    3. Plaza.\n";
      std::cout << "  Elija: ";
      std::cout << tnormal;
      std::cin  >> tipoVia;
      getline(std::cin, buffer);
    }

    if (tipoVia != "-1"){
      if (tipoVia == "1"){
        structListaDirecciones.tipoVia = "Calle";
        tipoVia = "0";
      }
      else if (tipoVia == "2"){
        structListaDirecciones.tipoVia = "Avenida";
        tipoVia = "0";
      }
      else if (tipoVia == "3"){
        structListaDirecciones.tipoVia = "Plaza";
        tipoVia = "0";
      }

      std::cout << tblue;
      std::cout << "Introduce el nombre de la " << structListaDirecciones.tipoVia << ": ";
      std::cout << tnormal;
      getline(std::cin, camposContacto);
      structListaDirecciones.nombreVia = camposContacto;

      while (atoi(nVia.c_str()) <= 0){
        std::cout << tblue;
        std::cout << "Introduce el número: ";
        std::cout << tnormal;
        std::cin  >> nVia;
        getline(std::cin, buffer);
      }
      structListaDirecciones.numero = nVia;

      nVia = "0";

      while (atoi(cPostal.c_str()) <= 0){
        std::cout << tblue;
        std::cout << "Introduce el Código Postal: ";
        std::cout << tnormal;
        std::cin  >> cPostal;
        getline(std::cin, buffer);
      }
      structListaDirecciones.codigoPostal = cPostal;

      cPostal = "0";

      std::cout << tblue;
      std::cout << "Introduce la ciudad: ";
      std::cout << tnormal;
      getline(std::cin, camposContacto);
      structListaDirecciones.ciudad = camposContacto;

      std::cout << tblue;
      std::cout << "Introduce la provincia: ";
      std::cout << tnormal;
      getline(std::cin, camposContacto);
      structListaDirecciones.provincia = camposContacto;


      listaDireccionesContacto.push_back (structListaDirecciones);
    }
    if (atoi(tipoVia.c_str()) == -1){
      c->setDireccionesPostales(listaDireccionesContacto);
    }
  }

  tipoVia = "0";
}

void introduceRedesSociales (Contacto *c){
  struct redSocial redesSociales;
  std::string buffer;
  std::string twitter;
  std::string facebook;
  std::cout << tblue;
  std::cout << "Twitter ";
  std::cout << tyellow;
  std::cout << "(sin @): ";
  std::cout << tnormal;
  std::cin  >> twitter;
  getline(std::cin, buffer);

  std::cout << tblue;
  std::cout << "Facebook: ";
  std::cout << tnormal;
  getline(std::cin, facebook);

  if (twitter != "-1"){
    redesSociales.Twitter = twitter;
  }
  if (facebook != "-1"){
    redesSociales.Facebook = facebook;
  }

  c->setRedesSociales (redesSociales);
}

void introduceFoto (Contacto *c){
  std::string foto;
  std::string buffer;
  std::cout << tblue;
  std::cout << "Introduzca una URL de una foto. ";
  std::cout << tyellow;
  std::cout << "(Para pegar texto desde portapapeles en terminal pulse Ctrl + Shift + V): ";
  std::cout << tnormal;
  std::cin  >> foto;
  getline(std::cin, buffer);

  if (foto != "-1"){
    c->setFoto(foto);
  }
  c->setFoto(foto);
}

struct fecha introduceFecha ()
{
  struct fecha fecha;
  std::string buffer;
  int dia;
  int mes;
  int anyo;
  
  
 
  do{
  std::cout << tblue;
  std::cout << "\tDía ";
  std::cout << tyellow;
  std::cout << "(1-31): ";
  std::cout << tnormal;
  std::cin  >> dia;
  getline(std::cin, buffer);
  } while((dia<1 || dia>31) && dia!=-1);

  do{
  std::cout << tblue;
  std::cout << "\tMes ";
  std::cout << tyellow;
  std::cout << "(1-12): ";
  std::cout << tnormal;
  std::cin  >> mes;
  getline(std::cin, buffer);
  } while((mes<1 || mes>12) && mes!=-1);
  
  do{
  std::cout << tblue;
  std::cout << "\tAño ";
  std::cout << tyellow;
  std::cout << "(1900-20XX): ";
  std::cout << tnormal;
  std::cin  >> anyo;
  getline(std::cin, buffer);
  } while((anyo<1900 || anyo>2100) && anyo!=-1);

  if (dia != -1){
    fecha.dia = dia;
  }
  if (mes != -1){
    fecha.mes = mes;
  }
  if (anyo != -1){
    fecha.anyo = anyo;
  }
  
  return fecha;
}


void introduceFechaNacimiento (Contacto *c){

  std::cout << tblue;
  std::cout << "Fecha de nacimiento: "<< std::endl;
  
  c->setFechaNacimiento (introduceFecha());
}


void introduceCitas (Contacto *c){
  std::string motivoCita;
  std::string buffer;
  
  struct cita structListaCitas;
  std::string horas = "-1";
  std::string minutos = "-1";
  std::string tipoCita = "0";
  

  std::list<cita>listaCitasContacto;
  int i = 0;
  std::cout << tblue;
  std::cout << "Citas del contacto:\n";
  while (tipoCita != "-1"){
    i ++;
    
    
    // Motivo de la cita
    while ((tipoCita != "-1") && (tipoCita != "1") && (tipoCita != "2") && (tipoCita != "3")){
      std::cout << tblue;
      std::cout << "Motivo de la Cita " << i << ":\n";
      std::cout << "    1. Revisión.\n";
      std::cout << "    2. Urgencia.\n";
      std::cout << "    3. Otro Motivo.\n";
      std::cout << "   -1. No quiero más citas.\n";
      std::cout << "  Elija: ";
      std::cout << tnormal;
      std::cin  >> tipoCita;
      getline(std::cin, buffer);
    }

    if (tipoCita != "-1"){
      if (tipoCita == "1"){
        structListaCitas.tipoCita = "Revisión";
        tipoCita = "0";
      }
      else if (tipoCita == "2"){
        structListaCitas.tipoCita = "Urgencia";
        tipoCita = "0";
      }
      else if (tipoCita == "3"){
        structListaCitas.tipoCita = "Otro Motivo";
        tipoCita = "0";
        std::cout << tblue;
        std::cout << "Introduce el motivo de la cita : ";
        std::cout << tnormal;
        getline(std::cin, motivoCita);
        structListaCitas.tipoCita = motivoCita;
      }


      // Fecha de la cita
      std::cout << tblue;
      std::cout << "Fecha de la cita: "<< std::endl;
      structListaCitas.fecha = introduceFecha();
      

      // Hora de la cita
      while (atoi(horas.c_str()) < 0 || atoi(horas.c_str()) >= 24 ){
        std::cout << tblue;
        std::cout << "Introduce la hora de la cita (24h): ";
        std::cout << tnormal;
        std::cin  >> horas;
        getline(std::cin, buffer);
      }
      structListaCitas.hora.horas = horas;
      horas = "-1";

      // Minutos de la cita
      while (atoi(minutos.c_str()) < 0 || atoi(minutos.c_str()) >= 60){
        std::cout << tblue;
        std::cout << "Introduce la fracción de hora, minutos (05, 10, 30, 55, etc): ";
        std::cout << tnormal;
        std::cin  >> minutos;
        getline(std::cin, buffer);
      }
      structListaCitas.hora.minutos = minutos;
      minutos = "-1";


      //Guardamos la cita en la lista de citas del contacto
      listaCitasContacto.push_back (structListaCitas);
    }
    if (atoi(tipoCita.c_str()) == -1){
      c->setCitas(listaCitasContacto);
      
      
    }
  }
  c->setCitas(listaCitasContacto);
  tipoCita = "0";
  
}




