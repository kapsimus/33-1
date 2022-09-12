#include <exception>
#include <memory>
#include "Stores.h"

Stores::Stores() {
    products = std::make_shared<std::map<std::string, int>>();
}

Stores::~Stores() {
    products.reset();
}

std::shared_ptr<std::map<std::string, int>> Stores::getProducts()  {
    return products;
}

void Stores::add(const std::string &article, const int count) {
    if (count <= 0) {
        throw ("Invalid count!");
    }
    std::map<std::string, int>::iterator it = products->find(article);
    if (it == products->end()) {
        products->insert(std::pair<std::string, int>(article, count));
    } else {
        it->second += count;
    }
}

void Stores::remove(const std::string &article, const int count) {
    if (count <= 0) {
        return;
    }
    std::map<std::string, int>::iterator it = products->find(article);
    if (it == products->end()) {
        throw("Invalid article!");
    } else {
        if (it->second < count) {
            throw ("Invalid count!");
        } else {
            it->second -= count;
        }
    }
}