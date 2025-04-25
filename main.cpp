#include <iostream>
#include <cassert>
#include "include/Data_Structure.h"

int main() {
    Binary_Search_Tree bst;
    bst.Create();

    // 1) 빈 트리 검색
    assert(bst.Search(10) == nullptr);

    // 2) 노드 삽입
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) {
        bst.Insert(v);
    }

    // 삽입된 값들 검색 확인
    for (int v : values) {
        assert(bst.Search(v) != nullptr);
    }
    // 없는 값 검색 시 nullptr
    assert(bst.Search(25) == nullptr);

    // 3) 리프 노드 삭제 (20)
    bst.Delete(20);
    assert(bst.Search(20) == nullptr);
    // 나머지 값들은 여전히 존재
    for (int v : {30, 40, 50, 60, 70, 80}) {
        assert(bst.Search(v) != nullptr);
    }

    // 4) 자식 하나인 노드 삭제 (30)
    bst.Delete(30);
    assert(bst.Search(30) == nullptr);
    for (int v : {40, 50, 60, 70, 80}) {
        assert(bst.Search(v) != nullptr);
    }

    // 5) 자식 둘인 노드 삭제 (50, 루트)
    bst.Delete(50);
    assert(bst.Search(50) == nullptr);
    for (int v : {40, 60, 70, 80}) {
        assert(bst.Search(v) != nullptr);
    }

    // 6) 존재하지 않는 값 삭제
    bst.Delete(100);
    // 트리 구조에 영향 없어야 함
    for (int v : {40, 60, 70, 80}) {
        assert(bst.Search(v) != nullptr);
    }

    std::cout << "All BST tests passed!" << std::endl;
    return 0;
}