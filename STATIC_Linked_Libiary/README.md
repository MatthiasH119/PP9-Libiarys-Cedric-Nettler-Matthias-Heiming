#  STATIC_Linked_Libiary 	

Hallo und Herzlich willkommen in unserer Static Linked Libiary,

hier haben Sie die Möglichkeit über den Befehl 'make make' mehrere Programme zu kompilieren und auszuführen.
Mit dem ersten Programm werden 100 Zufallszahlen erstellt, welche in der Datei mit dem Namen "instream.txt" gespeichert werden.
Anschließend werden diese Zufallszahlen an das eigenliche Programm 'main_aufgabe-2.c' übergeben und Sie erhalten direkt eine 
Ausgabe mit einer "expected value" und und einer "standard deviation" dieser Zufallszahlen.



Alternativ können die Programme wie folgt einzeln kompiliert und ausgeführt werden:

nutze: 'make compile_application_staticlib', zum kompilieren der static lib
nutze: 'make compile_main_static_a-2', zum kompilieren des main programms
nutze: 'make compile_instream_random_generator', zum kompilieren des Zufallsgenerators

nutze: 'make execute_programm' bzw. './main_aufgabe-2.elf -s', zum ausführen des Programms
nutze: 'make execute_instream_random_generator' bzw. './instream_random_generator.elf', zum ausführen des Zufallsgenerators

Der Zufallsgenerator erstellt eine unsortierte Reihe von Gaussverteilten Zahlen mit dem ungefähren Mittelwert: 'MAX' (definierter Wert in instream_random_generator.c, liegt aktuell bei 500)
Alternative zur Nutzung des Zufallsgenerators: eintragen von 100 Integer Zahlen in die Datei: 'instream.txt'




Wir hoffen, unser Programm gefällt ihnen.

# Autoren: 	Matthias Heiming & Cedric-Julian Nettler

		
