### Cargar copia de seguridad
__ID:__ 003  
__Breve descripción:__
  El Usuario restaura la última copia de seguridad.

__Actores principales:__  Usuario.  
__Actores secundarios:__  Ninguno.

__Precondiciones:__  
  1. Existencia de una copia de seguridad con datos.  

__Flujo principal:__  
  1. El caso de uso empieza cuando el usuario selecciona la acción de cargar copia de seguridad.
  2. El sistema comprueba si existe copia de seguridad almacenada.
  3. El sistema carga la copia y muestra un aviso satifactorio.

__Postcondiciones:__  
  - El Usuario puede trabajar con los datos cargados.

__Flujos alternativos:__  
  2a. Si no existe la copia de seguridad, se muestra un mensaje de error.
