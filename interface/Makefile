TARGET = test

src = ${wildcard ./*.c}
src_o = ${patsubst %.c, %.o, $(src)}

SRC = $(src)
OBJ = $(src_o)

INCLUDE := -I./
LIB := ./
C++_X86 := gcc
CFLAGS := $(CFLAGS) -c -O0 -g  -Wall ${WARN} ${INCLUDE}

COMPILE     = $(C++_X86) $(CFLAGS) "$<" -o $@
LINK        = $(C++_X86) $(OBJ) -o $(TARGET) 

$(TARGET): $(OBJ)
	$(LINK)

print: 
	@echo ${voconsrc}
	@echo ${vocon}

clean:
	rm -f $(TARGET)
	rm -f $(OBJ)
