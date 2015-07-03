### Guardar Copia de Seguridad

__ID:__ 002  
__Breve descripción:__
  El Usuario guarda copia de seguridad de la agenda.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Ninguno.

__Precondiciones:__
  1. La agenda debe tener contactos.

__Flujo principal:__
  1. El caso de uso empieza cuando el Usuario selecciona la acción de guardar copia de seguridad.
  2. El sistema almacena la copia de seguridad y muestra un mensaje satisfactorio.

__Postcondiciones:__

- La copia de seguridad queda almacenada en un fichero local.

__Flujos alternativos:__   
  2a. Si no hay contactos en la agenda, el sistema muestra un mensaje de error.
