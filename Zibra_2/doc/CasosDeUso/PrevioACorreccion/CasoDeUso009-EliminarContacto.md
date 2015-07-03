### Eliminar Contacto

__ID:__ 009  
__Breve descripción:__
  El Usuario busca un contacto en la agenda y lo elimina.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Cliente.

__Precondiciones:__
  1. El Usuario debe tener un nombre por el que buscar.

__Flujo principal:__
  1. El caso de uso empieza cuando el Usuario selecciona la acción de eliminar Contacto.
  2. El sistema solicita el nombre del Contacto.  
    2.1. El Usuario inserta el nombre del Contacto.
  3. El sistema muestra un mensaje satisfactorio si ha encontrado el Contacto y lo ha borrado.

__Postcondiciones:__

- El Contacto deja de existir en la agenda.

__Flujos alternativos:__   
  2.1.a. Si no existe el Contacto, el sistema muestra un mensaje de error.
