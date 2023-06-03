Matrix.o: Matrix.c
	gcc -c Matrix.c

matrix_driver.o: matrix_driver.c
	gcc -c matrix_driver.c

matrix_driver: Matrix.o matrix_driver.o
	gcc Matrix.o matrix_driver.o -o matrix_driver

clean:
	rm -f *.o
	rm -f matrix_driver
