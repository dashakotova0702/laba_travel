files=function.o main.o searchfunc.o menufunc.o
target=laba3

all: $(target)

searchfunc.o: searchfunc.c
	gcc searchfunc.c -g -c -o searchfunc.o

menufunc.o: menufunc.c
	gcc menufunc.c -g -c -o menufunc.o

main.o: main.c
	gcc main.c -g -c -o main.o

function.o: function.c
	gcc function.c -g -c -o function.o

$(target): $(files)
	gcc $(files) -o $(target) -g

clean:
	rm -rf $(files)
