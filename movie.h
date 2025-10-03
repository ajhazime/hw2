#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"



class Movie : public Product{
public:
    Movie(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
    virtual std::set<std::string> keywords() const override;
 
    /**
     * Allows for a more detailed search beyond simple keywords
     */
    virtual bool isMatch(std::vector<std::string> &searchTerms) const override;

    /**
     * Returns a string to display the product info for hits of the search
     */
    virtual std::string displayString() const override;

    /**
     * Outputs the product info in the database format
     */
    virtual void dump(std::ostream &os) const override;

protected: 
    std::string genre_;
    std::string rating_;
};


#endif