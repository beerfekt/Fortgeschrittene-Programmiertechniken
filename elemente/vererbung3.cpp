


//###########  Person (base) ######################


//person.h

protected:
    string name;

public:
   virtual void dynamisch() const; //Überschrieben
--)
//person.cpp

 //dynamisch()
     cout << name << endl;



//##########  Mitarbeiter (derived) ##################


//mitarbeiter.h
private:
  long sozialNr;

public:
 virtual void dynamisch()const override;



//mitarbeiter.cpp

  //dynamisch()
     cout << name    << endl;
     cout << sozialNr << endl;



//##################### main ##########################

  Mitarbeiter m;
  m.dynamisch();  //ausgabe:  "name, sozialNr"






