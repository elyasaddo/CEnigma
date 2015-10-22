
GPP = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
ABSTRACTOBJECTS = ../src/AbstractMapper.o ../src/ConfigurableMapper.o

all: testCharVisitor testConfigurableMapper

testCharVisitor: testCharVisitor.o ../src/CharVisitor.o ../src/Reflector.o $(ABSTRACTOBJECTS)
	$(GPP) $^ -o $@

testConfigurableMapper: testConfigurableMapper.o ../src/CharVisitor.o ../src/Plugboard.o ../src/Rotor.o $(ABSTRACTOBJECTS)
	$(GPP) $^ -o $@

testCharVisitor.o: testCharVisitor.cpp ../src/CharVisitor.hpp ../src/AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

testConfigurableMapper.o: testConfigurableMapper.cpp ../src/CharVisitor.hpp ../src/AbstractMapper.hpp ../src/ConfigurableMapper.hpp ../src/Plugboard.hpp ../src/Rotor.hpp
	$(GPP) $(CFLAGS) -c $<
	
# Abstract objects
# AbstractMapper.o: AbstractMapper.cpp AbstractMapper.hpp
#	$(GPP) $(CFLAGS) -c $<

# ConfigurableMapper.o: ConfigurableMapper.cpp ConfigurableMapper.hpp AbstractMapper.hpp
#	$(GPP) $(CFLAGS) -c $<

clean:
	rm -rf enigma enigma.exe *.o

.PHONY: clean all
