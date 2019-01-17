LBSOURCES := input.o sort.o output.o filter.o process.o
DLLS := input.so sort.so output.so filter.so process.so

%.o : %.c
	gcc -c $< -std=c99 -Wall -Werror -pedantic

%.a: $(LBSOURCES)
	ar rc $@ $(LBSOURCES)
	ranlib $@

%.so: $(LBSOURCES)
	gcc -shared $(LBSOURCES) -o $@
    
app.%: libapp.a
	gcc main.c libapp.a -o $@

create: $(DLLS)

dapp.%: 
	gcc main.c $(DLLS) -L. -Wl,-rpath,. -o $@
	
test.%: libapp.a process.o
	gcc test.c $(DLLS) -L. -Wl,-rpath,. -o $@

clean:
	rm *.o *.exe *.a *.dll *.so