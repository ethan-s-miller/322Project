#include "BookManager.hpp"

/** How the csv file is structured:
 *      ISBN,"Title","Author","Genre"
 *  For example:
 *      1012,"Dune","Frank Herbert","Sci-Fi"
 *  No spaces in-between commas.
 *  The author and title strings are surrounded by qoutes because there could
 *    possibly be commas within them (i.e. "Herbert, Frank").
 *  The genre string is surrounded by qoutes so that a book can have multiple genres
 *    where each comma within these quotes seperates a genre the book is classified under.
 *  The title, genre, and author strings cannot contain qoutes.
 */

BookManager::BookManager()
{
    this->mFile = "books.csv";
}

BookManager::BookManager(std::string file)
{
    this->mFile = file;
}

BookManager::~BookManager()
{

}

void BookManager::add(Book book)
{
    std::ofstream library;
    library.open(this->mFile);
    if(!library.is_open())
    {
        library.close();
        throw mFile; // Failed to open mFile with write access
    }

    library << book.getISBN() << ",";
    library << "\"" << book.getTitle() << "\",";
    library << "\"" << book.getAuthor() << "\",";
    library << "\"" << book.getGenre() << "\"\n";

    library.close();
}

void BookManager::remove(std::string isbn)
{
    
}

Book BookManager::get(std::string isbn)
{
    std::ifstream library;
    library.open(this->mFile);
    if(!library.is_open())
    {
        library.close();
        throw mFile; // Failed to open mFile with read access
    }

    std::string line;
    while(!library.eof())
    {
        std::getline(library, line);
        if (line.substr(0, line.find_first_of(',')) == isbn)
        {
            line = line.substr(line.find_first_of('\"'), line.size() - 1);
            std::string title = line.substr(0, line.find_first_of('\"'));

        }
    }
}

Book BookManager::search(std::string searchString)
{

}