all: dir_info.c
	gcc dir_info.c
run: all
	./a.out
