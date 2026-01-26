# Aufgabenstellung IP1 Lab12: LINUX
Nach dem Installieren der VirtualBox und einrichten der Linux Umgebung starten sie die Linux Umgebung:
* Background: [Setup Linux](https://github.com/teiniker/teiniker-lectures-computerscience/blob/master/introduction/setup/Environment-Linux.md)

## Starten sie ein Terminal (bash) als User (student)
* Background: [Arbeiten im Dateisystem](https://github.com/teiniker/teiniker-lectures-computerscience/blob/master/linux/filesystem/FileSystemCommands.md)
  
## Erstellen sie ein neues File in `/etc/skel` mit dem Namen  `Hello.txt`.
  * Editieren sie dieses File mit dem Editor `vim`:  `vim Hello.txt`
  * Einfügen des Texts: `Hallo, dies ist das Willkommensfile..`
  * Speichern und Editor beenden
  * Background: [vim als Editor](https://github.com/teiniker/teiniker-lectures-computerscience/blob/master/linux/editors/vim.md)

![Navigieren zu /etc/skel](figures/cmd1.png)
![Navigieren zu /etc/skel](figures/vim1.png)

![Navigieren zu /etc/skel](figures/vim2.png)

Als `student` hat man keine Schreibrechte in `/etc/skel`.

Daher verlassen wir den Editor mit `:q!`.
![Navigieren zu /etc/skel](figures/cmd_skel.png)

Lösung: Wechseln des Benutzers oder `sudo` (mit den Rechten des `root` Benutzers) und erneuter Versuch das File zu erstellen.
![Navigieren zu /etc/skel](figures/Sudo_vim.png)

## Legen sie einen neuen Benutzer an (`Nachname_Vorname`)
* Background: [Benutzerverwaltung](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/linux/user-management)
  
![Navigieren zu /etc/skel](figures/add_user.png)
* Wechseln sie zum neuen User
* Welches File finden sie im `/home/Nachname_Vorname` Verzeichnis
* Ausgabe des Fileinhaltes mittels `cat Hallo.txt`
![Navigieren zu /etc/skel](figures/switch_user.png)

## Clonen des Repositories:
* Wechseln sie wieder zum Benutzer `student`
* Erstellen sie das Verzeichnis `/home/student/Study/Sem1/IP1`
* Clonen sie `https://github.com/teiniker/teiniker-lectures-computerscience.git` in dieses Verzeichnis (einfügen der Zwischenablage mittels `Strg + Shift + V`)
![Navigieren zu /etc/skel](figures/git_clone.png)
  
## Compilieren und ausführen in Visual Studio Code:
* Starten sie VS Code
![Navigieren zu /etc/skel](figures/start_VScode.png)
* File -> Open Folder
![Navigieren zu /etc/skel](figures/VSC_openFolder.png)
* Yes, I trust the autors
* Öffnen eines bestehenden *.c; Run code...
![Navigieren zu /etc/skel](figures/VSC_run.png)
Debian/linux intro done!

*Martin Kohl, 2026-2026, GPL v3.0* 