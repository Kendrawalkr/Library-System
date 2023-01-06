//---------------------------------------------------------------------------
// return.h
//---------------------------------------------------------------------------
// Handles the operation of returning a book into the library system. Both by
// unassigning the book from the patron who checked it out, and modifying the
// values for currently checked in copies of the book.
//---------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include <iostream>

class Return : public Command {
public:
    /**
     * @brief Construct a new Return object. Default constructor.
     *
     * @post: Return object will be created.
     */
    Return();

    //---------------------------------------------------------------------------
        /**
         * @brief Destroy the Return object and free memory.
         *
         * @pre: Assumes valid return object created.
         * @post: Return object will be deleted and memory freed.
         */
    ~Return();

    //---------------------------------------------------------------------------
        /**
         * @brief Handles the execution of the return of the given book
         * into the library system.
         *
         * @param input for execution of command
         * @return true if command was sucessfully executed
         * @return false if command was not successfully executed
         */
    virtual bool execute(istream& input);

    virtual void display();

private:
    Item* theItem;
    Patron* thePatron;
};

#endif