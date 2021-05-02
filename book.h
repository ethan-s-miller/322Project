#ifndef BOOK_H
#define BOOK_H

#include "includes.h"
class Book
{

private:
    std::string title;
    std::string author;
    std::string genre;
    std::string isbn;

    void setAuthor(std::string author)
    {
        this->author = author;
    }

    void setGenre(std::string genre)
    {
        this->genre = genre;
    }
    
    void setISBN(std::string isbn)
    {
        this->isbn = isbn;
    }

    void setTitle(std::string title)
    {
        this->title = title;
    }




public:

    Book(){}

    Book(std::string title, std::string author, std::string genre, std::string isbn)
    {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->isbn = isbn;
    }

    std::string getTitle(){return this->title;}

    std::string getAuthor(){return this->author;}

    std::string getGenre(){return this->genre;}

    std::string getISBN() {return this->isbn;}







};

#endif
