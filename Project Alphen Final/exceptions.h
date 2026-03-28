#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class UserException : public exception
{
protected:
    string message;

public:
    UserException(string msg) : message(msg) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class LoginException : public UserException
{
public:
    LoginException() : UserException("Invalid username or password!") {}
};

class UserExistsException : public UserException
{
public:
    UserExistsException() : UserException("User already exists!") {}
};

class FileException : public UserException
{
public:
    FileException() : UserException("File operation failed!") {}
};

#endif