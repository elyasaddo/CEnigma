# edit this makefile so that running make compiles your enigma program

GPP = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11 -c

all: enigma

enigma: CharVisitor.o IOBoard.o Plugboard.o Reflector.o RotateVisitor.o Rotor.o Main.o
	$(GPP) $^ -o $@

Main.o: Main.cpp
	$(GPP) $(CFLAGS) $< -o $@

CharVisitor.o: Visitor.cpp CharVisitor.cpp
	$(GPP) $(CFLAGS) $^ -o $@

IOBoard.o: IOBoard.cpp
	$(GPP) $(CFLAGS) $< -o $@

Plugboard.o: AbstractMapper.cpp ConfigurableMapper.cpp Plugboard.cpp
	$(GPP) $(CFLAGS) $^ -o $@

Reflector.o: AbstractMapper.cpp ConfigurableMapper.cpp Plugboard.cpp
	$(GPP) $(CFLAGS) $^ -o $@

RotateVisitor.o: Visitor.o RotateVisitor.o
	$(GPP) $(CFLAGS) $^ -o $@

Rotor.o: AbstractMapper.cpp ConfigurableMapper.cpp Plugboard.cpp
	$(GPP) $(CFLAGS) $^ -o $@

clean:
	rm -rf enigma *.o

.PHONY: clean all
