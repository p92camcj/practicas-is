#include "../hpp/menu.hpp"
#include "../hpp/contacto.hpp" //Se necesita para saber si un contacto es o no favorito.
#include "../hpp/agenda.hpp" // Se necesita para poder buscar por apellido
#include "../hpp/colores.hpp"
#include <cstdlib>  // Para poder usar system ()
#include <iostream> // Para poder usar cout
#include <string>
#include <list>

int Menu::mostrarMenuPrincipal (){
  int option;
  std::string buffer;
  system ("clear"); // Limpia la pantalla

  //Pone el texto en azul e imprime el menú
  std::cout << tblue;
  std::cout << "¿Qué desea?\n";
  std::cout << "   1. Insertar un nuevo contacto.\n";
  std::cout << "   2. Insertar una nueva cita.\n";
  std::cout << "   3. Guardar copia de seguridad.\n";
  std::cout << "   4. Mostrar contacto.\n";
  std::cout << "   5. Editar contacto.\n";
  std::cout << "   6. Eliminar contacto.\n";
  std::cout << "   7. Mostrar agenda.\n";
  std::cout << "   8. Cargar copia de seguridad.\n";
  std::cout << "   0. SALIR.\n\n";
  std::cout << "Elija una opción: ";
  std::cout << tnormal; // Establece la letra a default

  std::cin >> option;
  getline(std::cin, buffer);
  return (option);
}

int Menu::mostrarEditarContacto (Contacto contacto){
  int option;
  system ("clear"); // Limpia la pantalla

  //Pone el texto en azul e imprime el menú de Editar Contacto
  std::cout << tblue;
  std::cout << "¿Qué desea?\n";
  std::cout << "   1. Modificar DNI\n";
  std::cout << "   2. Modificar nombre.\n";
  std::cout << "   3. Modificar primer apellido.\n";
  std::cout << "   4. Modificar segundo apellido.\n";
  std::cout << "   5. Modificar la anotación\n";
  std::cout << "   6. Modificar la dirección.\n";
  std::cout << "   7. Modificar la lista de teléfonos.\n";
  std::cout << "   8. Modificar la lista de correos electrónicos.\n";
  std::cout << "   9. Modificar la fecha de nacimiento.\n";
  std::cout << "   10. Modificar la cuenta de Twitter.\n";
  std::cout << "   11. Modificar la cuenta de Facebook.\n";
  std::cout << "   12. Modificar la foto.\n";
  if (contacto.getFavorito()){
    std::cout << tred; // Establece la letra a rojo
    std::cout << "   13. Eliminar como favorito\n";
  }
  else{
    std::cout << tyellow; // Establece la letra amarillo
    std::cout << "   13. Establecer favorito\n";
  }
  std::cout << tblue;
  std::cout << "   0. SALIR.\n\n";
  std::cout << "Elija una opción: ";
  std::cout << tnormal; // Establece la letra a default

  std::cin >> option;
  return (option);
}

int Menu::mostrarEditarDirecciones (){
  int option;
  system ("clear"); // Limpia la pantalla

  //Pone el texto en azul e imprime el menú de Editar Contacto
  std::cout << tblue;
  std::cout << "¿Qué desea?\n";
  std::cout << "   1. Modificar el tipo de vía\n";
  std::cout << "   2. Modificar el nombre de la vía.\n";
  std::cout << "   3. Modificar el número.\n";
  std::cout << "   4. Modificar el código postal.\n";
  std::cout << "   5. Modificar la ciudad\n";
  std::cout << "   6. Modificar la provincia.\n";
  std::cout << "   0. Volver al menú principal.\n";
  std::cout << " Elija una opción: ";
  std::cout << tnormal;
  std::cin  >> option;

  return (option);
}

int Menu::tipoVia(){
  std::string tipoVia = "-1";
  while ((tipoVia != "1") && (tipoVia != "2") && (tipoVia != "3")){
    std::cout << tblue;
    std::cout << "Vía:\n";
    std::cout << "    1. Calle.\n";
    std::cout << "    2. Avenida.\n";
    std::cout << "    3. Plaza.\n";
    std::cout << "  Elija: ";
    std::cout << tnormal;
    std::cin  >> tipoVia;
  }
  return (atoi(tipoVia.c_str()));
}

Contacto Menu::encontrarContacto (Agenda a){
  int nContactos = 0, opcion = 0, bucle = 0;
  std::string nombre;
  std::list<Contacto> listContactos;
  std::list<Contacto>::iterator it;
  system ("clear"); // Limpia la pantalla

  if (a.getContactos().empty()){
    Contacto ERROR1 ("ERROR1","ERROR1","ERROR1","ERROR1","ERROR1",false);
    return (ERROR1);
  }
  while (listContactos.empty()){
    //Pone el texto en azul e imprime el menú
    std::cout << tblue;
    std::cout << "Introduzca: \n";
    std::cout << "El nombre de una persona.\n";
    std::cout << "El número 0 para volver al menú principal.\n\n";
    std::cout << tnormal; // Establece la letra a default

    getline(std::cin, nombre);
    std::cout << tblue;
    if (nombre == "0"){ // Si el usuario ha introducido un 0, salimos de la función
      Contacto ERROR2 ("ERROR2","ERROR2","ERROR2","ERROR2","ERROR2",false);
      return (ERROR2); // ERROR2 es un usuario especial.
    }

    listContactos = a.buscarContacto (nombre);  // Creamos una lista con contactos del nombre que buscamos

    if (listContactos.empty()){ // Si la lista tiene 0 elementos, salimos
      Contacto ERROR3 ("ERROR3","ERROR3","ERROR3","ERROR3","ERROR3",false);
      return (ERROR3);  // ERROR3 es un usuario especial.
    }

    if (listContactos.size() == 1){ // Si la lista tiene 1 elemento, lo devuelve
      return (*listContactos.begin());
    }
    else if (listContactos.size() > 1){
      for(it=listContactos.begin(); it!=listContactos.end(); it++){
        nContactos ++;

        if (nContactos % 2 == 0){
          std::cout << tcyan;
        }
        else{
          std::cout << tpurple;
        }

        std::cout << nContactos << ".\n";
        a.mostrarContacto(&(*it), false);
        std::cout << "\n";
      }

      std::cout << tblue;
      while ((opcion < 1) || (opcion > nContactos)){
        std::cout << "¿Qué contacto quiere? escoja un número: ";
        std::cout << tnormal;
        std::cin  >> opcion;
      }
      for(it=listContactos.begin(); it!=listContactos.end(); it++){
        bucle ++;
        if (bucle == opcion){
          return (*it);
        }
      }
    }
  }
  return (*it); //Nunca llegará a esta línea de código, está para evitar warning por si no entra por ninguna condición.
}
