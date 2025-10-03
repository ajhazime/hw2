#ifndef FUNCTIONALDATASTORE_H
#define FUNCTIONALDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"

class FunctionalDataStore : public DataStore { 
public:
    FunctionalDataStore();

    ~FunctionalDataStore();
    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product *p) override;

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User *u) override;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product *> search(std::vector<std::string> &terms, int type) override;

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream &ofile) override;

    User* getUserName(const std::string& username);

    void addToCart(std::string username, Product* product);

    void viewCart(std::string username);

    void purchaseCart(std::string username);

protected:

    std::vector<Product*> products_;
    std::map<std::string, std::vector<Product*>> cartList_;
    std::set<User*> users_;
    std::map<std::string, std::set<Product*>> keywordMap_;
private:

};





#endif