%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror
main.exe: main.o
	gcc -o main.exe main.o
clean:
	rm *.o *.exe