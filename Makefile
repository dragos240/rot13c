all: clean rot13c

clean:
	rm rot13c

rot13c:
	gcc -o rot13c rot13c.c
