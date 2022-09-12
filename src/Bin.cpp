#include "Bin.h"

void Bin::add(const std::string &article, const int count) {
    if (count <= 0) {
        return;
    }
    std::map<std::string, int>::iterator it = getProducts()->find(article);
    if (it == getProducts()->end()) {
        throw ("Invalid article!");
    } else {
        if (it->second < count) {
            throw ("Invalid count!");
        } else {
            std::map<std::string, int>::iterator itBin = products.find(article);
            if (itBin == products.end()) {
                products.insert(std::pair<std::string, int>(article, count));
            } else {
                itBin->second += count;
            }
            it->second -= count;
        }
    }
}

void Bin::remove(const std::string &article, const int count) {
    if (count <= 0) {
        return;
    }
    std::map<std::string, int>::iterator itBin = products.find(article);
    if (itBin == products.end()) {
        throw("Invalid article!");
    } else {
        if (itBin->second < count) {
            throw ("Invalid count!");
        } else {
            itBin->second -= count;
        }
    }
}