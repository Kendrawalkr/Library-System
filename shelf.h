//---------------------------------------------------------------------------
// shelf.h
//---------------------------------------------------------------------------
// Holds containers of items of different genres.
//
// Assumptions:
//  -- each genre is uniquely identified by a letter
//  -- there cannot be two genres with the same letter
// Implementation
//  -- containers[] 
//  -- uses a hash table to store containers for differnt genres
//  -- each genre is associated with a letter e.g: F- fiction
//  -- array size is 26, letters a...z correlate directly to index 0...25
//  -- uses a hash table of binary search trees to store the books
//  -- first letter of genre is stored as char
//  -- no destructor - no dynamically allocated memory
//---------------------------------------------------------------------------

#ifndef SHELF
#define SHELF

#include "itemcontainer.h"
#include "itemfactory.h"
#include <iostream>

class Shelf {
    friend ostream& operator<<(ostream&, const Shelf&);

public:

    Shelf();  // contructor

    ~Shelf(); // destructor

//--------------------------------------------------------------------------
    /** insert
     * @brief inserts book into a container 
     * @pre existing book object of any type
     * @post book is unchanged
     * @return true book inserted, false book not inserted
     * @param book to be inserted
     */
    bool insert(Item*);

    //---------------------------------------------------------------------------
    /** buildBook
    * @brief interface between data file and book addition
    * @return true if book was added, false if not
    */
    bool buildItem(istream& in);

    //--------------------------------------------------------------------------
    /** checkOut
    * @brief checks and gets the item that needs to be checked out
    * @pre Item object of target
    * @post decrements copies of item available by 1 if item is available
    * @return true if successful false if not
    * @param item to be checkout out
    */
    bool retrieve(Item& target, Item*& toReturn);

    //---------------------------------------------------------------------------
    /** display
    * @brief displays all the contents of containers to console
    * @post each BookContainer in containers displayed to console
    */

    void display() const;


private:

    static const int ITEM_TYPES = 26;

    // hash funtion to get genre 
    int hash(char) const;
    
    bool validCodes[ITEM_TYPES];


    // array that stores containers by genre
    ItemContainer* containers[ITEM_TYPES]; 
};

#endif
