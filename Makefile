# Makefile para compilar los archivos especificados usando mingw32-make y generar el ejecutable prueba.exe
# Para correr el programa se usa el comando 'mingw32-make run'

ifeq ($(OS), Windows_NT)
	# Si es Windows la extensión de los ejecutable es .exe
	EXTENSION = .exe
	# Comando para limpiar en Windows
	RM = del 
else 
	# Si es Linux la extensión de los ejecutable es .out
	EXTENSION = .out
	# Comando para limpiar en Linux
	RM = rm -f
endif

# Definir el compilador
CXX = g++

# Definir las opciones del compilador
CXXFLAGS = -std=c++11 -Wall

# Directorio de los archivos fuente
SRCDIR = src

# Lista de archivos fuente a compilar. 
#Aquí van todos los archivos necesarios para que funcione el sistema
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Obtener la lista de archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Nombre del ejecutable
EXECUTABLE = prueba$(EXTENSION)

# Regla por defecto: compilar los archivos fuente y generar el ejecutable
all: $(EXECUTABLE)

# Regla para generar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla para compilar los archivos fuente a objetos
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

# Regla para compilar y ejecutar el programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)