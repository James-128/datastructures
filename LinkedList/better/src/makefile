objs =\
	access.o\
	main.o\
	display.o\
	mod.o

include_dir = ../include/
objects_dir = ../objects
main: objects
	gcc -I $(include_dir) $(objects_dir)/*

objects: $(objs)

%.o: %.c
	gcc -I $(include_dir) -c $< -o $(objects_dir)/$@


