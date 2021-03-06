# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = tests/gtest-1.7.0

# Where to find user code.
# USER_DIR = ../samples

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11
# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = contacto_unittest #agenda_unittest #menu_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS) main clean

clean :
	@echo Borrando ejecutables, tests, librerías y objetos ...
	@rm -f $(TESTS) main gtest.a gtest_main.a *.o
	@echo Borrados ejecutables, tests, librerías y objetos

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	@echo Creando gtest-all.o ...
	@echo Creado gtest-all.o
	@$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	@echo Creando gtest_main.o ...
	@echo Creado gtest_main.o
	@$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	@echo Creando gtest.a ...
	@ar -rs $@ $^
	@echo Creado gtest.a

gtest_main.a : gtest-all.o gtest_main.o
	@echo Creando gtest_main.a ...
	@ar -rs $@ $^
	@echo Creado gtest_main.a

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

contacto.o : cpp/contacto.cpp hpp/contacto.hpp
	@echo Creando contacto.o ...
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c cpp/contacto.cpp
	@echo Creado contacto.o

agenda.o : cpp/agenda.cpp hpp/agenda.hpp cpp/contacto.cpp hpp/contacto.hpp
	@echo Creando agenda.o ...
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c cpp/agenda.cpp
	@echo Creado agenda.o

menu.o : cpp/menu.cpp hpp/menu.hpp cpp/agenda.cpp hpp/agenda.hpp cpp/contacto.cpp hpp/contacto.hpp
	@echo Creando menu.o ...
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c cpp/menu.cpp
	@echo Creado menu.o

contacto_unittest.o : tests/contacto_unittest.cpp hpp/contacto.hpp cpp/contacto.cpp
	@echo Creando contacto_unittest.o ...
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c tests/contacto_unittest.cpp
	@echo Creado contacto_unittest.o

#agenda_unittest.o : tests/agenda_unittest.cpp hpp/agenda.hpp cpp/agenda.cpp hpp/contacto.hpp cpp/contacto.cpp
#	@echo Creando agenda_unittest.o ...
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c cpp/agenda_unittest.cpp
#	@echo Creado agenda_unittest.o

#menu_unittest.o : tests/menu_unittest.cpp hpp/menu.hpp cpp/menu.cpp hpp/agenda.hpp cpp/agenda.cpp hpp/contacto.hpp cpp/contacto.cpp
#	@echo Creando menu_unittest.o ...
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c cpp/menu_unittest.cpp
# @echo Creado menu_unittest.o

contacto_unittest : contacto.o contacto_unittest.o gtest_main.a
	@echo Creando contacto_unittest ...
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
	@echo Creado contacto_unittest. Para ejecutar este test escriba ./contacto_unittest

#agenda_unittest : agenda.o contacto.o agenda_unittest.o gtest_main.a
#	@echo Creando agenda_unittest ...
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
#	@echo Creado agenda_unittest
#	@echo Creado agenda_unittest. Para ejecutar este test escriba ./agenda_unittest

#menu_unittest : menu.o agenda.o contacto.o menu_unittest.o gtest_main.a
#	@echo Creando menu_unittest ...
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
#	@echo Creado menu_unittest
#	@echo Creado menu_unittest. Para ejecutar este test escriba ./menu_unittest

main : menu.o agenda.o contacto.o cpp/main.cpp cpp/editaListas.cpp cpp/introducirDatos.cpp cpp/persistenciaFichero.cpp
	@echo Creando main ...
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
	@echo Creado main. Para ejecutar el programa escriba ./main
