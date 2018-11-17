%.o : %.c *.h
	gcc -c $< -std=c99
app.exe: main.o process.o my_str.o
	gcc -o app.exe main.o process.o my_str.o
test.exe: tests.o process.o test_my_str.o my_str.o
	gcc -o test.exe process.o tests.o test_my_str.o my_str.o
clean:
	rm *.o *.exe