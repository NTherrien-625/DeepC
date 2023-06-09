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

leaky_relu.o: Activation/leaky_relu.c
	gcc -c Activation/leaky_relu.c

leaky_relu_driver.o: drivers/leaky_relu_driver.c
	gcc -c drivers/leaky_relu_driver.c

leaky_relu_driver: Matrix.o leaky_relu.o leaky_relu_driver.o
	gcc Matrix.o leaky_relu.o leaky_relu_driver.o -o leaky_relu_driver

Model.o: Model.c
	gcc -c Model.c

model_driver.o: drivers/model_driver.c
	gcc -c drivers/model_driver.c

model_driver: mse.o xor_dataset.o Optimizer.o relu.o Matrix.o Linear.o Model.o model_driver.o
	gcc mse.o xor_dataset.o Optimizer.o relu.o Matrix.o Linear.o Model.o model_driver.o -o model_driver

mse.o: Loss/mse.c
	gcc -c Loss/mse.c

loss_driver.o: drivers/loss_driver.c
	gcc -c drivers/loss_driver.c

loss_driver: Matrix.o mse.o loss_driver.o
	gcc Matrix.o mse.o loss_driver.o -o loss_driver

Optimizer.o: Optimizer.c
	gcc -c Optimizer.c

xor_dataset.o: datasets/xor_dataset.c
	gcc -c datasets/xor_dataset.c

clean:
	rm -f *.o
	rm -f *_driver
