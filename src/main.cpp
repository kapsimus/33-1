#include <iostream>
#include "Stores.h"

int main() {
    Stores store;
    std::string article;
    std::string count;
    do {
        std::cout << "Enter article: ";
        std::cin >> article;
        std::cout << "Enter count: ";
        std::cin >> count;
        try {
            store.add(article, std::stoi(count));
        } catch (std::exception err) {
            std::cerr << "Exception: " << err.what() << std::endl;

        }
    } while (article != "end");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
