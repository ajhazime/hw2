#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing : public Product {
public: 

    Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size);

    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    bool isMatch(std::vector<std::string> &searchTerms) const override;
    void dump(std::ostream &os) const override;
    std::string getBrand() const;
    std::string getSize() const;

protected:
    std::string size_;
    std::string brand_;
};


#endif