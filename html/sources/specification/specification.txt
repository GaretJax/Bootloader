Anforderungsspezifikation
=========================

Funktional
----------

Muss
~~~~

Muss Ziele sind von der Projektspezifikation gegeben und müssen erfüllt werden.

#. Nach einschalten der Hardware wird der Bootloader automatisch gestartet
#. Der Bootloader muss eine Applikation aufnehmen und diese permanent speichern;
#. Der Bootloader muss eine permanente Applikation starten;
#. Der Benutzer muss eine exisitierende Applikation entfernen;
#. Binärdaten des Formats S-Record können behandelt werden;
#. Der Bootloader hat keine Auswirkung auf die funktionsweise der auszuführenden Applikation.

Kann
~~~~

#. Der Bootloader zeigt eine Auswahl an zu verfügung stehenden Applikation an;
#. Der Bootloader started nach einer gewissen Zeit eine vom Benutzer als default markierte Applikation;
#. Eine Applikation kann auf das Gerät geladen werden ohne es permanent zu speichern;
   Dies auch wenn der Speicherplatz des permanenten Specihers belegt ist. Dieses kann ausgeführt werden;
   Bei Neustart des Geräts ist dieses nicht mehr vorhanden. Nach nicht permanenten laden einer Applikation;
   ist der vorherige Zustand nach dem neustarten wieder hergestellt;
#. Nach permanentem speichern einer Applikation und späterer Löschung ist der Zustand für den Anwender unverändert;
#. Der Speicherplatz wird insofern optimal genutzt, dass keine unnötigen, nicht verwendbaren Lücken enstehen;
#. Es kann eine default Applikation gewählt werden, welche nach einem gewissen Timeout automatisch gestartet wird;
#. Eine default Applikation wird nicht mehr als 5 mal hintereinander autmatisch gestartet, falls dessen verarbeitung fehlerhaft war;

Nicht-Funktional
----------------

#. Der Code sowie Kommentar sind in englisch gehalten;
#. Der Source code muss dokumentiert sein;
#. Ein Nutzer mit shell Kentnissen kommt mit der Benutzerschnittstelle zurecht. D. h., das Grundprinzip des Eingebens 
   von verschiedenen Kommandos und deren Parameter, sowie die Benutzung des "Hilfe" Befehls sollte dem Benutzer vertraut sein.
