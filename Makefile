PREFIX = /usr/local/bin
TARGET = ucs_menu
GCCFLAGS = -O3

.PHONY: all clean install uninstall

all: $(TARGET)
	
$(TARGET): ucs_input.c
	$(CC) $(GCCFLAGS) $^ -o $@
clean:
	rm $(TARGET)
install: $(TARGET)
	install $(TARGET) $(PREFIX)
uninstall:
	rm $(PREFIX)/$(TARGET)
