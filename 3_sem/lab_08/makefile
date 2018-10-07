%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb


app.exe: main.o input.o memory.o operations.o output.o process.o
	gcc -o app.exe main.o input.o memory.o operations.o output.o process.o
test.exe: test.o input.o memory.o operations.o output.o process.o
	gcc -o test.exe test.o input.o memory.o operations.o output.o process.o
clean:
	rm *.o *.exe