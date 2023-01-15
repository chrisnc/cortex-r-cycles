CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-r5 -Os

.PHONY: default
default: test.o
	arm-none-eabi-objdump -d $^

.PHONY: clean
clean:
	$(RM) *.o
