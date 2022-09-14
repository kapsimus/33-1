#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>

using productPtr = std::shared_ptr<std::map<std::string, int>>;

class Stores {
private:
    productPtr productsDB;
    std::vector<productPtr> baskets;
    int basketID = -1;
public:
    Stores();
    ~Stores();
    void addToStore(const std::string &article, int count);
    void removeFromStore(const std::string &article, int count);
    void addToBasket(const std::string &article, int count);
    void removeFromBasket(const std::string &article, int count);
    void addBasket();
};