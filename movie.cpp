#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty)
{
    rating_ = rating;
    genre_ = genre;
}

std::set<std::string> Movie::keywords() const{
    std::set<std::string> outputSet;
    addToKeywordsSet(outputSet, genre_);
    addToKeywordsSet(outputSet, name_);
    return outputSet;
}

bool Movie::isMatch(std::vector<std::string> &searchTerms) const
{
    return false;
}

/**
 * Returns a string to display the product info for hits of the search
 */
std::string Movie::displayString() const{
    std::string output = "";

    return name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + "left.";
}

/**
 * Outputs the product info in the database format
 */
void Movie::dump(std::ostream &os) const{
    os << "movie\n" << name_ << "\n"
       << price_ << "\n"
       << qty_ << '\n'
       << genre_ << '\n'
       << rating_ << '\n';
       return;
}