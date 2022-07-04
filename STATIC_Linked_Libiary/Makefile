compile_main_static_a-2:
	gcc -o main_aufgabe-2.elf main_aufgabe-2.c -l_static_gaussian -lm

compile_application_staticlib:
	gcc -c static_gaussian.c
	ar -crs lib_static_gaussian.a static_gaussian.o
	sudo cp static_gaussian.h /usr/include
	sudo cp lib_static_gaussian.a /usr/lib

compile_instream_random_generator:
	gcc instream_random_generator.c -o instream_random_generator.elf

execute_programm:
	./main_aufgabe-2.elf -s

execute_instream_random_generator:
	./instream_random_generator.elf
