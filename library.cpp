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

#include "library.h"

//---------------------------------------------------------------------------
// constructor
Library::Library() {

}

//---------------------------------------------------------------------------
// destructor
Library::~Library() {
}

//---------------------------------------------------------------------------
// buildPatron
//bool Library::buildPatrons(istream& in) {
//    // data format --> ID# Last First
//    //return patronContainer.insert(in);
//    // no patron factory - create patron object here?
//    return false;
//}

//---------------------------------------------------------------------------
// printPatronHistory
//void Library::printPatronHistory(const Patron&) const {
    //TODO do we want to go directly to patron? or access through patron container
//}

//---------------------------------------------------------------------------
// runCommands
bool Library::runCommands(istream& inFile) {
    return commManager.runCommands(inFile, *this);
}


//---------------------------------------------------------------------------
// buildBook
bool Library::buildItem(istream& in) {
   return shelf.buildItem(in);
}


//---------------------------------------------------------------------------
// displayItems
void Library::displayItems() const {
    shelf.display();
}

//---------------------------------------------------------------------------
// getPatron
bool Library::getPatron(int userID, Patron*& patron) {
    bool success = false;

    // valid ID retrieve patron from PatronContainer
    if (userID > 0 && userID < 10000) {
        patContainer.retrieve(userID, patron);
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// getItem
bool Library::getItem(Item& target, Item*& toReturn) {

    bool success = false;

    // retrieve item from shelf
    Item* retrieved;

    // if successfully retrieved item
    if (shelf.retrieve(target, retrieved)) {
        
        // set referenced to item to found item 
        toReturn = retrieved;
        success = true;

    }

    return success;
    
}