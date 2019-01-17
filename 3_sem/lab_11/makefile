%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb


test.exe: test.o my_snprintf.o 
	gcc -o test.exe test.o my_snprintf.o
clean:
	rm *.o *.exe