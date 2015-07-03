### Insertar Nuevo Contacto
__ID:__ 001
__Breve descripción:__ El Usuario inserta un nuevo Cliente en la agenda.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Cliente.

__Precondiciones:__  
  1. Los datos deben cumplir un formato normalizado.

__Flujo principal:__  
  1. El caso de uso empieza cuando el Usuario selecciona la acción de insertar un nuevo Contacto.
  2. El sistema solicita introducir los datos del Contacto.  
  2.1 El Usuario inserta los datos solicitados al Contacto.
  3. El sistema guarda en memoria los datos introducidos.

__Postcondiciones:__  
  - El contacto queda almacenado en la agenda.

__Flujos alternativos:__  
  2.1a. Al introducir un dato inválido, vuelve a 2.
