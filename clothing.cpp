#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size) : Product(category, name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

bool Clothing::isMatch(std::vector<std::string> &searchTerms) const
{
    return false;
}

std::set<std::string> Clothing::keywords() const{

    std::set<std::string> outputSet;
    addToKeywordsSet(outputSet, brand_);
    addToKeywordsSet(outputSet, name_);

    return outputSet;
}
std::string Clothing::displayString() const{

    return name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + "left.";
}

void Clothing::dump(std::ostream &os) const
{
    os << "clothing\n" << name_ << "\n"
       << price_ << "\n"
       << qty_ << "\n"
       << size_ << "\n"
       << brand_ << "\n";
}

std::string Clothing::getBrand() const
{
    return brand_;
}

std::string Clothing::getSize() const
{
    return size_;
}

