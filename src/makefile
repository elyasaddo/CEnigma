
GPP = g++
CFLAGS = -Wall -Werror -pedantic

all: enigma

enigma: CharVisitor.o IOBoard.o Plugboard.o Reflector.o RotateVisitor.o Rotor.o Main.o
	$(GPP) $^ -o $@

Main.o: Main.cpp
	$(GPP) $(CFLAGS) -c $<

CharVisitor.o: CharVisitor.cpp CharVisitor.hpp Visitor.hpp AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

IOBoard.o: IOBoard.cpp IOBoard.hpp
	$(GPP) $(CFLAGS) -c $<

Plugboard.o: Plugboard.cpp Plugboard.hpp ConfigurableMapper.hpp AbstractMapper.hpp Visitor.hpp
	$(GPP) $(CFLAGS) -c $<

Reflector.o: Reflector.cpp Reflector.hpp AbstractMapper.hpp Visitor.hpp
	$(GPP) $(CFLAGS) -c $<

RotateVisitor.o: RotateVisitor.cpp RotateVisitor.hpp Visitor.hpp AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

Rotor.o: Rotor.cpp Rotor.hpp ConfigurableMapper.hpp AbstractMapper.hpp Visitor.hpp
	$(GPP) $(CFLAGS) -c $<

clean:
	rm -rf enigma *.o

.PHONY: clean all
