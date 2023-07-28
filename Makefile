# Compiler
CC := gcc

# Directories
LIB_SRC_DIR := src/lib
DRIVER_SRC_DIR := src/driver
OBJ_DIR := obj

$(OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: $(DRIVER_SRC_DIR)/%.c
	$(CC) -c $< -o $@

TensorDriver: $(OBJ_DIR)/Tensor.o $(OBJ_DIR)/TensorDriver.o
	$(CC) $^ -o $@

LinearDriver: $(OBJ_DIR)/Tensor.o $(OBJ_DIR)/Linear.o $(OBJ_DIR)/LinearDriver.o
	$(CC) $^ -o $@

clean:
	rm -f obj/*.o
	rm -f *Driver
