//---------------------------------------------------------------------------
// main.cpp
//---------------------------------------------------------------------------

#include "library.h"
#include <fstream>
#include <iostream>

using namespace std;



int main() {

    string compare = "Danny Dunn & the Homework Machine";
    string comrade = "I Hate My Brother Harry";
    Library lib;
    ifstream books;
    //ifstream books, patrons, commands;
    books.open("data4books.txt");
    lib.buildItem(books); // initialize books
    lib.displayItems();
    //patrons.open("patronsFile");
    //lib.buildPatrons(patrons); // initialize patrons
    //commands.open("commandFile");
    //lib.commandHandler(commands); // initialize commands


    return 0;
}


