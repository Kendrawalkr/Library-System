

#include "commandmanager.h"

/** 
 * runCommands()
 * Handles the parsing and execution calls for commands coming in through istream. 
 * @param inFile incoming file stream containing commands and run information
 */
bool CommandManager::runCommands(istream& inFile, Library& library) {
    
    // instantiate bool tracker
    bool success = false;

    // create storage for command char 
    char commandType;

    // create pointer to empty command
    Command* newCommand;

    for (;;) {
        // bring in first character in file to commandType
        inFile >> commandType;
        if (inFile.eof()) {
            break;
        }
        inFile.get(); // for empty space

        //create a new command of type
        newCommand = commFactory.createCommand(commandType);

        // if command character was invalid
        if (newCommand == nullptr) {
            // output error message
            cout << "Command: " << commandType << " is an invalid command" << endl;
            success = false;
        }
        else {
            return (newCommand->buildCommand(inFile, library));
        }
    }

    return success;

}