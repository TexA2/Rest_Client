all: main

main: get_req.o dser.o cli.o
	g++ main.cc get_req.o dser.o cli.o -lcurl -o start

get_req.o: get_req.cc
	g++ -c get_req.cc

dser.o: dser.cc
	g++ -c dser.cc

cli.o: cli.cc
	g++ -c cli.cc

clean:
	rm -rf *.o