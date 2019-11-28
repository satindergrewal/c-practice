cd libhello
gcc -Wall -c libhello.c
ar -cqv libhello.a libhello.o
rm libhello.o
cd ..
gcc -o hello hello.c libhello/libhello.a
