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

    // Some code that uses the person class statically
    Person p(42, "Bob", "Smith");
    Person q(43, "Sally", "Smith");

    p.set_hourly_rate(15.0f);
    p.set_hours_worked(30);
    q.set_hourly_rate(16.75f);
    q.set_hours_worked(42);
    
    // We can also dynamically allocate a person object
    Person* pptr = new Person(44, "Eric", "Davis"); // Like malloc (new is perferred)
                                                // because it works with classes.
    pptr->set_hourly_rate(12.15f);
    pptr->set_hours_worked(23);
    (*pptr).set_hourly_rate(12.35f); // Same as line 49 but sucks just use ->

    delete pptr;                     // Like free, frees up memory pptr points to
    
    pptr = NULL;                     // NULL is just a macro for 0.
    int y = NULL;                    // valid but weird
    pptr = nullptr;                  // A C++ only thing

    pptr = new Person(45, "Kim", "Young");
    // Do things with it
    delete pptr;

    cout << p.get_id() << " " << p.get_first_name() << "\n";

    // p and q were allocated on the STACK (an area of memory). STACK is
    // where "temporary" variables (parameters in functions, p and q here).
    // HEAP memory is where dynamically allocated memory comes from.
    // STACK and HEAP memory are shared. If one gets too big, a STACK OVERFLOW
    // occurs.

    // When p and q go out of SCOPE (where you can access the variable), stack
    // variables go away. The destructor gets called right before this happens.
}
