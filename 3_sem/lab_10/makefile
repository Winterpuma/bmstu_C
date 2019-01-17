%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb


app.exe: main.o list.o process.o
	gcc -o app.exe main.o list.o process.o
test.exe: test.o list.o process.o
	gcc -o test.exe test.o list.o process.o
clean:
	rm *.o *.exe