#include "checkout.h"
#include <iostream>

//---------------------------------------------------------------------------
// constructor
Checkout::Checkout() {
}

//---------------------------------------------------------------------------
// destructor
Checkout::~Checkout() {
}

//---------------------------------------------------------------------------
// display
void Checkout::display() {
    cout << "CheckOut  ";
    item_->display();
}

//---------------------------------------------------------------------------
// execute
// patron_ and item_ data fields are set
bool Checkout::execute() {
    bool success = false;

    // decrement available copies
    //add *this to user history

    // search the library for    //decrease book number available if theres some available
    // add to patron history
}