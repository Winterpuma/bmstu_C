%.o : %.c *.h
	gcc -c $< -std=c99
test.exe: main.o
	gcc -o test.exe main.o
clean:
	rm *.o *.exe