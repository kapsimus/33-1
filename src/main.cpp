#include <iostream>
#include "Stores.h"
#include "MyExceptions.h"

int main() {
    Stores store;
    std::string article;
    int count;
    do {
        std::cout << "Enter article: ";
        std::cin >> article;
        if (article != "end") {
            std::cout << "Enter count: ";
            std::cin >> count;
            if (std::cin.fail()) {
                count = 0;
                std::cin.clear();
            }
            try {
                store.addToStore(article, count);
            } catch (const InvalidArticleException &x) {
                std::cerr << "Exception: " << x.what() << std::endl;
            } catch (const InvalidCountException &x) {
                std::cerr << "Exception: " << x.what() << std::endl;
            }
        }
    } while (article != "end");

    store.addBasket();
    do {
        std::string op;
        std::cout << "Enter operation (add/remove/end): ";
        std::cin >> op;
        if (op != "end") {
            std::cout << "Enter article: ";
            std::cin >> article;
            std::cout << "Enter count: ";
            std::cin >> count;
            if (std::cin.fail()) {
                count = 0;
                std::cin.clear();
            }
            try {
                if (op == "add") {
                    store.addToBasket(article, count);
                } else if (op == "remove") {
                    store.removeFromBasket(article, count);
                }
            } catch (const InvalidArticleException &x) {
                std::cerr << "Exception: " << x.what() << std::endl;
            } catch (const InvalidCountException &x) {
                std::cerr << "Exception: " << x.what() << std::endl;
            }
        }
    } while (article != "end");

    return 0;
}
