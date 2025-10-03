#include "datastore.h"
#include "functionaldatastore.h"
#include "product.h"
#include "util.h"

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>

FunctionalDataStore::FunctionalDataStore() : DataStore()
{
}

FunctionalDataStore::~FunctionalDataStore()
{
    for (Product *p : products_)
    {
        delete p;
    }
    for (User *u : users_)
    {
        delete u;
    }
}

/**
 * Adds a user to the data store
 */
void FunctionalDataStore::addUser(User *u)
{
    users_.insert(u);
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product *> FunctionalDataStore::search(std::vector<std::string> &terms, int type)
{

    /*
    Create vector to store products that match terms
    get list of products <Product*> products_
    iterate through products calling getName() on product
    */

    std::set<Product *> eligibleProducts;

    bool firstit = true;
    for (const std::string &term : terms)
    {
        std::set<Product *> currSet = keywordMap_[term];
        
        if (firstit)
        {
            eligibleProducts = currSet;
            firstit = false;
            continue;
        }
        if (type == 0)
        {
            eligibleProducts = setIntersection(eligibleProducts, currSet);
        }
        else if (type == 1)
        {
            eligibleProducts = setUnion(eligibleProducts, currSet);
        }
    }
    std::vector<Product *> result;
    for (Product *p : eligibleProducts)
    {
        result.push_back(p);
    }
    return result;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void FunctionalDataStore::dump(std::ostream &ofile)
{
    ofile << "<products>\n";

    for (Product *p : products_)
    {
        p->dump(ofile);
    }
    ofile << "</products>\n";
    ofile << "<users>\n";
    for (User *u : users_)
    {
        u->dump(ofile);
    }
    ofile << "</users>\n";
    return;
}

User *FunctionalDataStore::getUserName(const std::string &username)
{
    for (User *u : users_)
    {
        if (u->getName() == username)
        {
            return u;
        }
    }
    return nullptr;
}

void FunctionalDataStore::addToCart(std::string username, Product *product)
{
    // add product to the users cart
    if (getUserName(username) == nullptr)
    {
        return;
    }

    cartList_[username].push_back(product);
}

void FunctionalDataStore::viewCart(std::string username)
{
    if (getUserName(username) == nullptr)
    {
        std::cout << "Invalid Username Try again." << std::endl;
        return;
    }
    std::vector<Product *> &cart = cartList_[username];

    if (cart.empty())
    {
        std::cout << "Cart is Empty" << std::endl;
        return;
    }

    for (size_t i = 0; i < cart.size(); ++i)
    {
        std::cout << "Item " << i + 1 << '\n';
        std::cout << cart[i]->displayString() << std::endl;
    }

    return;
}

void FunctionalDataStore::purchaseCart(std::string username)
{

    std::vector<Product *> &cart = cartList_[username];

    User *user = getUserName(username);
    if (user == nullptr)
    {
        std::cout << "Invalid username." << std::endl;
        return;
    }

    if (cart.empty())
    {
        std::cout << "Cart empty" << std::endl;
        return;
    }

    std::vector<Product *> newCart;
    for (Product *p : cart)
    {
        if (p->getQty() > 0 && user->getBalance() >= p->getPrice())
        {
            user->deductAmount(p->getPrice());
            p->subtractQty(1);
        }
        else
        {
            newCart.push_back(p);
        }
    }
    cartList_[username] = newCart;
    return;
}

void FunctionalDataStore::addProduct(Product *p)
{
    products_.push_back(p);
    std::set<std::string> keywords = p->keywords();
    for (const std::string &keyword : keywords)
    {
        keywordMap_[convToLower(keyword)].insert(p);
    }
    return;
}
