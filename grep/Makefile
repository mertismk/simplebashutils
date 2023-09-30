FLAGS = -Wall -Werror -Wextra

s21_grep: grep.o
	gcc $(FLAGS) grep.o -o s21_grep
	rm *.o

grep.o: grep.c
	gcc -c grep.c

test: s21_grep
	python3 test.py 
	rm first
	rm second
	rm result
	
clean: 
	rm s21_grep