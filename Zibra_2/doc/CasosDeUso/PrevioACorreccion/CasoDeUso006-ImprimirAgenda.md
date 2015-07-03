### Imprimir agenda

__ID:__ 006  
__Breve descripción:__
  El Usuario imprime la agenda.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Cliente.

__Precondiciones:__
  1. La agenda debe tener contactos.

__Flujo principal:__
  1. El caso de uso empieza cuando el Usuario selecciona la acción de imprimir agenda.
  2. El sistema muestra dos opciones: por pantalla y en HTML.
  3. El usuario selecciona la opción deseada.  
    3.1. Si la opción escogida es por pantalla, el sistema muestra la agenda por pantalla.  
    3.2. Si la opción escogida es por HTML, el sistema muestra un mensaje satisfactorio
       si ha podido imprimir correctamente la agenda en HTML.

__Postcondiciones:__

- La agenda queda imprimida en la manera elegida por el usuario.

__Flujos alternativos:__  
  1a. Si no hay contactos en la agenda, el sistema muestra un mensaje de error.
