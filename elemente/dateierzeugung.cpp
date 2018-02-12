	std::ofstream file("test.txt");  //1
	file << "Text"; //2
 }//3

 	//1 Erzeugen und Öffnen der Datei test.txt → Zustand im Objekt file
	//2 Beschreiben der Datei
	//3 Die lokale Variable file erreicht ihr Lebensdauerende und wird zerstört 
               //→ die Datei wird geschlossen und ggf. gepufferter Inhalt wird synchronisiert.
