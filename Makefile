CC := g++ # this is the main compiler
# CC := clange --analyze # and comment out the linker last line
SRCDIR := src
BUILDDIR := build
TARGET := bin/main

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -Wextra -Wpedantic -std=c++14
LIBDIR := -L/usr/lib64/
LIB := -lsfml-graphics -lsfml-system -lsfml-window
INC := -Iinclude

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIBDIR) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIBDIR) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	@echo " $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester"; $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	@echo " $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket"; $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
