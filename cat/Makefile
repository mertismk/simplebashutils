FLAGS = -Wall -Werror -Wextra

s21_cat: cat.o
	gcc $(FLAGS) cat.o -o s21_cat
	rm *.o

cat.o: cat.c
	gcc -c cat.c

test: s21_cat
	python3 test.py 
	rm first
	rm second
	rm result
	
clean: 
	rm s21_cat