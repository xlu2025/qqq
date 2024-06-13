#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

class MyString {
    unique_ptr<char[]> str;
public:
    MyString() : str{ make_unique<char[]>(1) } { // Default Constructor
        str[0] = '\0';
    }

    MyString(const char* val) { // Constructor with 1 argument
        if (val == nullptr) {
            str = make_unique<char[]>(1);
            str[0] = '\0';
        }
        else {
            str = make_unique<char[]>(strlen(val) + 1);
            strcpy(str.get(), val);
            cout << "The given string is: " << str.get() << endl;
        }
    }

    MyString(const MyString& source) { // Copy Constructor
        str = make_unique<char[]>(strlen(source.str.get()) + 1);
        strcpy(str.get(), source.str.get());
    }

    MyString(MyString&& source) noexcept = default; // Move Constructor using default

    ~MyString() = default; // Destructor
};

int main(void) {
    cout << "Start!" << endl;

    MyString a;
    MyString b{ "Hello" };
    MyString c{ a };
    MyString d{ MyString{ "World" } };

    cout << "Bye" << endl;
    return 0;
}
