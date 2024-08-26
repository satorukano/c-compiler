CFLAGS=-std=c11 -g -static
pcc: pcc.c

test: 9cc
	./test.sh

clean:
	rm -f 9cc *.o *~ tmp*

.PHONY: test clean
