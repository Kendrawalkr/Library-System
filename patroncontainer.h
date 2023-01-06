//---------------------------------------------------------------------------
// patronContainer.h
//---------------------------------------------------------------------------
// PatonContaier class stores all patrons of the library and acts as an
// interface between the patron and the library class. The PatronContainer
// allows quick lookup for patrons.
//
// Assumtpions:
//  -- There can only be 10,000 patrons
//  -- userID will be unique identifier to lookup patrons
// Implementation:
//  -- Patrons are stored in an array
//---------------------------------------------------------------------------

#pragma once
#include "patron.h"
using namespace std;

class PatronContainer {
public:
    PatronContainer();  // constructor
    ~PatronContainer(); // destructor

    //---------------------------------------------------------------------------
    /** insert()
    * @brief Inserts created Patron object into container (the array of
    * patrons)
    * @param patron info from file
    * @return true if added, false otherwise
    */
    bool insert(istream&);

    //---------------------------------------------------------------------------
    /** retrieve()
    * @brief retrieves the patron
    * @param the uniqueID of the patron
    * @return the Patron with the associated uniqueID
    */
    bool retrieve(const int userID, Patron*&) const;
    
private:
    static const int PATRON_LIMIT = 10010;

    // array of patron objects, userID is a direct hash
    Patron* patronList[PATRON_LIMIT] = { nullptr }; // array of patrons
   
}; // end of PatronContainer class
