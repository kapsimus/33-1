#include <exception>
#include <memory>
#include "Stores.h"
#include "MyExceptions.h"

Stores::Stores() {
    productsDB = std::make_shared<std::map<std::string, int>>();
}

Stores::~Stores() {
    productsDB.reset();
    baskets.clear();
}

void Stores::addToStore(const std::string &article, const int count) {
    if (count <= 0) {
        throw InvalidCountException();
    }
    auto it = productsDB->find(article);
    if (it == productsDB->end()) {
        productsDB->insert(std::pair<std::string, int>(article, count));
    } else {
        it->second += count;
    }
}

void Stores::removeFromStore(const std::string &article, const int count) {
    if (count <= 0) {
        throw InvalidCountException();
    }
    auto it = productsDB->find(article);
    if (it == productsDB->end()) {
        throw InvalidArticleException();
    } else {
        if (it->second < count) {
            throw InvalidCountException();
        } else {
            it->second -= count;
        }
    }
}

void Stores::addBasket() {
    if (baskets.empty()) {
        basketID = 0;
        baskets.push_back(std::make_shared<std::map<std::string, int>>());
    } else {
        basketID++;
        baskets.push_back(std::make_shared<std::map<std::string, int>>());
    }
}

void Stores::addToBasket(const std::string &article, const int count) {
    if (count <= 0) {
        throw InvalidCountException();
    }
    auto it = productsDB->find(article);
    if (it == productsDB->end()) {
        throw InvalidArticleException();
    } else {
        if (it->second < count) {
            throw InvalidCountException();
        } else {
            if (!baskets.empty()) {
                if (!baskets[basketID]->empty()) {
                    auto itBin = baskets[basketID]->find(article);
                    if (itBin == baskets[basketID]->end()) {
                        baskets[basketID]->insert(std::pair<std::string, int>(article, count));
                    } else {
                        itBin->second += count;
                    }
                    it->second -= count;
                } else {
                    baskets[basketID]->insert(std::pair<std::string, int>(article, count));
                    it->second -= count;
                }
            } else {
                addBasket();
                baskets[basketID]->insert(std::pair<std::string, int>(article, count));
                it->second -= count;
            }
        }
    }
}

void Stores::removeFromBasket(const std::string &article, const int count) {
    if (count <= 0 || baskets.empty()) {
        throw InvalidCountException();
    }
    auto itBin = baskets[basketID]->find(article);
    if (itBin == baskets[basketID]->end()) {
        throw InvalidArticleException();
    } else {
        if (itBin->second < count) {
            throw InvalidCountException();
        } else {
            itBin->second -= count;
            auto it = productsDB->find(article);
            if (it != productsDB->end()) {
                it->second += count;
            }
        }
    }
}