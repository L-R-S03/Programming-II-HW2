a.exe: movie.o main.o 
	g++ movie.o main.o -o a.exe

movie.o: movie.h movie.cpp 
	g++ -c -g movie.cpp 

main.o: main.cpp movie.h 
	g++ -c -g main.cpp 

clean: 
	rm -f *.o a.exe