//---------------------------------------------------------------------------
// fictionbook.cpp
//---------------------------------------------------------------------------
// A fiction book object. Handles the creation and storage of a fiction book,
// containing title, author, number of copies "owned" by the library, and
// copies of this book currently checked in.
// 
// Ficiton sorted by author, then title
//
// Implementation:
//  -- initial character in input dictates 'f' for fiction
//---------------------------------------------------------------------------
#include "fictionbook.h"

#include <iomanip>
//---------------------------------------------------------------------------
//default constructor
FictionBook::FictionBook() {
    author_ = "";
    year_ = 0;
    title_ = "";
    itemType_ = 'F';
}

//---------------------------------------------------------------------------
//destructor
FictionBook::~FictionBook() {
}

//---------------------------------------------------------------------------
// buildBook
// file format: type author, title, year : istream passed in beginning at author
bool FictionBook::buildItem(istream& in) {
    string author;
    string title;
    int year;

    getline(in, author, ',');
    in.get(); // remove blank space
    getline(in, title, ',');
    in.get(); // remove blank space
    in >> year;
    setAuthor(author);
    setTitle(title);
    setYear(year);

    return (getAuthor() == author && getTitle() == title && getYear() == year);

}

//---------------------------------------------------------------------------
// create
Item* FictionBook::create() {
    return new FictionBook();
}

//---------------------------------------------------------------------------
//display
void FictionBook::display() const {
    cout << setw(5) << left << availableCopies_ << setw(37) << left << author_ <<  setw(37) << left << title_ << setw(37) << left << year_ << endl;
}

//---------------------------------------------------------------------------
//setAuthor
void FictionBook::setAuthor(string author) {
    author_ = author;
}

//---------------------------------------------------------------------------
// setYear
bool FictionBook::setYear(int year) {
    bool success = false;
    if (year > 0) {
        year_ = year;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// getAuthor
string FictionBook::getAuthor() const {
    return author_;
}

//---------------------------------------------------------------------------
// getYear
int FictionBook::getYear() const {
    return year_;
}

//---------------------------------------------------------------------------
// changeAvailable
bool FictionBook::changeAvailable(int num) {
    bool success = false;

    if (num == 1 && availableCopies_ < totalCopies_) {
        availableCopies_ += num;
        success = true;
    }
    else if (num == -1 && availableCopies_ > 0) {
        availableCopies_ += num;
        success = true;
    }
    return success;
 }

//---------------------------------------------------------------------------
// overloaded comparison operators 
// Fiction sorted by author, then title
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// overloaded operator<
bool FictionBook::operator<(const Item & rhsItem) const { 
    bool holder = false; 
        const FictionBook& rhsBookCasted = static_cast<const FictionBook&>(rhsItem);
    
    (getAuthor() < rhsBookCasted.getAuthor()) ? holder = true : holder = false;

    // if the book authors are the same, compare titles
    if (getAuthor() == rhsBookCasted.getAuthor()) {
        (getTitle() < rhsBookCasted.getTitle()) ? holder = true : holder = false;
    }

    return holder; 
}

//---------------------------------------------------------------------------
// overloaded operator>
bool FictionBook::operator>(const Item& rhsItem) const {
    bool holder = false;

    // cast book to fiction book 
    const FictionBook& rhsBookCasted = static_cast<const FictionBook&>(rhsItem);

    // compare titles, adjust bool as needed
    (getAuthor() > rhsBookCasted.getAuthor()) ? holder = true : holder = false;

    // if the book titles are the same compare authors
    if (getAuthor() == rhsBookCasted.getAuthor()) {
        (getTitle() > rhsBookCasted.getTitle()) ? holder = true : holder = false;
    }
    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator == 
bool FictionBook::operator==(const Item& rhsItem) const {
    bool holder = false; 

    // cast rhs book to fiction book
    const FictionBook& rhsBookCasted = static_cast<const FictionBook&>(rhsItem);

    // compare author, title, and year between two books 
    if (rhsBookCasted.getAuthor() == getAuthor() && rhsBookCasted.getTitle() == getTitle() && rhsBookCasted.getYear() == getYear()) {
        holder = true; 
    }
    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator !=
bool FictionBook::operator!=(const Item& rhsItem) const {
    return !(*this == rhsItem);
}

