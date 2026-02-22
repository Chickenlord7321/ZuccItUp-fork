# Author: Caleb Bronn
# Last Update: 22 Feb 2026

G = g++-4.9 -std=c++11	# allows us to use C++11 methods like Regex
CFLAGS = -I/usr/local/lib/Oracle/instantclient_11_2/sdk/include
LFLAGS = -L/usr/local/lib/Oracle/instantclient_11_2 -locci -lociei

zuccItUp: main.o server.o
	$(G) $(LFLAGS) -o zuccItUp main.o server.o
	@echo "Zucc It Up is ready to roll!"

main.o: src/main.cpp server.o
	$(G) -c $(CFLAGS) src/main.cpp -o main.o
	
server.o: src/server.cpp
	$(G) -c $(CFLAGS) src/server.cpp -o server.o

clean:
	rm -f *.o zuccItUp
