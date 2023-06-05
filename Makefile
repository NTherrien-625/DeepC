Matrix.o: Matrix.c
	gcc -c Matrix.c

matrix_driver.o: matrix_driver.c
	gcc -c matrix_driver.c

matrix_driver: Matrix.o matrix_driver.o
	gcc Matrix.o matrix_driver.o -o matrix_driver

Linear.o: Layers/Linear.c
	gcc -c Layers/Linear.c

linear_driver.o: linear_driver.c
	gcc -c linear_driver.c

linear_driver: Matrix.o Linear.o linear_driver.o
	gcc Matrix.o Linear.o linear_driver.o -o linear_driver

clean:
	rm -f *.o
	rm -f matrix_driver
	rm -f linear_driver
