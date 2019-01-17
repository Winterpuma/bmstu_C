%.o : %.c
	gcc -c $< -std=c99 -Wall -Werror -ggdb

test1.exe: test_adt_string_1.o adt_string_1.o
	gcc -o test1.exe test_adt_string_1.o adt_string_1.o

test2.exe: test_adt_string_1.o adt_string_2.o
	gcc -o test2.exe test_adt_string_1.o adt_string_2.o

clean:
	rm *.o *.exe