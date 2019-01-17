%.o: %.c *.h
	gcc -c $< -std=c99 -Wall -Werror 

test.exe: test.o lab12_2_lib.o
	gcc -o test.exe test.o lab12_2_lib.o

my_lib.dll: lab12_2_lib.o
	gcc -shared lab12_2_lib.o -o my_lib.dll

my_lib.so: lab12_2_lib.o
	gcc -shared -o my_lib.so lab12_2_lib.o

clean:
	rm *.o *.exe *.a *.so *.dll
