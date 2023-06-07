Matrix.o: Matrix.c
	gcc -c Matrix.c

matrix_driver.o: drivers/matrix_driver.c
	gcc -c drivers/matrix_driver.c

matrix_driver: Matrix.o matrix_driver.o
	gcc Matrix.o matrix_driver.o -o matrix_driver

Linear.o: Layers/Linear.c
	gcc -c Layers/Linear.c

linear_driver.o: drivers/linear_driver.c
	gcc -c drivers/linear_driver.c

linear_driver: Matrix.o Linear.o linear_driver.o
	gcc Matrix.o Linear.o linear_driver.o -o linear_driver

relu.o: Activation/relu.c
	gcc -c Activation/relu.c

relu_driver.o: drivers/relu_driver.c
	gcc -c drivers/relu_driver.c

relu_driver: Matrix.o relu.o relu_driver.o
	gcc Matrix.o relu.o relu_driver.o -o relu_driver

Model.o: Model.c
	gcc -c Model.c

model_driver.o: drivers/model_driver.c
	gcc -c drivers/model_driver.c

model_driver: Model.o model_driver.o
	gcc Model.o model_driver.o -o model_driver

clean:
	rm -f *.o
	rm -f matrix_driver
	rm -f linear_driver
	rm -f relu_driver
	rm -f model_driver
