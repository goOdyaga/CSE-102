all: clean compile run
clean:
	@rm -rf test
compile: main.c
	@gcc main.c -o test -lm
run: test
	@./test
