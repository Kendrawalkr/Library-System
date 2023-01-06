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
#pragma once
#include "library.h"
#include "itemfactory.h"

class Command {
public:
    /**
     * @brief Construct a new Command object. Default constructor.
     * @post: Command object will be created.
     */
    Command();

    //---------------------------------------------------------------------------
    /**
     * @brief Destroy the Return object and free memory.
     * @pre: Assumes valid command object created.
     * @post: Command object will be deleted and memory freed.
     */
    virtual ~Command();

    //---------------------------------------------------------------------------
    /**
    * @brief Handles the execution of given code determined by input.
    * @param istream for execution of command
    * @return true if command was sucessfully executed
    * @return false if command was not successfully executed
        */

        // TODO: I don't think this is virtual, how would it work?
    virtual bool execute() = 0;

    virtual void display() = 0;

    bool buildCommand(istream& inFile, Library& library);

private:

protected:
    Library& library_;
    ItemFactory itemFactory_;
    Patron* patron_;
    Item* item_;