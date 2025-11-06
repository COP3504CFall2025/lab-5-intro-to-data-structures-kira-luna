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
    // Creating and filling list 1 (testing default constructor, addTail()
    std::cout << "\nCreating & filling list 1." << std::endl;
    LinkedList<int> list1;
    for (int i = 1; i < 6; i ++) {
        list1.addTail(i);
    }
    // Printing list 1 forwards and backwards
    /*
    std::cout << "Printing list 1 forwards: " << std::endl;
    list1.printForward();
    std::cout << "Printing list 1 backwards: " << std::endl;
    list1.printReverse();
    std::cout << "List 1 node count: " << list1.getCount() << std::endl << std::endl;
    */

    // Testing copy constructor
    std::cout << "Creating list 2: copying list 1." << std::endl;
    LinkedList<int> list2(list1);
    std::cout << "List 2 node count: " << list2.getCount() << std::endl << std::endl;
    std::cout << "Printing list 2: " << std::endl;
    list2.printForward();
    std::cout << "List 2 node count: " << list2.getCount() << std::endl << std::endl;

    // Testing addHead(), removeHead(), removeTail()
    /*
    std::cout << "Adding 0, -1 to the front of list 2:" << std::endl;
    list2.addHead(0);
    list2.addHead(-1);
    std::cout << "Printing list 2: " << std::endl;
    list2.printForward();
    std::cout << "Removing the front of list 2:" << std::endl;
    list2.removeHead();
    std::cout << "Printing list 2: " << std::endl;
    list2.printForward();
    std::cout << "Removing the end 2 items of list 2:" << std::endl;
    list2.removeTail();
    list2.removeTail();
    std::cout << "Printing list 2: " << std::endl;
    list2.printForward();
    */

    // TODO: Test: Move constructor, Move assignment, Copy assignment
    // TODO: Test accessors: getCount(), getHead(), getTail()


    // Clearing lists
    /*
    std::cout << "Clearing list 1." << std::endl;
    list1.clear();
    std::cout << "Printing list 1: " << std::endl;
    list1.printForward();
    std::cout << "List 1 node count: " << list1.getCount() << std::endl << std::endl;

    std::cout << "Clearing list 2." << std::endl;
    list2.clear();
    std::cout << "Printing list 2: " << std::endl;
    list2.printForward();
    std::cout << "List 2 node count: " << list2.getCount() << std::endl << std::endl;
    */

    return 0;
    // Testing destructor (end of main() scope)
}


#endif