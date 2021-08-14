//
// Created by david on 22.04.2021.
//

#ifndef A45_REPOVALIDATOR_H
#define A45_REPOVALIDATOR_H

#include <string>
#include "../Persistency/TC_Database.h"

class ValidationException {
private:
    std::string message;

public:
    ValidationException(std::string _message);

    std::string getMessage() const;
};

class ValidationExceptionInherited : public std::exception {
private:
    std::string message;

public:
    ValidationExceptionInherited(std::string _message);

    const char *what() const noexcept override;
};

class RepoValidator {
public:
    static void validate(const TC_Database &r);
};


#endif //A45_REPOVALIDATOR_H
