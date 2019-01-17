%.o : %.c *.h
	gcc -c $< -std=c99

test.exe: main.o mystring.o
	gcc -o test.exe main.o mystring.o

clean:
	rm *.o *.exe
