#pragma once
#include <map>
#include <string>
#include "Stores.h"

class Bin: Stores {
    std::map<std::string, int> products;
public:
    void add(const std::string &article, const int count);
    void remove(const std::string &article, const int count);
};