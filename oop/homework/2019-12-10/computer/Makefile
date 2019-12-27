main: main.o component.o cpu.o ram.o hdd.o psu.o mobo.o case.o
	g++ main.o component.o cpu.o ram.o hdd.o psu.o mobo.o case.o -o main

main.o: main.cc cpu.hh ram.hh hdd.hh psu.hh mobo.hh case.hh
	g++ -c main.cc

component.o: component.cc component.hh
	g++ -c component.cc

cpu.o: cpu.cc cpu.hh component.hh
	g++ -c cpu.cc

ram.o: ram.cc ram.hh component.hh
	g++ -c ram.cc

hdd.o: hdd.cc hdd.hh component.hh
	g++ -c hdd.cc

psu.o: psu.cc psu.hh component.hh
	g++ -c psu.cc

mobo.o: mobo.cc mobo.hh component.hh cpu.hh ram.hh
	g++ -c mobo.cc

case.o: case.cc case.hh component.hh mobo.hh psu.hh hdd.hh
	g++ -c case.cc

clean:
	rm main *.o