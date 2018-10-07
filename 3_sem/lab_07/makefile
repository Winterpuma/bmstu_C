%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb

app.exe: main.o input.o sort.o output.o filter.o process.o
	gcc -o app.exe main.o input.o filter.o sort.o output.o process.o 

test.exe: test.o process.o input.o sort.o output.o filter.o 
	gcc -o test.exe test.o process.o input.o filter.o sort.o output.o

clean:
	rm *.o *.exe