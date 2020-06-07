#pragma once
#include <algorithm>
#include <iostream>
#include <string>

const int minCharInPassword = 9;

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage (ErrorCode message);

bool doesPasswordsMatch (const std::string& password, const std::string& furtherPassword);

ErrorCode checkPasswordRules (const std::string& password);

ErrorCode checkPassword (const std::string& password, const std::string& furtherPassword);
