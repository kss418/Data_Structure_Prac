#include "include/Data_Structure.h"

int main(){
    Sorted_Linked_List list;
    list.Create();

    list.Insert(3);
    list.Insert(2);
    list.Insert(1);

    std::cout << list.Search(4) << std::endl;
    std::cout << list.Search(3) << std::endl;

    list.Delete(3);
    std::cout << list.Search(3) << std::endl;

    return 0;
}