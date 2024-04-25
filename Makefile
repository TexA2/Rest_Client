all: main

main: librestclient.so clean
	g++ -L./ -Wl,-rpath=./ ./src/main.cc -lrestclient -lcurl -o start

librestclient.so: get_req.o dser.o cli.o
	g++ -shared get_req.o dser.o cli.o -o librestclient.so

get_req.o: ./src/get_req.cc
	g++ -fPIC -c ./src/get_req.cc

dser.o: ./src/dser.cc
	g++ -fPIC -c ./src/dser.cc

cli.o: ./src/cli.cc
	g++ -fPIC -c ./src/cli.cc

clean:
	rm -rf *.o