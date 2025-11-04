#include "list.hpp"
#include <iostream>

int main() {
    sjtu::list<int> myList, otherList;
    int ans = 0;

    try{ myList.pop_back(); } catch (...) { ans++; std::cout << "1. pop_back threw\n"; }
    try{ myList.pop_front(); } catch (...) { ans++; std::cout << "2. pop_front threw\n"; }
    try{ myList.front(); } catch (...) { ans++; std::cout << "3. front threw\n"; }
    try{ myList.back(); } catch (...) { ans++; std::cout << "4. back threw\n"; }
    sjtu::list<int>::iterator it = myList.end(), oit = otherList.end();
    try{ *it; } catch (...) { ans++; std::cout << "5. *it threw\n"; }
    try{ it--; } catch (...) { ans++; std::cout << "6. it-- threw\n"; }
    try{ it++; } catch (...) { ans++; std::cout << "7. it++ threw\n"; }
    try{ myList.erase(it); } catch (...) { ans++; std::cout << "8. erase(it) threw\n"; }
    try{ myList.insert(oit, 0); } catch (...) { ans++; std::cout << "9. insert(oit, 0) threw\n"; }

    std::cout << "Total exceptions: " << ans << " (expected 9)\n";
    return 0;
}

