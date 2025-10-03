#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) : Product(category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
}

bool Book::isMatch(std::vector<std::string> &searchTerms) const
{
    return false;
}

/*
 * Returns the appropriate keywords that this product should be associated with
 */
std::set<std::string> Book::keywords() const
{
    std::set<std::string> outputSet;
    addToKeywordsSet(outputSet, author_);
    outputSet.insert(convToLower(isbn_));
    addToKeywordsSet(outputSet, name_);
    
    return outputSet; 
}


/*
 * Returns a string to display the product info for hits of the search
 */
std::string Book::displayString() const
{
    return name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + "left.";
}

/*
 * Outputs the product info in the database format
 */
void Book::dump(std::ostream &os) const{
    os << "book\n" << name_ << "\n" << price_ << "\n" << qty_ << '\n' << isbn_ << '\n' << author_ << '\n';
}

std::string Book::getISBN() const {
    return isbn_;
} 
std::string Book::getAuthor() const
{
    return author_;
}