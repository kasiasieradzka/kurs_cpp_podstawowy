#include "validation.hpp"
#include <cstdlib>
#include <iostream>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage (ErrorCode message) {
    switch (message)
    {
        case ErrorCode::Ok:
        {
            return "Poprawnie wprowadzono nowe haslo \n";
        }
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        {
            return "Haslo musi zawierac co najmniej 9 znakow";
        }
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
        {
            return "Haslo musi zawierac co najmniej jedna cyfre";
        }   
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        {
            return "Haslo musi zawierac co najmniej jeden znak specjalny";
        }
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        {
            return "Haslo musi zawierac co najmniej jedna duza litere";
        }
        case ErrorCode::PasswordsDoesNotMatch:
        {
            return "Wprowadzone hasla nie zgadzaja sie";
        }
        default:
        {
            return "Niezdefiniowany blad";
        }
    }
}

bool doesPasswordsMatch (const std::string& password, const std::string& furtherPassword) {
    return password == furtherPassword;
}

ErrorCode checkPasswordRules (const std::string& password) {
    if (password.length() < 9)
    {
        getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters);
    }
    
    for (size_t i = 0; i < password.length(); i++)
    {
        char temporary;
        password[i] = temporary;

        if (temporary >= 48 && temporary <= 57) {
            return getErrorMessage(ErrorCode::Ok); 
        }
        else {
            getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber);
        }

    }
    
    for (size_t i = 0; i < password.length(); i++)
    {
        char temporary;
        password[i] = temporary;

        if ((temporary >= 32 && temporary <= 47) || (temporary >= 58 && temporary <= 64) || (temporary >= 91 && temporary <= 96) || (temporary >= 123 && temporary <= 126)) {
            return getErrorMessage(ErrorCode::Ok);
        }
        else {
            return getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
        }

    }
    
    for (size_t i = 0; i < password.length(); i++)
    {
        char temporary;
        password[i] = temporary;

        if (temporary >= 65 && temporary <= 90) {
            return getErrorMessage(ErrorCode::Ok);
        }
        else {
            return getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);
        }
    }
}

ErrorCode checkPassword (const std::string& password, const std::string& furtherPassword) {
    if (doesPasswordsMatch(password, furtherPassword)) {
        return checkPasswordRules(password);
    }
}
