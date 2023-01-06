//---------------------------------------------------------------------------
// patron.cpp
//---------------------------------------------------------------------------
// A Patron class to store information on Patrons of the library
// Patron name, ID, book rental history and currently checked out books
// are all stored.
// Patron Objects are initiated in the Patron Factory.
//
// Assumptions:
//  -- rentalHistory has no limit
//  -- currentCheckOuts has no limit
//  -- userID will be unique identifier
// Implementation:
//  -- rentalHistory Book objects are stored in a STL list
//  -- currentCheckOuts Book objects are stored in a STL list
//  -- Once a book is added to currentCheckOuts it is added to rentalHistory
//---------------------------------------------------------------------------

#include "patron.h"

//---------------------------------------------------------------------------
// Constructor
Patron::Patron() {

// initialize member fields
	nameLastFirst_ = "";
	userID_ = 0;
}

//---------------------------------------------------------------------------
// destructor
Patron::~Patron() {

}


//---------------------------------------------------------------------------
// buildPatron
bool Patron::buildPatron(istream& inFile, int userID) {
	string nameLastFirst;
	userID_ = userID;

    // take name from inFile 
    getline(inFile, nameLastFirst);
    nameLastFirst_ = nameLastFirst;
	return true;
}

//---------------------------------------------------------------------------
// getFirst
string Patron::getName() const {
	return nameLastFirst_;
}

//---------------------------------------------------------------------------
// getID
int Patron::getID() const {
	return userID_;
}

//---------------------------------------------------------------------------
// printHistory
void Patron::printHistory() const {

	// go through list of commands ie. checkout, returns 
	// print via command functions the history
	// TODO
	//for (Command historyCommand : itemHistory) {
	//	historyCommand.display();
	//}
}


//---------------------------------------------------------------------------
// addToHistory
bool Patron::addToHistory(const Command comm) {

	// push history object to back of list (newest)
	itemHistory.push_back(comm);

}

//---------------------------------------------------------------------------
// searchCheckouts
bool Patron::searchCheckouts(const Item* target) const  {

}