#pragma once
#include <exception>

class InvalidArticleException: std::exception {
public:
    const char* what() const noexcept override;
};

class InvalidCountException: std::exception {
public:
    const char* what() const noexcept override;
};