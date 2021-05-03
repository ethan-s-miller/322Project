#include "BookManager.hpp"

/** How the csv file is structured:
 *      ISBN,Title,Author,Genre
 *  For example:
 *      1012,Dune,Frank Herbert,Sci-Fi
 *  No spaces in-between commas.
 *  The ISBN, Author, Title, and Genre strings should not have commas in them.
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
    std::ofstream library(this->mFile, std::ofstream::app);
    if(!library.is_open())
    {
        library.close();
        throw mFile; // Failed to open mFile with write access
    }

    library << book.getISBN() << ",";
    library << book.getTitle() << ",";
    library << book.getAuthor() << ",";
    library << book.getGenre() << "\n";

    library.close();
}

void BookManager::remove(std::string isbn)
{
    std::fstream library(this->mFile, std::fstream::in | std::fstream::out);
    if(!library.is_open())
    {
        library.close();
        throw mFile; // Failed to open mFile with read access
    }

    std::string line, books;
    while(!library.eof())
    {
        std::getline(library, line);
        books += line;
    }

    size_t pos = books.find(isbn);
    if (pos == std::string::npos)
        return;
    books.erase(pos, books.find_first_of('\n', pos) + 1);

    library << books;
    library.close();
}

Book BookManager::get(std::string isbn)
{
    std::ifstream library(this->mFile);
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
            line = line.substr(line.find_first_of(','), line.size() - 1);
            
            std::string title = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','), line.size() - 1);
            
            std::string author = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','), line.size() - 1);
            
            std::string genre = line;

            library.close();
            return Book(title, author, genre, isbn);
        }
    }
    library.close();
    throw isbn; // Failed to retrieve the book of the given isbn
}

std::vector<Book> BookManager::search(std::string searchString)
{
    std::vector<Book> results;
    
    std::ifstream library(this->mFile);
    if(!library.is_open())
    {
        library.close();
        throw mFile; // Failed to open mFile with read access
    }

    std::string line;
    while(!library.eof())
    {
        std::getline(library, line);
        if (line.find(searchString) != std::string::npos)
        {
            std::string isbn = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','), line.size() - 1);
            
            std::string title = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','), line.size() - 1);
            
            std::string author = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','), line.size() - 1);
            
            std::string genre = line;

            results.push_back(Book(title, author, genre, isbn));
        }
    }
    library.close();
    return results;
}