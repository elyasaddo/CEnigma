
GPP = g++
CFLAGS = -Wall -Werror -pedantic
ABSTRACTOBJECTS = ..\src\AbstractMapper.o ..\src\ConfigurableMapper.o

all: testCharVisitor

testCharVisitor: testCharVisitor.o ..\src\CharVisitor.o \src\CharVisitor Reflector.o $(ABSTRACTOBJECTS)
	$(GPP) $^ -o $@

testCharVisitor.o: testCharVisitor.cpp ..\src\CharVisitor.hpp ..\src\AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

# Abstract objects
AbstractMapper.o: AbstractMapper.cpp AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

ConfigurableMapper.o: ConfigurableMapper.cpp ConfigurableMapper.hpp AbstractMapper.hpp
	$(GPP) $(CFLAGS) -c $<

clean:
	rm -rf enigma enigma.exe *.o

.PHONY: clean all
