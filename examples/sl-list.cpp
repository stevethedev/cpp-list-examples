
#include <iostream>

#include <Lists/SinglyLinkedList.hpp>

using SD::Lists::SinglyLinkedList;

int main(int argc, char const *argv[]) {
    SinglyLinkedList<std::string> list;
    list.insert("world").insert("hello", 0);
    std::cout << list.get(0) << " " << list.get(1) << "!" << std::endl;
    std::cout << list.remove(1).get(0) << "!" << std::endl;
    std::cout << "count: " << list.count() << std::endl;
    std::cout << list.set(0, "goodbye!").get(0) << "!" << std::endl;
    return 0;
}
