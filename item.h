//---------------------------------------------------------------------------
// item.h
//---------------------------------------------------------------------------
// An abstract class.
// An item class for the library to store different types of items.
// Current item types are book, but can be other types such as DVD, magazine, etc.
// Assumptions:
//  --
// Implementation:
//  --
//---------------------------------------------------------------------------

#pragma once
#include <string>
using namespace std;

class Item {
public:


    //---------------------------------------------------------------------------
    //constructor
    Item();

    //---------------------------------------------------------------------------
    //destuctor
    virtual ~Item();

//---------------------------------------------------------------------------
    /** buildItem
   * @brief creates item object reading from data file
   * @pre: A correctly formatted open data file
   * @post: a new item object 
   */
   virtual bool buildItem(istream& in) = 0;

      /** display
     * @brief prints the contents of the item to console,
     * pure virtual function
     * @pre implemented display() in child classes
     * @post book contents displayed to console
     */
   virtual void display() const = 0;


      /** create
     * @brief creates a new item object, pure virutal funciton
     * @pre implemented create() in child classes
     * @return returns a pointer to a new item object
     */
   virtual Item *create() = 0;

   char getType() const;

   virtual bool setFormat(char format);

   virtual bool changeAvailable(int num) = 0;

     /**
    * Less than operator. Compares LHS and RHS for lesser value.
    * @param rhsBook rhs item being passed in
    * @return true
    * @return false
    */
   virtual bool operator<(const Item &rhsItem) const = 0;


     /**
     *
     * Greater than operator. compares LHS and RHS for greater value.
     * @param rhsItem rhs Item being passed in for comparison
     * @return true
     * @return false
     */
   virtual bool operator>(const Item &rhsItem) const = 0;


   /**
     * Equals operator. Determines if two Item objects are equal.
     *
     * @param rhsItem rhs Item being passed in for equals comparison
     * @return true
     * @return false
     */
   virtual bool operator==(const Item &rhsItem) const = 0;


   /**
     * Does not equals operator. Determines if two items are not equal.
     * @param rhsItems
     * @return true
     * @return false
     */

   virtual bool operator!=(const Item &rhsItem) const = 0;


private:

protected:
    char itemType_; 
    char format_;
    static const int FORMATS = 26;
    bool validFormat[FORMATS] = { false };
};