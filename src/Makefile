OS = $(shell uname -o)
FLAGS = -Wall -Wextra -Werror -std=c11
FLAGS_FOR_GCOV = -fprofile-arcs -ftest-coverage
ALL_TESTS = $(wildcard test/s21_test_function/*.c)

ifeq ($(OS), GNU/Linux)
	TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	TEST_FLAGS = -lcheck -lm -lpthread
endif

all: s21_string.a

clean:
	@rm -rf s21_tests *.gcda *.gcno *.o *.info *.a report gcov

rebuild:
	@make clean && make gcov_report

test: s21_string.a
	gcc $(FLAGS) $(ALL_TESTS) test/s21_tests.c --coverage s21_string.a $(TEST_FLAGS) -o s21_tests
	./s21_tests

s21_string.a:
	gcc $(FLAGS) -c function/*.c
	ar rc s21_string.a *.o
	ranlib s21_string.a

s21_string.a_gcov:
	gcc $(FLAGS) $(FLAGS_FOR_GCOV) -c function/*.c
	ar rc s21_string.a *.o
	ranlib s21_string.a

gcov_report: s21_string.a_gcov test
	mkdir gcov
	mv s21_*.gcda ./gcov
	mv s21_*.gcno ./gcov
	lcov -t "s21_string" -o s21_string.info -c -d ./gcov/.
	genhtml -o report ./s21_string.info
	rm -fr ./gcov 
	rm *.o s21_tests

cl_fr:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -n -style=google *.h ./test/s21_test_function/*.c ./test/*.c ./test/*.h ./function/*.c

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov