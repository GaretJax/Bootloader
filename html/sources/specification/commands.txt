Befehle
=======

.. todo::
   * Add more text describing the commands.
   * Do the commands returns something? A little phrase would be neat for the
     user, but a value is better if we access the API programmatically.

``help``

  Zeigt eine Liste aller möglichen Befehle an.

---------------

``help command-name``

  Zeigt die Hilfe für ``command-name`` an.

---------------

``download [-b app-name [-d]]``

  Lädt die folgenden Daten in den Arbeitsspeicher als eine SRecord Datei.
  
  -b app-id            Führt den Befehl ``burn app-id`` aus.
  -d                     Setzt die Applikation als default Startanwendung 

---------------

``burn app-name [-d]``

  Speichert das sich im Arbeitsspeicher befindende SRecordFile in den Flashspeicher unter dem Namen ``app-name``.
  
  -d                     Setzt die zu brennende Applikation als default Startanwendung

---------------

``run [-r|app-id]``

  Führt die default, oder die mit dem ``app-id`` identifizierte Applikation aus.
  
  -r                     Führt das sich im Arbeitsspeicher befindende SRecordFile aus.

---------------

``list``

  Führt eine Liste der sich im Flashspeicher befindenden Applikationen auf.

---------------

``set [--default=app-id] [--timeout=seconds] [...]``

  Setzt die Werte der gegebenen Konfigurationsoptionen.
  
  -d app-id              Siehe ``--default-app``
  --default=app-id       Setzt die default Applikation
  -t seconds             Siehe ``--default-app``
  --timeout=seconds      Setzt die Wartezeit nach der die default Applikation gestartet werden soll
  -e num                 Siehe ``--default-app``
  --errcount=num         Anzahl Neustarts im Falle eines fehlerhafen Starts einer Applikation.
                         Sobald errorcount erreicht ist, wird das Timeout deaktiviert und den Bootloader wird in Terminal-Mode umschalten.

---------------

``bootconfig``

  Führt die aktuelle Konfiguration (app-name, timeout, errorcount) des Bootloaders auf.

---------------

``erase app-id``

  Entfernt die mit dem ``app-id`` identifizierte Applikation aus der Applikationsliste des Flashspeichers.
