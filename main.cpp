#include "include/Data_Structure.h"

int main(){
    Sorted_Array array;
    array.Create(20);

    array.Insert(10);
    array.Insert(5);
    array.Insert(8);

    std::cout << *array.Access(2) << std::endl;
    std::cout << *array.Search(5) << std::endl;
    std::cout << array.Search(9) << std::endl;

    array.Delete(8);
    std::cout << array.Search(8) << std::endl;
    std::cout << *array.Access(1) << std::endl;

    return 0;
}