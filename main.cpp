#ifdef MAIN

#include "ABDQ.hpp"
#include "ABQ.hpp"
#include "ABS.hpp"
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include "LLDQ.hpp"
#include "LLQ.hpp"
#include "LLS.hpp"
#include <iostream>

/*
    - LEAVE THE IFDEF GUARDS TO KEEP YOUR MAIN WITHOUT CONFLICTING WITH GRADESCOPE!
    - Test your code in this main and run locally with the RunMain configuration in CLion, or
    through your own command line compilation. Make sure to add flag "-DMAIN" to your compilation so this
    main function can compile.

*/

int main() {
    std::cout << "Creating list 1." << std::endl;
    LinkedList<int> list;
    std::cout << "Total node count: " << list.getCount() << std::endl << std::endl;

    int num = 1;
    std::cout << "Adding element: " << num << std::endl;
    list.addTail(num);
    std::cout << "Printing list: " << std::endl;
    list.printForward();
    std::cout << "Total node count: " << list.getCount() << std::endl << std::endl;

    num++;
    std::cout << "Adding element: " << num << std::endl;
    list.addTail(num);
    std::cout << "Printing list: " << std::endl;
    list.printForward();
    std::cout << "Total node count: " << list.getCount() << std::endl << std::endl;

    num++;
    std::cout << "Adding element: " << num << std::endl;
    list.addTail(num);
    std::cout << "Printing list: " << std::endl;
    list.printForward();
    std::cout << "Total node count: " << list.getCount() << std::endl << std::endl;

    num++;
    std::cout << "Adding element: " << num << std::endl;
    list.addTail(num);
    std::cout << "Printing list: " << std::endl;
    list.printForward();
    std::cout << "Total node count: " << list.getCount() << std::endl << std::endl;

    std::cout << "Clearing list." << std::endl;
    list.clear();
    std::cout << "Printing list: " << std::endl;
    list.printForward();
    std::cout << "Total node count: " << list.getCount() << std::endl << std::endl;

    return 0;
}


#endif