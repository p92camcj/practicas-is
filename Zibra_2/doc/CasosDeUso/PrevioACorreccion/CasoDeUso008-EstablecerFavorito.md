### EstablecerFavorito

__ID:__ 008  
__Breve descripción:__
  El Usuario marca como favorito un contacto en la agenda.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Cliente.

__Precondiciones:__
  1. El Usuario debe tener un nombre por el que buscar el contacto a marcar como favorito.

__Flujo principal:__
  1. El caso de uso empieza cuando el Usuario selecciona la acción de marcar favorito dentro de editar un contacto.
  2. El sistema solicita el nombre del Contacto a editar.  
    2.1. El Usuario inserta el nombre del Contacto.
  3. El sistema pregunta al usuario que campo desea editar.  
    3.1. Tras seleccionar marcar favorito, el contacto pasa a ser favorito sino lo era. Si era favorito, el sistema pregunta al usuario si quiere quede deje de serlo
  4. El sistema muestra un mensaje satisfactorio.

__Postcondiciones:__

- El sistema queda marcado como favorito si no lo estaba o deja de ser favorito si lo era.

__Flujos alternativos:__  
  2a. Si no existe el Contacto, el sistema muestra un mensaje de error.
