#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <string>
#include <list>

struct redSocial {
  std::string Twitter;
  std::string Facebook;
};

struct direccion {
  std::string tipoVia;  // Puede ser calle, avenida, o plaza
  std::string nombreVia;
  std::string numero;
  std::string codigoPostal;
  std::string ciudad;
  std::string provincia;
};

struct fecha {
  int dia;  
  int mes;
  int anyo;
};

struct hora {
  std::string horas;  
  std::string minutos;
};	

struct cita {
  struct fecha fecha;  
  struct hora hora; 
  std::string tipoCita;
};

class Contacto {
  private:
    std::string DNI_;
    std::string nombre_;
    std::string apellido1_;
    std::string apellido2_;
    std::list<unsigned long int> telefonos_;
    std::list<std::string> correosElectronicos_;
    std::list<direccion> direccionesPostales_;
    std::string anotaciones_;
    bool favorito_;
    struct redSocial redesSociales_;
    unsigned int uso_;
    std::string foto_;
    struct fecha fechaNacimiento_;
    std::list<cita> citas_;

  public:
    void setDNI(std::string DNI) {DNI_ = DNI;}
    std::string getDNI() {return DNI_;}
    void setNombre(std::string nombre) {nombre_ = nombre;}
    std::string getNombre() {return nombre_;}
    void setApellido1(std::string apellido) {apellido1_ = apellido;}
    std::string getApellido1() const {return apellido1_;}
    void setApellido2(std::string apellido) {apellido2_ = apellido;}
    std::string getApellido2() const {return apellido2_;}
    void setTelefonos(std::list<unsigned long int> telefonos) {telefonos_ = telefonos;}
    std::list<unsigned long int> getTelefonos() {return telefonos_;}
    void setCorreosElectronicos(std::list<std::string> correosElectronicos) {correosElectronicos_ = correosElectronicos;}
    std::list<std::string> getCorreosElectronicos() {return correosElectronicos_;}
    void setDireccionesPostales(std::list<direccion> direccionesPostales) {direccionesPostales_ = direccionesPostales;}
    std::list<direccion> getDireccionesPostales() {return direccionesPostales_;}
    void setAnotaciones(std::string anotaciones) {anotaciones_ = anotaciones;}
    std::string getAnotaciones() {return anotaciones_;}
    void setFavorito(bool favorito) {favorito_ = favorito;}
    bool getFavorito() {return favorito_;}
    void conmutarFavorito();
    void setRedesSociales(struct redSocial redesSociales) {redesSociales_ = redesSociales;}
    struct redSocial getRedesSociales() {return redesSociales_;}
    void setUso(unsigned int uso) {uso_ = uso;}
    unsigned int getUso() {return uso_;}
    void setFoto(std::string foto) {foto_ = foto;}
    std::string getFoto () {return foto_;}
    void aumentarUso() {setUso(getUso()+1);}
    Contacto(std::string initDNI = "", std::string initNombre = "", std::string initApellido1 = "",
             std::string initApellido2 = "", std::string anotaciones = "", bool favorito = false);
    void setFechaNacimiento(struct fecha fechaNacimiento) {fechaNacimiento_=fechaNacimiento;}
    struct fecha getFechaNacimiento() {return fechaNacimiento_;}
    void setCitas(std::list<cita> citas) {citas_=citas;}
    std::list<cita> getCitas() {return citas_;}
    //void setCitas(std::list<struct cita> citas) {citas_=citas;}
    //std::list<struct cita> getCitas() {return citas_;}
};

#endif
