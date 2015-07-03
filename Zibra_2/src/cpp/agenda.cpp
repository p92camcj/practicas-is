/*

FICHERO AGENDA.CC

*/

#include "../hpp/agenda.hpp"
#include "../hpp/contacto.hpp"
#include <list>
#include <iostream>
#include <fstream>
#include "../hpp/colores.hpp"

void Agenda::insertarContacto(Contacto contacto){
  contactos_.push_back(contacto);
}


std::list<Contacto> Agenda::buscarContacto(std::string nombre){
    std::list<Contacto>::iterator it;
    std::list<Contacto> aux;
    for(it=contactos_.begin(); it!=contactos_.end(); it++){
      if((*it).getNombre() == nombre){
        aux.push_back(*it);
      }
    }
    return aux;
}

bool Agenda::eliminarContacto(std::string DNI){
  std::list<Contacto>::iterator it;

  for(it=contactos_.begin(); it!=contactos_.end(); it++){
    if((*it).getDNI() == DNI){
      contactos_.erase(it);
      return true;
    }
  }
  return false;
}

bool Agenda::imprimirAgenda(int opcion){
  bool salida = false;
  std::list<Contacto>::iterator it;
  std::list<Contacto> aux;
  aux = contactos_;
  int nContactos;
  if(opcion == 0){//Impresión por pantalla
    aux.sort( [](const Contacto &c1, const Contacto &c2) { return c1.getApellido1()+" "+c1.getApellido2() < c2.getApellido1()+" "+c2.getApellido2(); } );
    for(it=aux.begin(); it!=aux.end(); it++){
      nContactos ++;

      if (nContactos % 2 == 0)
      {
        std::cout << tcyan;
      }
      else
      {
        std::cout << tpurple;
      }
      std::cout << std::endl;
      mostrarContacto(&(*it),0);
    }
    salida = true;
  }
  else if(opcion == 1){ //Impresión HTML (GENERAMOS UN JSON)
    std::ofstream archivo;
    //ITERADORES
    std::list<Contacto>::iterator auxit; //Auxiliar para poder aumentarlo, para conocer el ult. elemento
    std::list<std::string>::iterator imail; //Obtener el primer nodo de la lista de mails
    std::list<unsigned long int>::iterator itel; //Obtener el primer nodo de la lista de telefonos
    std::list<direccion>::iterator idir; //Obtener el primer nodo de la lista de telefonos
    std::list<cita>::iterator icit; //Obtener el primer nodo de la lista de citas
    //-----------
    struct redSocial redes;
    struct fecha fechaNacimiento;
    std::string datos[] = {"DNI", "nombre", "apellido1", "apellido2",
    "favorito", "anotaciones", "mail", "telefono",
    "direccion", "codigoPostal", "ciudad", "provincia",
    "fechaNacimiento_dia", "fechaNacimiento_mes", "fechaNacimiento_anyo",
    "facebook", "twitter", "foto", "tipoCita", "fecha_dia", "fecha_mes", "fecha_anyo", 

    };
    archivo.open("datos.json");
    if(archivo.is_open()){
      archivo << "[" << std::endl;
      for(it=aux.begin(); it!=aux.end(); it++){
        archivo << "{" << std::endl;
        if((*it).getDNI() != ""){
          archivo << '\"' + datos[0] +  '\"' + ':' + '\"' + (*it).getDNI() + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[0] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }

        if((*it).getNombre() != ""){
          archivo << '\"' + datos[1] +  '\"' + ':' + '\"' + (*it).getNombre() + '.' + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[1] +  '\"' + ':' + '\"' + '0' + '.' + '\"' + ',' << std::endl;
        }

        if((*it).getApellido1() != ""){
          archivo << '\"' + datos[2] +  '\"' + ':' + '\"' + (*it).getApellido1() + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[2] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }


        if((*it).getApellido2() != ""){
          archivo << '\"' + datos[3] +  '\"' + ':' + '\"' + (*it).getApellido2() + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[3] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }

        if((*it).getFavorito()){
          archivo << '\"' + datos[4] +  '\"' + ':' + " 1" + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[4] +  '\"' + ':' + " 0" + ',' << std::endl;
        }
        archivo << '\"' + datos[5] +  '\"' + ':' + '\"' + (*it).getAnotaciones() + '\"' + ',' << std::endl;

        //OBTENEMOS LOS DATOS DE LAS LISTAS (PRIMER NODO)
        //CORREO ELECTRONICO
        if (!(*it).getCorreosElectronicos().empty()){
          imail = ((*it).getCorreosElectronicos()).begin();
          if((*imail) != ""){
            archivo << '\"' + datos[6] +  '\"' + ':' + '\"' + (*imail) + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[6] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }
        }
        //TELEFONO
        if (!(*it).getTelefonos().empty()){
          itel = ((*it).getTelefonos()).begin();
          if(std::to_string((*itel)) != ""){
            archivo << '\"' + datos[7] +  '\"' + ':' + '\"' + std::to_string((*itel)) + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[7] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }
        }

        //DIRECCION
        if (!(*it).getDireccionesPostales().empty()){
          idir = ((*it).getDireccionesPostales()).begin();
          if((*idir).tipoVia == "" || (*idir).nombreVia == "" || (*idir).numero == ""){
            archivo << '\"' + datos[8] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[8] +  '\"' + ':' + '\"' + (*idir).tipoVia;
            archivo << ' ';
            archivo << (*idir).nombreVia;
            archivo << ',';
            archivo << ' ' + (*idir).numero + '.' + '\"' + ',' << std::endl;
          }


          //Almacenamos codigo postal, ciudad y provincia por separado. (DE LA LISTA DE DIRECCIONES)
          //CODIGO POSTAL
          if((*idir).codigoPostal != ""){
            archivo << '\"' + datos[9] +  '\"' + ':' + '\"' + (*idir).codigoPostal + '.' + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[9] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }

          //CIUDAD
          if((*idir).ciudad != ""){
            archivo << '\"' + datos[10] +  '\"' + ':' + '\"' + (*idir).ciudad + ',' + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[10] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }

          //PROVINCIA
          if((*idir).provincia != ""){
            archivo << '\"' + datos[11] +  '\"' + ':' + '\"' + (*idir).provincia + '.' + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[11] +  '\"' + ':' + '\"' + '0' + '.' + '\"' + ',' << std::endl;
          }
        }
        
        fechaNacimiento = (*it).getFechaNacimiento();
        //DÍA
        if(std::to_string(fechaNacimiento.dia) != ""){
          archivo << '\"' + datos[12] +  '\"' + ':' + '\"' + std::to_string(fechaNacimiento.dia) + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[12] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }
        //MES
        if(std::to_string(fechaNacimiento.mes) != ""){
          archivo << '\"' + datos[13] +  '\"' + ':' + '\"' + std::to_string(fechaNacimiento.mes) + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[13] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }
        //ANYO
        if(std::to_string(fechaNacimiento.anyo) != ""){
          archivo << '\"' + datos[14] +  '\"' + ':' + '\"' + std::to_string(fechaNacimiento.anyo) + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[14] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }
        
        
        redes = (*it).getRedesSociales();
        //FACEBOOK
        if(redes.Facebook != ""){
          archivo << '\"' + datos[15] +  '\"' + ':' + '\"' + redes.Facebook + '\"' + ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[15] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
        }
        //TWITTER
        if(redes.Twitter != ""){
          archivo << '\"' + datos[16] +  '\"' + ':' + '\"' + redes.Twitter + '\"' << ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[16] +  '\"' + ':' + '\"' + '0' + '\"' << ',' << std::endl;
        }

        //FOTO
        if((*it).getFoto() != ""){
          archivo << '\"' + datos[17] +  '\"' + ':' + '\"' + (*it).getFoto() + '\"' << ',' << std::endl;
        }
        else{
          archivo << '\"' + datos[17] +  '\"' + ':' + '\"' + '0' + '\"' << ',' << std::endl;
        }
        
        
        
        //CITA     
        if (!(*it).getCitas().empty()){
          icit = ((*it).getCitas()).begin();
          
          //Motivo cita
          if((*icit).tipoCita == "" ){
            archivo << '\"' + datos[18] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[18] +  '\"' + ':' + '\"' + (*icit).tipoCita + '\"' << ',' << std::endl;
     
          }


          //Almacenamos fecha_dia, fecha_mes y fecha_anyo por separado. (DE LA LISTA DE CITAS)
          //Fecha dia
          if(std::to_string((*icit).fecha.dia) != ""){
            archivo << '\"' + datos[19] +  '\"' + ':' + '\"' + std::to_string((*icit).fecha.dia) + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[19] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }
          
          //Fecha mes
          if(std::to_string((*icit).fecha.mes) != ""){
            archivo << '\"' + datos[20] +  '\"' + ':' + '\"' + std::to_string((*icit).fecha.mes) + '\"' + ',' << std::endl;
          }
          else{
            archivo << '\"' + datos[20] +  '\"' + ':' + '\"' + '0' + '\"' + ',' << std::endl;
          }
          
          //Fecha anyo
          if(std::to_string((*icit).fecha.anyo) != ""){
            archivo << '\"' + datos[21] +  '\"' + ':' + '\"' + std::to_string((*icit).fecha.anyo) + '\"'  << std::endl;
          }
          else{
            archivo << '\"' + datos[21] +  '\"' + ':' + '\"' + '0' + '\"'  << std::endl;
          }

        }
        
      


        //Comprobamos si es el ultimo elemento para poner coma o no al corchete
        auxit = it;
        if((++auxit) != aux.end()){
          archivo << "}," << std::endl;
        }
        else{
          archivo << "}" << std::endl;
        }
      }
      archivo << "]";
      archivo.close();
    }
  }

  return salida;
}



void Agenda::mostrarContacto(Contacto* contacto, bool detallado){
  std::list<std::string>correos = (*contacto).getCorreosElectronicos();
  std::list<unsigned long int>telefonos = (*contacto).getTelefonos();
  std::list<direccion>direcciones = (*contacto).getDireccionesPostales();
  std::list<cita>citas = (*contacto).getCitas();
  struct redSocial redes;
  struct fecha fechaNacimiento;
  (*contacto).aumentarUso();
  std::cout << "   DNI: " << (*contacto).getDNI() << std::endl;
  std::cout << "   Nombre: " << (*contacto).getNombre() << std::endl;
  std::cout << "   Apellidos: " << (*contacto).getApellido1() + ' ' + (*contacto).getApellido2() << std::endl;
  if(detallado){
    std::cout << "   Anotaciones: " << (*contacto).getAnotaciones() << std::endl;
    std::cout << "   Favorito: ";
    if((*contacto).getFavorito()){
      std::cout << "Sí" << std::endl;
    }
    else{
      std::cout << "No" << std::endl;
    }
    std::cout << "   Uso: " << (*contacto).getUso() << std::endl;

    //MUESTRA MAILS
    std::cout << "---Correos electronicos---" << std::endl;
    if(!(correos.empty())){
      for(auto imail=correos.begin(), jmail=correos.end(); imail!=jmail; imail++){
        std::cout << "   " << (*imail) << std::endl;
      }
    }
    else
    {
      std::cout << "   VACIO    " << std::endl;
    }

    //MUESTRA TELEFONOS
    std::cout << "---------Telefonos--------" << std::endl;
    if(!(telefonos.empty())){
      for(auto itel=telefonos.begin(), jtel=telefonos.end(); itel!=jtel; ++itel){
        std::cout << "   " << (*itel) << std::endl;
      }
    }
    else
    {
      std::cout << "   VACIO    " << std::endl;
    }

    //MUESTRA DIRECCIONES POSTALES
    std::cout << "---Direcciones postales---" << std::endl;
    if(!(direcciones.empty())){
      for (auto idir=direcciones.begin(), jdir=direcciones.end();idir!=jdir;++idir) {
        std::cout << " " << (*idir).tipoVia << " " << (*idir).nombreVia << " "
        << (*idir).numero << " " << (*idir).ciudad << " "
        << (*idir).provincia << " " << (*idir).codigoPostal << std::endl;
      }
    }
    else
    {
      std::cout << "   VACIO    " << std::endl;
    }
    
    //MUESTRA FECHAS
    std::cout << "---Fechas del contacto---" << std::endl;
    fechaNacimiento = (*contacto).getFechaNacimiento();
    std::cout << "   Fecha de Nacimiento: " << fechaNacimiento.dia << "/" << fechaNacimiento.mes << "/" << fechaNacimiento.anyo << std::endl;
    
    std::cout << "---Próximas Citas del contacto---" << std::endl;
}//fin del if(detallado) primero

    //MUESTRA CITAS
    
    citas = (*contacto).getCitas();
    if(!(citas.empty())){
      for (auto icit=citas.begin(); icit!=citas.end(); ++icit) {
        std::cout << "   " << (*icit).tipoCita << " -> " 
        << (*icit).fecha.dia << "/" << (*icit).fecha.mes << "/" << (*icit).fecha.anyo << " - "
        << (*icit).hora.horas << ":" << (*icit).hora.minutos <<  std::endl;
      }
    }
    else
    {
      std::cout << "   VACIO    " << std::endl;
    }

if(detallado){
    //MUESTRA REDES SOCIALES
    redes = (*contacto).getRedesSociales();
    std::cout << "------Redes sociales------" << std::endl;
    std::cout << "   Facebook: " << redes.Facebook << std::endl;
    std::cout << "   Twitter: " << redes.Twitter << std::endl;
  }

}
