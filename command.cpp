//---------------------------------------------------------------------------
// command.h
//---------------------------------------------------------------------------
// Handles the commands from the file. Manages subclasses using input command
// characters.
// 
// Assumptions:
// --
// Implementation:
// --
//
//---------------------------------------------------------------------------

#include "command.h"

//---------------------------------------------------------------------------
// constructor
Command::Command() {
//

}

//---------------------------------------------------------------------------
// destructor
Command::~Command() {
    patron_ = nullptr;
    item_ = nullptr; 
}


//---------------------------------------------------------------------------
// buildCommand
// data format passed in: Patron userID ItemType  itemFormat  then item specific data(author, titiel, or date for p)
bool Command::buildCommand(istream& inFile, Library& library) {
    //has access to library
    library_ = library;


    int patronID;
    inFile >> patronID; // user ID is stored
    inFile.get(); // clear empty space

    // search the library for existing patron
    Patron* patron;
    if (!library.getPatron(patronID, patron)) {
        cout << "User ID: " << patronID << " is an invalid user ID" << endl;
        return false;
        // if the patron exists then check library for the item
         
        // build the target item from the data file for comparison
        // create copy of item being checked out
        // place in this checkout
        // decrement the original item currentAvailable_
        // place this into patron 
    }
    else {
        patron_ = patron;
    }
    // patron is valid here
    // check if item is valid 

    // create an item from the data file for comparison
    Item* target;
    char type;
    inFile >> type;
    inFile.get(); // skips blank space

    //set Item Format
    char format;
    inFile >> format;

    target = itemFactory_.createItem(type);
    if (!target->setFormat(format)) {
        cout << "Item Format: " << format << " is and invalid format" << endl;
        string garbage;
        getline(inFile, garbage);
        return false;
    }
    // empty command object
    // pass the patron, and the item. and call.

    target->buildItem(inFile);
    Item* found;
    if (library.getItem(*target, found)) {
        item_ = found;
    }


    return execute();

}