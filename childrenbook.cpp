#include "childrenbook.h"

#include "book.h"

#include <iomanip>

using namespace std;
//---------------------------------------------------------------------------
// Constructor
ChildrenBook::ChildrenBook() {
    author_ = "";
    year_ = 0;
    itemType_ = 'C';
}

//---------------------------------------------------------------------------
// Destruct1or
ChildrenBook::~ChildrenBook() {}

//---------------------------------------------------------------------------
// buildBook

bool ChildrenBook::buildItem(istream &inFile) {
    string title = "";
    string author = "";
    int year;

    getline(inFile, author, ',');
    inFile.get();  // remove blank space
    getline(inFile, title, ',');
    inFile.get();  // remove blank space
    inFile >> year;
    setAuthor(author);
    setTitle(title);
    setYear(year);

    return (getAuthor() == author && getTitle() == title && getYear() == year);
}

//---------------------------------------------------------------------------
// create
Item *ChildrenBook::create() { return new ChildrenBook(); }

//---------------------------------------------------------------------------
// setAuthor
void ChildrenBook::setAuthor(string author) { author_ = author; }

//---------------------------------------------------------------------------
// getAuthor
string ChildrenBook::getAuthor() const { return author_; }

//---------------------------------------------------------------------------
// setYear
bool ChildrenBook::setYear(int year) {
    if (year > 0) {
        year_ = year;
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// getYear
int ChildrenBook::getYear() const { return year_; }

//---------------------------------------------------------------------------
// display

void ChildrenBook::display() const {
    cout << setw(5) << left << availableCopies_<< setw(37) << left << title_ << setw(37) << left <<  author_ << setw(37) << left << year_ << endl;
}

//---------------------------------------------------------------------------
// changeAvailable
bool ChildrenBook::changeAvailable(int num) {
    bool success = false;

    // if return, check that a copy is missing
    if (num == 1 && availableCopies_ < COPIES) {
        availableCopies_ += num;
        success = true;
    }
    //if checkout, make sure there are copies
    if (num == -1 && availableCopies_ > 0) {
        availableCopies_ += num;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// overloaded comparison operators
// Children sorted by title, then author
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// overloaded operator <
bool ChildrenBook::operator<(const Item &rhsItem) const {
    bool holder = false;

    // cast book to children's book
    const ChildrenBook &rhsBookCasted =
        static_cast<const ChildrenBook &>(rhsItem);

    // compare titles
    (getTitle() < rhsBookCasted.getTitle()) ? holder = true : holder = false;

    // if the book titles are the same compare authors
    if (getTitle() == rhsBookCasted.getTitle()) {
        (getAuthor() < rhsBookCasted.getAuthor()) ? holder = true : holder = false;
    }
    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator>
bool ChildrenBook::operator>(const Item &rhsItem) const {
    bool holder = false;

    // cast book to children's book
    const ChildrenBook &rhsBookCasted =
        static_cast<const ChildrenBook &>(rhsItem);

    // compare titles, adjust bool as needed
    (getTitle() > rhsBookCasted.getTitle()) ? holder = true : holder = false;

    // if the book titles are the same compare authors
    if (getTitle() == rhsBookCasted.getTitle()) {
        (getAuthor() > rhsBookCasted.getAuthor()) ? holder = true : holder = false;
    }
    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator==
bool ChildrenBook::operator==(const Item &rhsItem) const {
    bool holder = false;

    // cast rhs book to children's book
    const ChildrenBook &rhsBookCasted =
        static_cast<const ChildrenBook &>(rhsItem);

    // compare author, title, and year between two books
    if (rhsBookCasted.getAuthor() == getAuthor() &&
        rhsBookCasted.getTitle() == getTitle() &&
        rhsBookCasted.getYear() == getYear()) {
        holder = true;
    }
    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator !=
bool ChildrenBook::operator!=(const Item &rhsItem) const {
    // use comparison operator to return value
    return !(*this == rhsItem);
}