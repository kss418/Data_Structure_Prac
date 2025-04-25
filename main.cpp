#include <iostream>
#include <cassert>
#include "include/Data_Structure.h"

int main() {
    Priority_Queue pq;
    const int CAP = 5;
    pq.Create(CAP);

    // 1) 빈 큐 동작 확인
    assert(pq.Top() == 0);
    assert(pq.Pop() == 0);
    std::cout << "Empty PQ Top/Pop: OK\n";

    // 2) 요소 삽입
    int elems[] = {3, 5, 1, 4, 2};
    for (int v : elems) {
        pq.Push(v);
        std::cout << "Pushed " << v << "\n";
    }
    // 지금 최대값은 5
    assert(pq.Top() == 5);
    std::cout << "Top after pushes: " << pq.Top() << " (expected 5)\n";

    // 3) 최대 힙 팝 순서 검증
    int expected[] = {5, 4, 3, 2, 1};
    for (int e : expected) {
        int t = pq.Pop();
        std::cout << "Pop() returns " << t << "\n";
        assert(t == e);
    }
    // 이제 빈 상태
    assert(pq.Top() == 0);
    assert(pq.Pop() == 0);

    // 4) 재사용 테스트: 다시 삽입 후 확인
    pq.Push(10);
    pq.Push(20);
    assert(pq.Top() == 20);
    std::cout << "Re-push Top: " << pq.Top() << " (expected 20)\n";
    assert(pq.Pop() == 20);
    assert(pq.Pop() == 10);
    assert(pq.Pop() == 0);

    std::cout << "All Priority_Queue tests passed!\n";
    return 0;
}