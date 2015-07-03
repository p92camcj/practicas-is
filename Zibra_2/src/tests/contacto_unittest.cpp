#include "../hpp/contacto.hpp"
#include "gtest/gtest.h"
#include <list>

TEST(Contacto, ConstructorParametrosDefecto) {
  Contacto c("12345678C", "Nombre");

  EXPECT_EQ("12345678C", c.getDNI());
  EXPECT_EQ("Nombre", c.getNombre());
  EXPECT_EQ("", c.getApellido1());
  EXPECT_EQ("", c.getApellido2());
  EXPECT_TRUE((c.getTelefonos()).empty());
  EXPECT_TRUE((c.getCorreosElectronicos()).empty());
  EXPECT_TRUE((c.getDireccionesPostales()).empty());
  EXPECT_EQ("", c.getAnotaciones());
  EXPECT_FALSE(c.getFavorito());
  EXPECT_EQ("", (c.getRedesSociales()).Twitter);
  EXPECT_EQ("", (c.getRedesSociales()).Facebook);
  EXPECT_EQ(0, c.getUso());
}

TEST(Contacto, ConstructorParametros) {
  Contacto c("12345678C", "Nombre", "Apellido1", "Apellido2", "Anotaciones", true);

  EXPECT_EQ("12345678C", c.getDNI());
  EXPECT_EQ("Nombre", c.getNombre());
  EXPECT_EQ("Apellido1", c.getApellido1());
  EXPECT_EQ("Apellido2", c.getApellido2());
  EXPECT_TRUE((c.getTelefonos()).empty());
  EXPECT_TRUE((c.getCorreosElectronicos()).empty());
  EXPECT_TRUE((c.getDireccionesPostales()).empty());
  EXPECT_EQ("Anotaciones", c.getAnotaciones());
  EXPECT_TRUE(c.getFavorito());
  EXPECT_EQ("", (c.getRedesSociales()).Twitter);
  EXPECT_EQ("", (c.getRedesSociales()).Facebook);
  EXPECT_EQ(0, c.getUso());
}

TEST(Contacto, ConstructorCopiaDefecto) {
  Contacto c("12345678C", "Nombre", "Apellido1", "Apellido2", "Anotaciones", true);
  Contacto d(c);
  Contacto e=d;

  EXPECT_EQ("12345678C", c.getDNI());
  EXPECT_EQ("Nombre", c.getNombre());
  EXPECT_EQ("Apellido1", c.getApellido1());
  EXPECT_EQ("Apellido2", c.getApellido2());
  EXPECT_TRUE((c.getTelefonos()).empty());
  EXPECT_TRUE((c.getCorreosElectronicos()).empty());
  EXPECT_TRUE((c.getDireccionesPostales()).empty());
  EXPECT_EQ("Anotaciones", c.getAnotaciones());
  EXPECT_TRUE(c.getFavorito());
  EXPECT_EQ("", (c.getRedesSociales()).Twitter);
  EXPECT_EQ("", (c.getRedesSociales()).Facebook);
  EXPECT_EQ(0, c.getUso());

  EXPECT_EQ("12345678C", d.getDNI());
  EXPECT_EQ("Nombre", d.getNombre());
  EXPECT_EQ("Apellido1", d.getApellido1());
  EXPECT_EQ("Apellido2", d.getApellido2());
  EXPECT_TRUE((d.getTelefonos()).empty());
  EXPECT_TRUE((d.getCorreosElectronicos()).empty());
  EXPECT_TRUE((d.getDireccionesPostales()).empty());
  EXPECT_EQ("Anotaciones", c.getAnotaciones());
  EXPECT_TRUE(d.getFavorito());
  EXPECT_EQ("", (d.getRedesSociales()).Twitter);
  EXPECT_EQ("", (d.getRedesSociales()).Facebook);
  EXPECT_EQ(0, d.getUso());

  EXPECT_EQ("12345678C", e.getDNI());
  EXPECT_EQ("Nombre", e.getNombre());
  EXPECT_EQ("Apellido1", e.getApellido1());
  EXPECT_EQ("Apellido2", e.getApellido2());
  EXPECT_TRUE((e.getTelefonos()).empty());
  EXPECT_TRUE((e.getCorreosElectronicos()).empty());
  EXPECT_TRUE((e.getDireccionesPostales()).empty());
  EXPECT_EQ("Anotaciones", e.getAnotaciones());
  EXPECT_TRUE(e.getFavorito());
  EXPECT_EQ("", (e.getRedesSociales()).Twitter);
  EXPECT_EQ("", (e.getRedesSociales()).Facebook);
  EXPECT_EQ(0, e.getUso());
}

TEST(Contacto, OperadorIgualDefecto) {
  Contacto c("12345678C", "Nombre", "Apellido1", "Apellido2", "Anotaciones", true);
  Contacto d("01234567C");
  d=c;

  EXPECT_EQ("12345678C", d.getDNI());
  EXPECT_EQ("Nombre", d.getNombre());
  EXPECT_EQ("Apellido1", d.getApellido1());
  EXPECT_EQ("Apellido2", d.getApellido2());
  EXPECT_TRUE((d.getTelefonos()).empty());
  EXPECT_TRUE((d.getCorreosElectronicos()).empty());
  EXPECT_TRUE((d.getDireccionesPostales()).empty());
  EXPECT_EQ("Anotaciones", d.getAnotaciones());
  EXPECT_TRUE(d.getFavorito());
  EXPECT_EQ("", (d.getRedesSociales()).Twitter);
  EXPECT_EQ("", (d.getRedesSociales()).Facebook);
  EXPECT_EQ(0, d.getUso());
}
