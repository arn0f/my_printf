###############################################################################
#
# File Name         : Makefile
# Created By        : Arnaud Fredon
# Creation Date     : septembre 10th, 2015
# Last Change       : septembre 22th, 2015 at 22:52:12
# Last Change       : septembre 22th, 2015 at 22:52:12
# Purpose           : It's allow to compile our project easier
#                       - all   : Compile all source presents
#                       - clean : Clean all objects and executable
#
###############################################################################

#### INITIAL PARAMETERS ####
EXECUTABLE=bin/my_printf
SOURCES=$(wildcard *.c)
CFLAGS=-Wall -pedantic -ansi
LDFLAGS=
CC=gcc
OBJECTS=$(SOURCES:.c=.o)

#### TARGETS ####
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -lm $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	rm $(OBJECTS)

clean:
	rm $(OBJECTS) $(EXECUTABLE)

