UTIL=Station/station.c Sparse_Matrix/sparse_matrix.c Util/Util.c
MAIN=main.c
BINARY=Main
ZIP=Ex7

all:
	gcc -Wall -g $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)

in1: clear all
	./$(BINARY) < Cases/1.in

in2: clear all
	./$(BINARY) < Cases/2.in

in3: clear all
	./$(BINARY) < Cases/3.in

out1: 
	cat Cases/1.out	

out2:
	cat Cases/2.out	

out3:
	cat Cases/3.out	

clear:
	clear

r: clear all run
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o

zip:
	@zip -r ../$(ZIP).zip *
	clear

delzip:
	@rm ../$(ZIP).zip
