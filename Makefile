COMPILER = g++
CFLAGS = -Wall -g 

INCLUDE_SOURCES := $(shell cd $(CURDIR)/include && dir /S /B /AD)
INCLUDE := $(addprefix -I,$(INCLUDE_SOURCES))

LIBS = -lm

DESTDIR = ./
TARGET  = Application/main

SOURCES := $(shell dir /S /B /A-D *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)