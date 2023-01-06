//---------------------------------------------------------------------------
// checkout.h
//---------------------------------------------------------------------------
// Handles checking out a book.
//
// Implementation:
//  -- library calls execute to check out a book to a patron
//---------------------------------------------------------------------------
#include "command.h"

class Checkout : public Command {
public:
    Checkout(); // default

    ~Checkout();
    /** display()     
     * @brief Handles output and display of the checkout information
     */
    virtual void display();

    /**
     * @brief checks out a book to a patron
     * @return true able to checkout book, false otherwise
     * @post patron is assigned a book and one less copy of book is available
     *       if any were available to begin with
     */
    virtual bool execute();

private:
    Item* item_;
    Patron* patron_;
};
