compile_gaussian_application:
	gcc -o Programm_Gaussverteilung.elf Programm_Gaussverteilung.c -lm

execute_gaussian_application_to_stdout: compile_gaussian_application
	./Programm_Gaussverteilung.elf -e 150 -s 10 -n 1200

execute_gaussian_application_to_outstream.txt: compile_gaussian_application
	./Programm_Gaussverteilung.elf -e 150 -s 10 -n 1200 -o outstream.txt
