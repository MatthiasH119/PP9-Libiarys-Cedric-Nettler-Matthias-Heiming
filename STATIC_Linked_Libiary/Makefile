application_main_static_a-2: application_staticlib
	gcc -o main_aufgabe-2.elf main_aufgabe-2.c -l_static_gaussian

application_staticlib:
	gcc -c static_gaussian.c
	ar -crs lib_static_gaussian.a static_gaussian.o
	sudo cp static_gaussian.h /usr/include
	sudo cp lib_static_gaussian.a /usr/lib
