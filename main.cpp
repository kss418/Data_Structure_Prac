#include "include/Data_Structure.h"

int main(){
    Stack stack;
    stack.Create(3);

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;

    std::cout << stack.Empty();

    return 0;
}