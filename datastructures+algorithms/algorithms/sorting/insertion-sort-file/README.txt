Schritte der Implementierung
-------------------------------------------------------------------------------

1) Lokales Repository anlegen und Projekt einchecken
Wir kopieren das Beispiel "insertion-sort-file-exercise" in ein eigenes 
Verzeichnis (inklusive unity Framework): 

insertion-sort-file-exercise/
    ├── data-sorted.txt
    ├── data.txt
    ├── insertion-sort.c
    ├── insertion-sort.h
    ├── Makefile
    ├── README.txt
    ├── test.c
    ├── TODO.txt
    └── unity
        ├── LICENSE.txt
        ├── README.md
        ├── unity.c
        ├── unity.h
        └── unity_internals.h

Ein lokales Git Repo wird erstellt, die Files werden eingecheckt (inklusive .gitignore):
$ git init
$ code .gitignore

$ git add .
$ git commit -m "Initial import."
$ git tag initial-state -m "Initial project."


2) test_insertion_sort_dynamic() 
Nach der Implementierung der neuen Test-Funktion (make läuft durch) werden die 
Änderungen ins Repo übernommen.
$ git add test.c
$ git commit -m "Extended test.c"
$ git tag task-a -m "Task A implemented." 

3) test_insertion_sort_file()
Implementieren Sie eine weitere Test-Funtion "test_insertion_sort_file()" zusammen
mit der Hilfsfunktion "data_read()".
Checkn Sie die Änderungen wieder ein.
$ git add test.c
$ git commit -m "Extended test.c again"
$ git tag task-b -m "Task B implemented." 

Um die Zwischenschritte der Entwicklung anzuzeigen verwenden wir das folgende 
Git Kommando:
$ git log 
