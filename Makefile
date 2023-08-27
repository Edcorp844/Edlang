SRC_DIR=src
BUILD_DIR=build
CC = gcc

SOURCES_C=$(shell find $(SRC_DIR) -name *.c)
OBJECTS_C=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES_C))



.PHONY: compiler clean run

compiler: $(BUILD_DIR)/compiler.o

$(BUILD_DIR)/compiler.o : $(SOURCES_C)
	mkdir -p $(@D)
	$(CC) $(SOURCES_C) -o $(BUILD_DIR)/compiler.o
	@echo '-->$(SOURCES_C) compiled'

clean:
	rm -rf $(BUILD_DIR)/*
	rmdir $(BUILD_DIR)

run:
	./$(BUILD_DIR)/compiler.o test/main.ed
