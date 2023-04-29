CC=gcc -Wall -Werror -Wextra -std=c++17 -g
CHECKFLAGS=-lgtest -lgmock -pthread -lstdc++
GCOVFLAGS = -fprofile-arcs -ftest-coverage
GCOV=--coverage
OS = $(shell uname)

all: build_s21_calc

test: clean
	$(CC) -c test.cpp model.cpp  $(CHECKFLAGS)
	$(CC) $(GCOV) -o test test.o model.o $(CHECKFLAGS)
	./test

build_s21_calc:
	$(CC) $(GCOV) -c test.cpp model.cpp 
	$(CC) -c test.cpp model.cpp  $(CHECKFLAGS)
	$(CC) $(GCOV) -o test test.o model.o $(CHECKFLAGS)
	./test

check:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(shell find . -name "*.cpp" -or -name "*.cc" -or -name "*.h" -or -name "*.h")
	clang-format -n $(shell find . -name "*.cpp" -or -name "*.cc" -or -name "*.h" -or -name "*.h") --verbose -Werror
	rm .clang-format

leaks: test
ifeq ($(OS), Linux)
	CK_FORK=no valgrind --tool=memcheck --leak-check=full ./test
else
	leaks -atExit -- ./test
endif

gcov_report: test
	$(CC) $(CHECKFLAGS) $(GCOVFLAGS) test.cpp model.cpp $(CHECKFLAGS) -o gcov_rep.out
	./gcov_rep.out
	lcov -t "gcov_rep" --output-file=coverag.info --capture --directory .
	genhtml -o ./report coverag.info
	open ./report/index.html


clean:
	rm -f *.gcno *.gcda *.info *.out *.gch
	rm -rf ./gcov_rep.out.dSYM
	rm -rf ./report
	rm -rf ./*.o ./*.a
	rm -rf test
	rm -rf .clang-format
