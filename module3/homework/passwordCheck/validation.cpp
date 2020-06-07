#include "validation.hpp"

std::string getErrorMessage (const ErrorCode message) {
    switch (message)
    {
        case ErrorCode::Ok:
        {
            return "OK";
        }
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        {
            return "Password needs at least nine characters";
        }
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
        {
            return "Password needs at least one number";
        }   
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        {
            return "Password needs at least one special character";
        }
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        {
            return "Password needs at least one uppercase letter";
        }
        case ErrorCode::PasswordsDoesNotMatch:
        {
            return "Passwords don't match";
        }
        default:
        {
            return "Unknow error code";
        }
    }
}

bool doesPasswordsMatch (const std::string& password, const std::string& furtherPassword) {
    return password == furtherPassword;
}

ErrorCode checkPasswordRules (const std::string& password) {
    if (password.length() < minCharInPassword) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    
    if (std::none_of(password.begin(), password.end(), [](unsigned char letter) { return std::isdigit(letter); })) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
        
    if (std::none_of(password.begin(), password.end(), [](unsigned char letter) { return std::ispunct(letter); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
        
    if (std::none_of(password.begin(), password.end(), [](unsigned char letter) { return std::isupper(letter); })) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword (const std::string& password, const std::string& furtherPassword) {
    if (doesPasswordsMatch(password, furtherPassword)) {
        return checkPasswordRules(password);
    }
    else {
        return ErrorCode::PasswordsDoesNotMatch;
    }
}
