//---------------------------------------------------------------------------
// periodicalbook.cpp
//---------------------------------------------------------------------------
// A periodical book object. Handles the creation and storage of a periodical
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in.
//
// Assumptions:
//  -- initial character in input dictates 'p' for periodical
//---------------------------------------------------------------------------
#include "periodicalbook.h"
#include <iomanip>

//---------------------------------------------------------------------------
// default constructor
PeriodicalBook::PeriodicalBook() {
    month_ = 0;
    year_ = 0;
    title_ = "";
    itemType_ = 'P';
}

//---------------------------------------------------------------------------
// destructor
PeriodicalBook:: ~PeriodicalBook() {
}

//---------------------------------------------------------------------------
// buildBook
// file format: type title, month year
bool PeriodicalBook::buildItem(istream& in) {
    string title;
    int month;
    int year;

    getline(in, title, ',');
    in.get(); // remove blank space
    in >> month;
    in.get(); // remove blank space
    in >> year;
    setTitle(title);
    setMonth(month);
    setYear(year);

    return (getTitle() == title && getMonth() == month && getYear() == year);
}

//---------------------------------------------------------------------------
// create
Item* PeriodicalBook::create() {
    return new PeriodicalBook();
}

//---------------------------------------------------------------------------
// display
void PeriodicalBook::display() const {
    cout << setw(5) << left << availableCopies_ << setw(3) <<  month_ << setw(34) << left <<  year_ << setw(30) << title_ << endl;
}

//---------------------------------------------------------------------------
//setMonth
bool PeriodicalBook::setMonth(int month) {
    bool success = false;
    if (month > 0 && month <= 12) {
        month_ = month;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// getMonth
int PeriodicalBook::getMonth() const {
    return month_;
}

//---------------------------------------------------------------------------
//setYear
bool PeriodicalBook::setYear(int year) {
    bool success = false;
    if (year > 0) {
        year_ = year;
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
//getYear
int PeriodicalBook::getYear() const {
    return year_;
}

//---------------------------------------------------------------------------
//changeAvailable
bool PeriodicalBook::changeAvailable(int num) {
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
// Periodicals sorted by date (year, then month), then by title 
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// overloaded operator<
bool PeriodicalBook::operator<(const Item& rhsItem) const {
    bool holder = false;

    // cast book to preiodical book 
    const PeriodicalBook& rhsBookCasted = static_cast<const PeriodicalBook&>(rhsItem);

    // compare year
    if (year_ < rhsBookCasted.getYear()) {
        holder = true;
    }
    // if year is the same compare month
    else if (getYear() == rhsBookCasted.getYear()) {
        if (month_ < rhsBookCasted.getMonth()) {
            holder = true;
        }
        // if the month is the same compare title
        else if (month_ == rhsBookCasted.getMonth()) {
            if (title_ < rhsBookCasted.getTitle()) {
                holder = true;
            }
        }
    }

    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator >

bool PeriodicalBook::operator>(const Item& rhsItem) const {
    bool holder = false;

    // cast book to preiodical book 
    const PeriodicalBook& rhsBookCasted = static_cast<const PeriodicalBook&>(rhsItem);

    // compare year
    if (year_ > rhsBookCasted.getYear()) {
        holder = true;
    }
    // if year is the same compare month
    else if (getYear() == rhsBookCasted.getYear()) {
        if (month_ > rhsBookCasted.getMonth()) {
            holder = true;
        }
        // if the month is the same compare title
        else if (month_ == rhsBookCasted.getMonth()) {
            if (title_ > rhsBookCasted.getTitle()) {
                holder = true;
            }
        }
    }

    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator==
bool PeriodicalBook::operator==(const Item& rhsItem) const {
    bool holder = false;

    // cast rhs book to periodical's book
    const PeriodicalBook& rhsBookCasted = static_cast<const PeriodicalBook&>(rhsItem);

    // compare year, month, title
    if (year_ == rhsBookCasted.getYear() && month_ == rhsBookCasted.getMonth() && title_ == rhsBookCasted.getTitle()) {
        holder = true;
    }

    return holder;
}

//---------------------------------------------------------------------------
// overloaded operator!=
bool PeriodicalBook::operator!=(const Item& rhsItem) const {
    // use comparison operator to return value
    return !(*this == rhsItem);
}
