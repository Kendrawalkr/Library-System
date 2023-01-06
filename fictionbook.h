//---------------------------------------------------------------------------
// fictionbook.h
//---------------------------------------------------------------------------
// A fiction book object. Handles the creation and storage of a fiction book,
// containing title, author, number of copies "owned" by the library, and
// copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'f' for fiction
//---------------------------------------------------------------------------
#include "book.h"
#include <iostream>

class FictionBook : public Book {
    /**
     * @brief Output operator overload for FictionBook object. Dictates output
     * formatting and functionality for a fiction book.
     *
     * @return ostream& containing information to be output in a formatted style
     * @pre: Assumes valid FictionBook object being passed in.
     * @post: none
     */
    friend ostream& operator<<(ostream&, const FictionBook&);

public:
    /**
     * @brief Construct a new FictionBook object
     * @pre: assumes object needs to be created
     * @post: new FictionBook object
     */
    FictionBook();

    //---------------------------------------------------------------------------
    /**
    * @brief Destroy the FictionBook object.
    * @pre: assumes valid object to be deleted
    * @post: object will be deleted & memory freed
    */
    ~FictionBook();

    //---------------------------------------------------------------------------
     /** buildBook
    * @brief creates book object reading from data file
    * @pre: A correctly formatted open data file
    * @post: a new book object
    */
    bool buildItem(istream& in);

    //---------------------------------------------------------------------------
    /** create
     * @brief Creates a fiction book object, then returns a copy of that object
     * for the factory to function properly.
     * @return FictionBook copy of newly created book object
     * @post: new fiction book object is created and returned.
     */
    virtual Item* create();

    //---------------------------------------------------------------------------
    /** display
     * @brief displays the book copies, author, title and year to console.
     * @post contents displayed to console
     */
    virtual void display() const;

    /** setAuthor
     * @brief sets the author data member of the book
     * @pre a new book object
     * @post a book object with a set author
     */
    void setAuthor(string author);

    /** setYear
     * @brief sets the year data member
     * @pre a new book object
     * @post a book object with a published year
     */
    bool setYear(int year);

    /** getAuthor
     * @brief gets and returns the book author
     * @pre book object has set author
     * @post string of author is returned
     */
    string getAuthor() const;

    /** getYear
     * @brief returns the book published year
     * @pre a book object with set year
     * @post int year is returned
     */
    int getYear() const;

    /** changeAvailable
     * @brief changes the available copies for the given item
     * @return bool if change was successful
     */
    virtual bool changeAvailable(int num);

    /**
* Less than operator. Compares LHS and RHS for lesser value.
* @param rhsItem rhs Book being passed in
* @return true
* @return false
*/
    bool operator<(const Item& rhsItem) const;

    /**
      *
      * Greater than operator. compares LHS and RHS for greater value.
      * @param rhsItem rhs Book being passed in for comparison
      * @return true
      * @return false
      */
    bool operator>(const Item& rhsItem) const;

    /**
      * Equals operator. Determines if two Book objects are equal.
      *
      * @param rhsItem rhs Book being passed in for equals comparison
      * @return true
      * @return false
      */
    bool operator==(const Item& rhsItem) const;

    /**
      * Does not equals operator. Determines if two books are not equal.
      *
      * @param rhsItem
      * @return true
      * @return false
      */

    bool operator!=(const Item& rhsItem) const;

private:

    // author of the book, last then first name
    string author_;

    //publishing year
    int year_;

    static const int COPIES = 5;
    int availableCopies_ = COPIES;
    int totalCopies_ = COPIES;
};
