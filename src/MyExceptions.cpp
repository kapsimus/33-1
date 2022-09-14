#include "MyExceptions.h"

const char *InvalidArticleException::what() const noexcept {
    return "InvalidArticleException";
}

const char *InvalidCountException::what() const noexcept {
    return "InvalidCountException";
}