
GPP = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
OBJECTS = bin/CharVisitor.o bin/IOBoard.o bin/Plugboard.o bin/Reflector.o bin/Rotor.o bin/Main.o
ABSTRACTOBJECTS = bin/AbstractMapper.o bin/ConfigurableMapper.o

all: mkdirBin enigma

mkdirBin:
	mkdir -p bin

enigma: $(OBJECTS) $(ABSTRACTOBJECTS)
	$(GPP) $^ -o $@

bin/Main.o: src/Main.cpp
	$(GPP) $(CFLAGS) -c $< -o $@

bin/CharVisitor.o: src/CharVisitor.cpp src/CharVisitor.hpp src/Visitor.hpp src/AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

bin/IOBoard.o: src/IOBoard.cpp src/IOBoard.hpp src/EnigmaConsts.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

bin/Plugboard.o: src/Plugboard.cpp src/Plugboard.hpp src/ConfigurableMapper.hpp src/AbstractMapper.hpp src/Visitor.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

bin/Reflector.o: src/Reflector.cpp src/Reflector.hpp src/AbstractMapper.hpp src/Visitor.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

bin/Rotor.o: src/Rotor.cpp src/Rotor.hpp src/ConfigurableMapper.hpp src/AbstractMapper.hpp src/Visitor.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

# Abstract objects
bin/AbstractMapper.o: src/AbstractMapper.cpp src/AbstractMapper.hpp src/EnigmaConsts.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

bin/ConfigurableMapper.o: src/ConfigurableMapper.cpp src/ConfigurableMapper.hpp src/AbstractMapper.hpp src/EnigmaConsts.hpp
	$(GPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf enigma enigma.exe bin/*.o 

.PHONY: clean all mkdirBin

