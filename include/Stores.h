#pragma once
#include <map>
#include <string>
#include <memory>

class Stores {
private:
    std::shared_ptr<std::map<std::string, int>> products;
protected:
    std::shared_ptr<std::map<std::string, int>> getProducts();
public:
    Stores();
    ~Stores();
    void add(const std::string &article, int count);
    void remove(const std::string &article, int count);
};