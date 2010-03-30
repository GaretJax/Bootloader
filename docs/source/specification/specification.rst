Anforderungsspezifikation
=========================

Funktional
----------

Muss
~~~~

Muss Ziele sind von der Projektspezifikation gegeben und müssen erfüllt werden.

#. Der Bootloader startet beim Einschalten des Geräts;
#. Der Bootloader kann eine Applikation aufnehmen und diese permanent speichern;
#. Der Bootloader kann eine permanente Applikation starten;
#. Der Benutzer kann eine exisitierende Applikation entfernen;
#. Binärdaten des Formats S-Record können behandelt werden;
#. Der Bootloader hat keine Auswirkung auf die funktionsweise der auszuführenden Applikation.

Kann
~~~~

#. Der Bootloader zeigt eine Auswahl an zu verfügung stehenden Applikation an;
#. Der Bootloader started nach einer gewissen Zeit eine vom Benutzer als default markierte Applikation;
#. Der Benutzer kann beliebig viele Applikation auf das Gerät aufnehmen, sofern sie den Speicherplatz nicht überschreiten;
#. Eine Applikation kann auf das Gerät geladen werden ohne es permanent zu speichern;
   Dies auch wenn der Speicherplatz des permanenten Specihers belegt ist. Dieses kann ausgeführt werden;
   Bei Neustart des Geräts ist dieses nicht mehr vorhanden. Nach nicht permanenten laden einer Applikation;
   ist der vorherige Zustand nach dem neustarten wieder hergestellt;
#. Nach permanentem speichern einer Applikation und späterer Löschung ist der Zustand für den Anwender unverändert;
#. Der Speicherplatz wird insofern optimal genutzt, dass keine unnötigen, nicht verwendbaren Lücken enstehen;
#. Es kann eine default Applikation gewählt werden, welche nach einem gewissen Timeout automatisch gestartet wird;
#. Eine default Applikation wird nicht mehr als 5 mal hintereinander autmatisch gestartet, falls dessen verarbeitung fehlerhaft war;
#. Der Bootloader hat keine auswirkung auf die Laufzeit der auszuführenden Applikation.

Nicht-Funktional
----------------

#. Der Code sowie Kommentar sind in englisch gehalten;
#. Der Source code muss dokumentiert sein;
#. Ein Nutzer mit shell Kentnissen kommt mit der Benutzerschnittstelle zurecht.
