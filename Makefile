# Compiler
CC := gcc

# Directories
LIB_SRC_DIR := src/lib
DRIVER_SRC_DIR := src/driver
OBJ_DIR := obj

# Dependency Lists
_ModelDriver_OBJ := Tensor.o ReLU.o LeakyReLU.o Linear.o Loss.o Model.o
ModelDriver_OBJ := $(patsubst %,$(OBJ_DIR)/%,$(_ModelDriver_OBJ))

$(OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: $(DRIVER_SRC_DIR)/%.c
	$(CC) -c $< -o $@

TensorDriver: $(OBJ_DIR)/Tensor.o $(OBJ_DIR)/TensorDriver.o
	$(CC) $^ -o $@

LinearDriver: $(OBJ_DIR)/Tensor.o $(OBJ_DIR)/Linear.o $(OBJ_DIR)/LinearDriver.o
	$(CC) $^ -o $@

ReLUDriver: $(OBJ_DIR)/Tensor.o $(OBJ_DIR)/ReLU.o $(OBJ_DIR)/ReLUDriver.o
	$(CC) $^ -o $@ -lm

LeakyReLUDriver: $(OBJ_DIR)/Tensor.o $(OBJ_DIR)/LeakyReLU.o $(OBJ_DIR)/LeakyReLUDriver.o
	$(CC) $^ -o $@ -lm

ModelDriver: $(ModelDriver_OBJ) $(OBJ_DIR)/ModelDriver.o
	$(CC) $^ -o $@ -lm

clean:
	rm -f obj/*.o
	rm -f *Driver
