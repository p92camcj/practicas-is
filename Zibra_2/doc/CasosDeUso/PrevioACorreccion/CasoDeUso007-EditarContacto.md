### Editar contacto

__ID:__ 007  
__Breve descripción:__
  El Usuario edita un contacto en la agenda.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Cliente.

__Precondiciones:__
  1. El Usuario debe tener un nombre por el que buscar el contacto a editar.

__Flujo principal:__
  1. El caso de uso empieza cuando el Usuario selecciona la acción de editar Contacto.
  2. El sistema solicita el nombre del Contacto a editar.  
    2.1. El Usuario inserta el nombre del Contacto.
  3. El sistema pregunta al usuario que campo desea editar.  
    3.1. Tras seleccionar el campo, el usuario debe introducir el nuevo valor.
  4. El sistema muestra un mensaje satisfactorio.

__Postcondiciones:__

- Los datos del contacto quedan modificados en la agenda.

__Flujos alternativos:__  
  2.1.a. Si no existe el Contacto, el sistema muestra un mensaje de error.
