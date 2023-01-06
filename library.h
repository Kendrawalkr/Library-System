//---------------------------------------------------------------------------
// library.h
//---------------------------------------------------------------------------
// Library class acts as interface between data files and storage / functions
//
// Assumptions:
// -- correctly formatted input from file
// -- each book item is uniquely identified by its srting criteria
// -- each command is uniquely and correctly identified by command char
// Implementation:
// -- holds a book factory, command factory, patron container, and bookcase
// -- Library reads input from data files
//---------------------------------------------------------------------------

#ifndef LIBRARY_H
#define LIBRARY_H

#include "shelf.h"
#include "itemfactory.h"
#include "command.h"
#include "commandfactory.h"
#include "patroncontainer.h"
#include "commandmanager.h"
#include <iostream>

using namespace std;


class Library {

public:
    // default constructor
    Library(); 

    // default destructor
    ~Library(); 

//---------------------------------------------------------------------------
    /** addPatron
     * @brief adds patron to patron container
     * @return true if patron was added, false if not
     * @param istream patron info from file
     */
    bool buildPatrons(istream&);

//---------------------------------------------------------------------------
    /** getPatronHistory
    * @brief prints patron book history to console
    * @param patron to get history from
    */
   // void printPatronHistory(const Patron&) const;

//---------------------------------------------------------------------------
// TODO comment
    bool runCommands(istream&);

//---------------------------------------------------------------------------
    /** buildBook
    * @brief interface between data file and book addition
    * @return true if book was added, false if not
    */
    bool buildItem(istream&);

//---------------------------------------------------------------------------
    /** displayContents
    * @brief displays books by category, sorted within the category
    */
    void displayItems() const;
   


//---------------------------------------------------------------------------
    /**
    * getPatron()
    * 
    * @brief Finds and returns a patron within the library system. Assigns desired
    * patron to a pointer to be used by calling function.
    * 
    * @param userID the ID of the Patron which is trying to be found
    * @param patron the pointer to be assigned to the found patron within 
    * container  
    * 
    * @return bool whether patron was successfully found 
    */
    bool getPatron(int userID, Patron*& patron); // how does this work? Is this supposed to be a pointer reference?

//---------------------------------------------------------------------------
    /**getItem
    * @brief retrieves an item from the library
    * @param target, the target item to fine
    * @param toReturn, Item returned by reference if found
    * @return true if found, false if not found
    */
    bool getItem(Item& target, Item*& toReturn);



private:

    // private data memebers
    ItemFactory itemF;
  //  CommandFactory commFactory;
  //  PatronContainer patronContainer;
    Shelf shelf;

 //  CommandFactory object
    CommandManager commManager;

    PatronContainer patContainer;
};

#endif
// TODO go through and delete uneccessary destructors - no strings & no dynamic memory
// TODO other functions we want in this class? from assignment