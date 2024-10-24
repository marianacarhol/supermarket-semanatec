all: compile run

compile: main.cpp | build
	g++ *.cpp -o build/main

run: 
	clear
	./build/main

clean:
	rm -f build/main
	rm -f build/dmain

debug: 
	g++ *.cpp -g -o build/dmain
	gdb build/dmain

debugvs:
	g++ *.cpp -g -o build/dmain

build:
	mkdir -p build
