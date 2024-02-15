# Makefile para compilar los archivos especificados usando mingw32-make y generar el ejecutable prueba.exe
# Para correr el programa se usa el comando 'mingw32-make run'
# Definir el compilador
CXX = g++

# Definir las opciones del compilador
CXXFLAGS = -std=c++11 -Wall

# Directorio de los archivos fuente
SRCDIR = src

# Lista de archivos fuente a compilar. 
#Aquí van todos los archivos necesarios para que funcione el sistema
SOURCES = main.cpp Banco.cpp Dinero.cpp Cliente.cpp Prestamo.cpp Certificado.cpp Transaccion.cpp Cuenta.cpp identidad.cpp Producto.cpp agregar_cliente.cpp Menu.cpp

# Obtener la lista de archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Nombre del ejecutable
EXECUTABLE = prueba.exe

# Regla por defecto: compilar los archivos fuente y generar el ejecutable
all: $(EXECUTABLE)

# Regla para generar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regla para compilar los archivos fuente a objetos
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	del $(EXECUTABLE) $(OBJECTS)

# Regla para compilar y ejecutar el programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)