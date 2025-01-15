// ssuds.cpp

#include <iostream>
#include <string.h> // C String library
#include <string>   // C++ Stirng library
#include <person.h>
using namespace std;

int main()
{
    /*
    int x = 42;
    double z = 3.14;
    float y = 3.14f;

    // C-style Strings
    char name[32] = "Bob Jones";        // C-style String (changable array)
    const char* name2 = "Sally Smith";  // C-Style String (unchangable)
    strcpy(name, "Robert Jones");
    x = strlen(name);                   // 12
    if (strcmp(name, "mmm") < 0)
        printf("name is alphabetically less than mmm\n");

    std::string cpp_name = "Bob Jones"; // Internally, the # of chars is still important
    cpp_name = "Robert Jones";          // No strcpy necessary
    x = cpp_name.length();              // Like strlen
    if (cpp_name < "mmm")
        cout << "cpp_name is alphabetically less than mmm\n";
    name2 = cpp_name.c_str();           // Getting the underlying C char pointer

    // Our goal with data structures will be to make constructs like this ^
    // that simplify the job of the user

    cout << "x=" << x << "abc" << "Hello World!\n";
    */

    // Some code that uses the person class
    Person p(42, "Bob", "Smith");
    Person q(43, "Sally", "Smith");

    p.set_hourly_rate(15.0f);
    p.set_hours_worked(30);
    q.set_hourly_rate(16.75f);
    q.set_hours_worked(42);
    
    cout << "Bob's ID is: " << p.get_id();
}
