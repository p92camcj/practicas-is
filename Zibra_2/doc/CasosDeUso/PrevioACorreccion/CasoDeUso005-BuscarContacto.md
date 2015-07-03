### Buscar Contacto
__ID:__ 005  
__Breve descripción:__ El Usuario busca un contacto en la agenda.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Cliente.

__Precondiciones:__
  1. El Usuario debe tener un nombre por el que buscar.

__Flujo principal:__
  1. El caso de uso empieza cuando el Usuario selecciona la acción de buscar Contacto.
  2. El sistema solicita el nombre del Contacto.  
  2.1. El Usuario inserta el nombre del Contacto.
  3. El sistema busca el contacto.

__Postcondiciones:__  

- El sistema recoge los datos del contacto.

__Flujos alternativos:__  
  3a. Si no existe el Contacto, el sistema muestra un mensaje de error.
