all: main

main: librestclient.so
	g++ -L./ -Wl,-rpath=./  main.cc -lrestclient -lcurl -o start

librestclient.so: get_req.o dser.o cli.o
	g++ -shared get_req.o dser.o cli.o -o librestclient.so

get_req.o: get_req.cc
	g++ -fPIC -c get_req.cc

dser.o: dser.cc
	g++ -fPIC -c dser.cc

cli.o: cli.cc
	g++ -fPIC -c cli.cc

clean:
	rm -rf *.o