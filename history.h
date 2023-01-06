//---------------------------------------------------------------------------
// history.h
//---------------------------------------------------------------------------
// Handles the operation of retrieving the history of a Patron within the
// library system. Returns and outputs their rental history of books from the
// library.
//
//---------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"
#include <iostream>

class History : public Command {
public:
    /**
     * @brief Construct a new History object. Default constructor.
     *
     * @post: history object will be created.
     */
    History();

    //---------------------------------------------------------------------------
        /**
         * @brief Destroy the History object and free memory.
         *
         * @pre: Assumes valid history object created.
         * @post: History object will be deleted and memory freed.
         */
    ~History();

    //---------------------------------------------------------------------------
        /**
         * @brief Handles the execution of the history retrieval for a patron
         * object. Outputs the check-out history of a given patron in a organized
         * fashion.
         *
         * @param input for execution of command
         * @return true if command was sucessfully executed
         * @return false if command was not successfully executed
         */
    virtual bool execute(istream& input);

private:
};

#endif