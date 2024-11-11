# Ustawienia kompilatora
CC=g++
CFLAGS=-c -Wall -I/usr/include/SDL2  # Flagi kompilacji
LDFLAGS=-lSDL2  # Flagi linkowania
EXEC=window_example  # Nazwa pliku wykonywalnego

# Pliki źródłowe
SOURCES=Engine.cpp Input.cpp PrimitiveRenderer.cpp Main.cpp Circle.cpp Ellipse.cpp GameObject.cpp Rectangle.cpp Polygon.cpp Triangle.cpp Point2D.cpp DrawableObject.cpp LineSegment.cpp ShapeObject.cpp TransformableObject.cpp UpdatableObject.cpp

# Pliki obiektowe wynikające z plików źródłowych
OBJECTS=$(SOURCES:.cpp=.o)

# Domyślny cel
all: $(EXEC)

# Reguła budowania pliku wykonywalnego
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(EXEC)

# Reguła budowania plików obiektowych
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# Czyszczenie plików obiektowych i pliku wykonywalnego
clean:
	rm -f $(OBJECTS) $(EXEC)

