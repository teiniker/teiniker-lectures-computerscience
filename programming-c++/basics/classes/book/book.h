#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    // Constructor
    Book(const std::string& isbn, const std::string& author, const std::string& title);

    // Accessor methods for isbn
    std::string getIsbn() const;
    void setIsbn(const std::string& isbn);

    // Accessor methods for author
    std::string getAuthor() const;
    void setAuthor(const std::string& author);

    // Accessor methods for title
    std::string getTitle() const;
    void setTitle(const std::string& title);

    // Method to convert the object to JSON
    std::string toJson() const;

private:
    std::string _isbn;
    std::string _author;
    std::string _title;
};

#endif // BOOK_H
