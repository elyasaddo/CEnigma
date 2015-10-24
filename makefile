
GPP = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
ABSTRACTOBJECTS = AbstractMapper.o ConfigurableMapper.o

all: enigma

enigma: CharVisitor.o IOBoard.o Plugboard.o Reflector.o Rotor.o Main.o $(ABSTRACTOBJECTS)
	$(GPP) $^ -o $@

Main.o: Main.cpp
	$(GPP) $(CFLAGS) -c $<

CharVisitor.o: CharVisitor.cpp CharVisitor.hpp Visitor.hpp AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

IOBoard.o: IOBoard.cpp IOBoard.hpp EnigmaConsts.hpp
	$(GPP) $(CFLAGS) -c $<

Plugboard.o: Plugboard.cpp Plugboard.hpp ConfigurableMapper.hpp AbstractMapper.hpp Visitor.hpp
	$(GPP) $(CFLAGS) -c $<

Reflector.o: Reflector.cpp Reflector.hpp AbstractMapper.hpp Visitor.hpp
	$(GPP) $(CFLAGS) -c $<

Rotor.o: Rotor.cpp Rotor.hpp ConfigurableMapper.hpp AbstractMapper.hpp Visitor.hpp
	$(GPP) $(CFLAGS) -c $<

# Abstract objects
AbstractMapper.o: AbstractMapper.cpp AbstractMapper.hpp EnigmaConsts.hpp
	$(GPP) $(CFLAGS) -c $<

ConfigurableMapper.o: ConfigurableMapper.cpp ConfigurableMapper.hpp AbstractMapper.hpp EnigmaConsts.hpp
	$(GPP) $(CFLAGS) -c $<

clean:
	rm -rf enigma enigma.exe *.o

.PHONY: clean all
