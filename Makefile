#COMPILE USING G++ COMPILER
COMPILER = g++
#FLAGS TO DISPLAY WARNINGS DURING COMPILATION
CFLAGS = -Wall -g 

#LOCATE PROJECT "INCLUDE" DIRECTORY AND FORMAT ALL PATHS TO INCLUDE ALL LOCAL HEADER FILES
INCLUDE_SOURCES := $(shell cd $(CURDIR)/include && dir /S /B /AD)
INCLUDE := $(addprefix -I,$(INCLUDE_SOURCES))

LIBS = -lm

#SET DESTINATION FOR EXECUTABLE FILE
DESTDIR = ./
TARGET  = Application/main

#CREATE .o OBJECT FILE NAMES FROM CURRENT C++ FILE NAMES
SOURCES := $(shell dir /S /B /A-D *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

#CREATES EXECUTABLE FILE, REQUIRES OBJECT FILES OF ALL C++ FILES IN PROJECT
$(DESTDIR)$(TARGET): $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

#CREATES OBJECT FILES FROM C++ FILES
$(OBJECTS): %.o: %.cpp
	$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@

#DELETES ALL .o AND .exe FILES
clean:
	del $(OBJECTS)
	del $(shell dir /S /B /A-D *.exe)