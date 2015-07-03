#include "../hpp/colores.hpp"
#include <cstdlib>
#include "../hpp/menu.hpp"
#include "../hpp/contacto.hpp"
#include <iostream>
#include "../hpp/agenda.hpp"
#include "../hpp/introducirDatos.hpp"
#include "../hpp/editaListas.hpp"
#include "../hpp/gestorPersistencia.hpp"
#include "../hpp/persistenciaFichero.hpp"
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
  Menu m;
  Agenda a;
  Contacto c;
  int opcionMenu = -1;
  int detalleContacto = -1;
  int eligeEditarContacto = -1;
  int terminalHTML = -1;
  int editarListas = -1;
  std::string modificarParametro;
  std::string dniContacto;
  pid_t pid;
  int esperaPid;
  int sistemaOperativo;
  int navegador;
  struct redSocial redesSociales;
  std::string twitter;
  std::string facebook;
  std::string buffer;

  //GESTOR PERSISTENCIA
  persistenciaFichero almacenamiento;
  almacenamiento.setNombreFichero("copiaSeguridad.agen");
  
  // PERSISTENCIA: CARGA LA AGENDA GUARDADA JUSTO AL INICIAR EL PROGRAMA
  a.setContactos(almacenamiento.cargarContactos());

  while (true) {
  
    // PERSISTENCIA: ALMACENA CONSTANTEMENTE LOS DATOS DE LA AGENDA
    almacenamiento.guardarContactos(a.getContactos());
    

    opcionMenu = m.mostrarMenuPrincipal();
    
    
    
    system ("clear");
    if ((opcionMenu >= 0) || (opcionMenu < 8)) {

      // INSERTAR UN NUEVO CONTACTO
      if (opcionMenu == 1) {
        Contacto c;
        std::cout << tblue;
        std::cout << "Introduzca los datos del contacto. ";
        std::cout << tyellow;
        std::cout << "Introduzca '-1' para no introducir un campo.\n";

        introduceDNI (&c);
        introduceNombre (&c);
        introduceApellido1 (&c);
        introduceApellido2 (&c);
        introduceAnotacion (&c);
        introduceFavorito (&c);
        introduceTelefonos (&c);
        introduceCorreo (&c);
        introduceDirecciones (&c);
        introduceRedesSociales (&c);
        introduceFechaNacimiento (&c);
        introduceFoto (&c);

        a.insertarContacto (c);
      }







     // INSERTAR UNA NUEVA CITA
      else if (opcionMenu == 2) {
        c = m.encontrarContacto (a);

        // Si nuestra lista de contactos está vacía, volvemos al menú principal
        if ((c.getDNI() == "ERROR1") && (c.getApellido1() == "ERROR1") &&
          (c.getApellido2() == "ERROR1")){
            std::cout << tblue;
            std::cout << "Lo sentimos pero la lista de contactos se encuentra vacía.";
            std::cout.flush();  // Funciona como fflush () en C.
            usleep (1600000);
          }

        // Si el usuario decide volver al menú principal, volvemos.
        else if ((c.getDNI() == "ERROR2") && (c.getApellido1() == "ERROR2") &&
        (c.getApellido2() == "ERROR2")){
          // NO SE HACE NADA PORQUE VUELVE AL MENÚ PRINCIPAL
        }

        // Si no existe nadie con el nombre buscado, volvemos al menú principal
        else if ((c.getDNI() == "ERROR3") && (c.getApellido1() == "ERROR3") &&
        (c.getApellido2() == "ERROR3")){
          std::cout << tblue;
          std::cout << "\nLo sentimos pero no existe ningún contacto con ese nombre.\n\n";
          std::cout.flush();  // Funciona como fflush () en C.
          usleep (1600000);
        }

        else{
        
          dniContacto = c.getDNI();
          introduceCitas(&c);
          a.eliminarContacto (dniContacto);
          a.insertarContacto (c);
        
        }
      }







      // GUARDAR COPIA DE SEGURIDAD
      else if (opcionMenu == 3) {
        almacenamiento.guardarContactos(a.getContactos());
        
	std::cout << tblue;
	std::cout << "\n\nCopia de seguridad creada con éxito.";
	std::cout << "\n\nPulse intro para volver al menú principal.";

	// Las siguientes 3 líneas son necesarias para que el usuario introduzca un intro.
	std::cin.clear();
	std::cin.ignore (256,'\n');
	std::cin.get();

	std::cout << tnormal;
      }

      // MOSTRAR CONTACTO
      else if (opcionMenu == 4) {
        c = m.encontrarContacto (a);

        // Si nuestra lista de contactos está vacía, volvemos al menú principal
        if ((c.getDNI() == "ERROR1") && (c.getApellido1() == "ERROR1") &&
          (c.getApellido2() == "ERROR1")){
            std::cout << tblue;
            std::cout << "Lo sentimos pero la lista de contactos se encuentra vacía.";
            std::cout.flush();  // Funciona como fflush () en C.
            usleep (1600000);
          }

        // Si el usuario decide volver al menú principal, volvemos.
        else if ((c.getDNI() == "ERROR2") && (c.getApellido1() == "ERROR2") &&
        (c.getApellido2() == "ERROR2")){
          // NO SE HACE NADA PORQUE VUELVE AL MENÚ PRINCIPAL
        }

        // Si no existe nadie con el apellido buscado, volvemos al menú principal
        else if ((c.getDNI() == "ERROR3") && (c.getApellido1() == "ERROR3") &&
        (c.getApellido2() == "ERROR3")){
          std::cout << tblue;
          std::cout << "\nLo sentimos pero no existe ningún contacto con ese nombre.\n\n";
          std::cout.flush();  // Funciona como fflush () en C.
          usleep (1600000);
        }

        else{
          while ((detalleContacto != 0) && (detalleContacto != 1)) {
            system ("clear");
            std::cout << tblue;
            std::cout << "¿Quiere mostrar el contacto detallado?\n";
            std::cout << "    1. Sí.\n";
            std::cout << "    0. No.\n";
            std::cout << "  Elija: ";
            std::cout << tnormal;
            std::cin >> detalleContacto;

            if ((detalleContacto == 0) || (detalleContacto == 1)){
              std::cout << tblue;
              system ("clear");
              if (detalleContacto == 0) {
                a.mostrarContacto (&c, false);
              }
              else if (detalleContacto == 1){
                a.mostrarContacto (&c, true);
              }
              std::cout << tblue;
              std::cout << "\n\nPulse intro para volver al menú principal.";

              // Las siguientes 3 líneas son necesarias para que el usuario introduzca un intro.
              std::cin.clear();
              std::cin.ignore (256,'\n');
              std::cin.get();

              std::cout << tnormal;
            }
          }
          detalleContacto = -1;
        }
      }

      // EDITAR CONTACTO
      else if (opcionMenu == 5) {
        c = m.encontrarContacto (a);
        dniContacto = c.getDNI();
        system ("clear");

        // Si nuestra lista de contactos está vacía, volvemos al menú principal
        if ((c.getDNI() == "ERROR1") && (c.getApellido1() == "ERROR1") &&
            (c.getApellido2() == "ERROR1")){
          std::cout << tblue;
          std::cout << "Lo sentimos pero la lista de contactos se encuentra vacía.";
          std::cout.flush();  // Funciona como fflush () en C.
          usleep (1600000);
        }

        // Si el usuario decide volver al menú principal, volvemos.
        else if ((c.getDNI() == "ERROR2") && (c.getApellido1() == "ERROR2") &&
        (c.getApellido2() == "ERROR2")){
          // NO SE HACE NADA PORQUE VUELVE AL MENÚ PRINCIPAL
        }

        // Si no existe nadie con el apellido buscado, volvemos al menú principal
        else if ((c.getDNI() == "ERROR3") && (c.getApellido1() == "ERROR3") &&
        (c.getApellido2() == "ERROR3")){
          std::cout << tblue;
          std::cout << "\nLo sentimos pero no existe ningún contacto con ese nombre.\n\n";
          std::cout.flush();  // Funciona como fflush () en C.
          usleep (1600000);
        }

      else{
        while (eligeEditarContacto != 0){
          system ("clear");
          eligeEditarContacto = m.mostrarEditarContacto (c);
          
          getline(std::cin, buffer);

          if (eligeEditarContacto == 1){
            introduceDNI (&c);
          }
          else if (eligeEditarContacto == 2){
            introduceNombre (&c);
          }
          else if (eligeEditarContacto == 3){
            introduceApellido1 (&c);
          }
          else if (eligeEditarContacto == 4){
            introduceApellido2 (&c);
          }
          else if (eligeEditarContacto == 5){
            introduceAnotacion (&c);
          }
          else if (eligeEditarContacto == 6){
            while ((editarListas != 1) && (editarListas != 2) && (editarListas != 3)){
              system ("clear");
              std::cout << tblue;
              std::cout << "¿Qué desea?\n";
              std::cout << "    1. Introducir nuevas direcciones.\n";
              std::cout << "    2. Modificar una dirección.\n";
              std::cout << "    3. Eliminar una dirección.\n";
              std::cout << " Elija: ";
              std::cout << tnormal;
              std::cin  >> editarListas;
              getline(std::cin, buffer);
            }
            system ("clear");

            if (editarListas == 1){
              introduceDirecciones (&c);
            }
            else if (editarListas == 2){
              modificaDireccion (&c);
            }
            else if (editarListas == 3){
              eliminaDireccion (&c);
            }
            editarListas = -1;
          }
          else if (eligeEditarContacto == 7){
            while ((editarListas != 1) && (editarListas != 2) && (editarListas != 3)){
              system ("clear");
              std::cout << tblue;
              std::cout << "¿Qué desea?\n";
              std::cout << "    1. Introducir nuevos teléfonos.\n";
              std::cout << "    2. Modificar un teléfono.\n";
              std::cout << "    3. Eliminar un teléfono.\n";
              std::cout << " Elija: ";
              std::cout << tnormal;
              std::cin  >> editarListas;
              getline(std::cin, buffer);
            }
            if (editarListas == 1){
              introduceTelefonos (&c);
            }
            else if (editarListas == 2){
              modificaTelefono (&c);
            }
            else if (editarListas == 3){
              eliminaTelefono (&c);
            }
            editarListas = -1;
          }
          else if (eligeEditarContacto == 8){
            while ((editarListas != 1) && (editarListas != 2) && (editarListas != 3)){
              system ("clear");
              std::cout << tblue;
              std::cout << "¿Qué desea?\n";
              std::cout << "    1. Introducir nuevos correos.\n";
              std::cout << "    2. Modificar un correo.\n";
              std::cout << "    3. Eliminar un correo.\n";
              std::cout << " Elija: ";
              std::cout << tnormal;
              std::cin  >> editarListas;
              getline(std::cin, buffer);
            }
            if (editarListas == 1){
              introduceCorreo (&c);
            }
            else if (editarListas == 2){
              modificaCorreo (&c);
            }
            else if (editarListas == 3){
              eliminaCorreo (&c);
            }
            editarListas = -1;
          }
          else if (eligeEditarContacto == 9){
            introduceFechaNacimiento(&c);
          }
          else if (eligeEditarContacto == 10){
            std::cout << tblue;
            std::cout << "Twitter: ";
            std::cout << tnormal;
            std::cin  >> twitter;
            getline(std::cin, buffer);
            if (twitter != "-1"){
              redesSociales.Twitter = twitter;
            }
            c.setRedesSociales (redesSociales);
          }
          else if (eligeEditarContacto == 11){
            std::cout << tblue;
            std::cout << "Facebook: ";
            std::cout << tnormal;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::getline(std::cin, facebook);
            if (facebook != "-1"){
              redesSociales.Facebook = facebook;
            }
            c.setRedesSociales (redesSociales);
          }
          else if (eligeEditarContacto == 12){
            introduceFoto(&c);
          }
          else if (eligeEditarContacto == 13){
            c.conmutarFavorito();
          }
        }
        a.eliminarContacto (dniContacto);
        a.insertarContacto (c);
        eligeEditarContacto = -1;
      }


    }

    // ELIMINAR CONTACTO
    else if (opcionMenu == 6) {
      c = m.encontrarContacto (a);

      // Si nuestra lista de contactos está vacía, volvemos al menú principal
      if ((c.getDNI() == "ERROR1") && (c.getApellido1() == "ERROR1") &&
        (c.getApellido2() == "ERROR1")){
          std::cout << tblue;
          std::cout << "Lo sentimos pero la lista de contactos se encuentra vacía.";
          std::cout.flush();  // Funciona como fflush () en C.
          usleep (1600000);
        }

        // Si el usuario decide volver al menú principal, volvemos.
        else if ((c.getDNI() == "ERROR2") && (c.getApellido1() == "ERROR2") &&
        (c.getApellido2() == "ERROR2")){
          // NO SE HACE NADA PORQUE VUELVE AL MENÚ PRINCIPAL
        }

        // Si no existe nadie con el apellido buscado, volvemos al menú principal
        else if ((c.getDNI() == "ERROR3") && (c.getApellido1() == "ERROR3") &&
        (c.getApellido2() == "ERROR3")){
          std::cout << tblue;
          std::cout << "\nLo sentimos pero no existe ningún contacto con ese nombre.\n\n";
          std::cout.flush();  // Funciona como fflush () en C.
          usleep (1600000);
        }

        else{
          a.eliminarContacto (c.getDNI());
        }

      }

      // MOSTRAR AGENDA
      else if (opcionMenu == 7) {
        while ((terminalHTML!=0) && (terminalHTML!=1)){
          system ("clear");
          std::cout << tblue;
          std::cout << "¿Quiere mostrarlo en?\n";
          std::cout << "   1. HTML.\n";
          std::cout << "   0. Terminal.\n";
          std::cout << " Elija: ";
          std::cout << tnormal;
          std::cin  >> terminalHTML;
          getline(std::cin, buffer);

          if (terminalHTML == 1){
            a.imprimirAgenda (1);
            std::cout << tblue;
            std::cout << "¿Está en Linux o Mac?\n";
            std::cout << "   1. Linux.\n";
            std::cout << "   2. Mac.\n";
            std::cout << "Elija: ";
            std::cout << tnormal;
            std::cin  >> sistemaOperativo;
            if (sistemaOperativo == 1){
              std::cout << tblue;
              std::cout << "1. ¿Google Chrome?\n";
              std::cout << "2. ¿Mozilla Firefox?.\n";
              std::cout << "3. ¿Otro?\n";
              std::cout << "Elija: ";
              std::cout << tnormal;
              std::cin  >> navegador;
              pid = fork ();
              if (pid == 0){
                if (navegador == 1){
                  system("gnome-terminal -x bash -c \"python -m SimpleHTTPServer\"");
                  system("google-chrome 127.0.0.1:8000");
                }
                else if (navegador == 2){
                  system("gnome-terminal -x bash -c \"python -m SimpleHTTPServer\"");
                  system("firefox 127.0.0.1:8000");
                }
                else if (navegador == 3){
                  system ("clear");
                  std::cout << "Entre en la dirección 127.0.0.1:8000 desde el navegador deseado.";
                }

                else if (sistemaOperativo == 2){
                  std::cout << "Entre en la dirección 127.0.0.1:8000 desde el navegador deseado.";
                  //system("osascript -e \'tell application \"Terminal\" to activate\' -e \'tell application \"System Events\" to tell process \"Terminal\" to keystroke \"t\" using command down\' -x bash -c \"python -m SimpleHTTPServer\"");
                }
                while ((pid = wait (&esperaPid)) != -1);
                  exit (1);
              }
            }
          }
          else if (terminalHTML == 0){
            system ("clear");
            a.imprimirAgenda (0);
          }
        }
        std::cout << tblue;
        std::cout << "\n\nPulse intro para volver al menú principal.\n";
        terminalHTML = -1;
        std::cin.clear();
        std::cin.ignore (256,'\n');
        std::cin.get();
      }

      // CARGAR COPIA DE SEGURIDAD
      else if (opcionMenu == 8) {
        a.setContactos(almacenamiento.cargarContactos());
        
	std::cout << tblue;
	
	std::cout << "\n\nPulse intro para volver al menú principal.";

	// Las siguientes 3 líneas son necesarias para que el usuario introduzca un intro.
	std::cin.clear();
	std::cin.ignore (256,'\n');
	std::cin.get();

	std::cout << tnormal;
      }

      // SALIR
      else if (opcionMenu == 0) {
        std::cout << tblue;
        std::cout << "¡Gracias por usar el programa!\n\n";
        std::cout << tnormal;
        usleep (1500000);
        system ("clear");
        return (0);
      }
    }
  }
}
