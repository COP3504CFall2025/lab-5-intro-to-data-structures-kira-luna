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
    // TODO: Test ABS.hpp here!
    // Testing Big 5
    std::cout << "Constructing & filling ABS 1." << std::endl;
    ABS<int> arrayBasedStack1(10);
    for (int i = 1; i < 6; i ++) {
        arrayBasedStack1.push(i);
    }
    arrayBasedStack1.getData().printForward();
    std::cout << "Copy constructing ABS 2 from ABS 1." << std::endl;
    ABS<int> arrayBasedStack2 = arrayBasedStack1;
    arrayBasedStack2.getData().printForward();
    std::cout << "Popping 2 elements from ABS 2." << std::endl;
    arrayBasedStack2.pop();
    arrayBasedStack2.pop();
    arrayBasedStack2.getData().printForward();
    std::cout << "Move constructing ABS 3 from ABS 2." << std::endl;
    ABS<int> arrayBasedStack3 = std::move(arrayBasedStack2);
    arrayBasedStack3.getData().printForward();
    std::cout << "Copy assigning ABS 4 from ABS 1." << std::endl;
    ABS<int> arrayBasedStack4(11);
    arrayBasedStack4 = arrayBasedStack1;
    arrayBasedStack4.getData().printForward();



    /*
    // Testing LinkedList class implementation
    // Creating and filling list 1 (testing default constructor, addTail()
    std::cout << "\nCreating & filling list 1." << std::endl;
    LinkedList<int> list1;
    for (int i = 1; i < 6; i ++) {
        list1.addTail(i);
    }
    // Test accessors: getHead(), getTail()
    std::cout << "Head of list 1: " << list1.getHead() << std::endl;
    std::cout << "Tail of list 1: " << list1.getTail() << std::endl;
    // Printing list 1 forwards and backwards
    std::cout << "Printing list 1 forwards: " << std::endl;
    list1.printForward();
    std::cout << "Printing list 1 backwards: " << std::endl;
    list1.printReverse();
    std::cout << "List 1 node count: " << list1.getCount() << std::endl << std::endl;

    // Testing copy constructor
    std::cout << "Creating list 2: copying list 1." << std::endl;
    LinkedList<int> list2(list1);
    std::cout << "List 2 node count: " << list2.getCount() << std::endl << std::endl;
    std::cout << "Printing list 2: " << std::endl;
    list2.printForward();
    std::cout << "List 2 node count: " << list2.getCount() << std::endl << std::endl;

    // Testing addHead(), removeHead(), removeTail()
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

    // Test: Move constructor
    std::cout << "Creating list 3: copying list 2." << std::endl;
    LinkedList<int> list3(std::move(list2));
    std::cout << "List 3 node count: " << list3.getCount() << std::endl << std::endl;
    std::cout << "Printing list 3: " << std::endl;
    list3.printForward();
    std::cout << "List 3 node count: " << list3.getCount() << std::endl << std::endl;
    std::cout << "Printing (now-empty) list 2: " << std::endl;
    list2.printForward();
    std::cout << "List 2 node count: " << list2.getCount() << std::endl << std::endl;

    // Test: Move assignment
    std::cout << "Assigning list 1: moving list 3 contents." << std::endl;
    list1 = std::move(list3);
    std::cout << "Printing list 1: " << std::endl;
    list1.printForward();
    std::cout << "Printing (now-empty) list 3: " << std::endl;
    list3.printForward();
    std::cout << "List 3 node count: " << list3.getCount() << std::endl << std::endl;

    // Test: Copy assignment
    std::cout << "\nAssigning list 1: copying list 2 contents." << std::endl;
    list1 = std::move(list2);
    std::cout << "Printing list 1: " << std::endl;
    list1.printForward();

    // Clearing lists
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