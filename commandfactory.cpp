#include "commandfactory.h"

//---------------------------------------------------------------------------
// commandFactory()
CommandFactory::CommandFactory() {
    for (int i = 0; i < ALPHABET; i++) {
        commandTypes[i] = nullptr;
    }
    // Checkout, Return, History
     commandTypes[2] = new Checkout;
    commandTypes[7] = new History;
     commandTypes[17] = new Return;
}


//---------------------------------------------------------------------------
// createCommand()
Command* CommandFactory::createCommand(char type) const {
    // create new command pointer
    Command* toReturn = nullptr;

    // create subscript from hash
    int subscript = hash(type);

    // if command exists at hash location
    if (commandTypes[subscript] != nullptr) {
        toReturn = commandTypes[subscript]->create();
    }
    // TODO: Disucss if we need to do error handling? Too lazy to look at spec rn, think we do. If so, cout here & the 800000 places we haven't put it yet

    return toReturn;
}

//---------------------------------------------------------------------------
// destructor()
CommandFactory::~CommandFactory() {
    for (int i = 0; i < ALPHABET; i++) {
        delete commandTypes[i];
        commandTypes[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// hash
int CommandFactory::hash(char type) const {
    // change to uppercase if it's not
    type = toupper(type);
    int subscript = type - 'A';
    return subscript;
}