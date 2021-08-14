//
// Created by david on 22.04.2021.
//

#include "RepoValidator.h"

ValidationException::ValidationException(std::string _message)
:message{_message}
{

}

//std::string ValidationException::getMessage() const {
//    return this->message();
//}

ValidationExceptionInherited::ValidationExceptionInherited(std::string _message) {

}

const char *ValidationExceptionInherited::what() const noexcept {
    return exception::what();
}
