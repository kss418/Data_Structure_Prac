#include "include/Data_Structure.h"
#include <cassert>

int main(){
    Circular_Queue q;
    const int CAP = 5;
    q.Create(CAP);

    // 1) 빈 큐 확인
    assert(q.Empty());
    assert(!q.Full());
    std::cout << "Empty on init: OK\n";

    // 2) Push 5개 → Full
    for (int i = 1; i <= CAP; ++i) {
        q.Push(i * 10);
        std::cout << "Pushed " << (i * 10) << "\n";
    }
    assert(!q.Empty());
    assert(q.Full());
    std::cout << "Full after " << CAP << " pushes: OK\n";

    // 3) Top(peek) 확인 (가장 먼저 들어간 값)
    int peek = q.Top();
    std::cout << "Top() returns: " << peek << " (expected 10)\n";
    assert(peek == 10);
    // Top()은 pop 하지 않으므로, 다음 Pop()도 10이어야 함
    int first = q.Pop();
    std::cout << "Pop() returns: " << first << " (expected 10)\n";
    assert(first == 10);

    // 4) Pop 나머지
    for (int expect = 20; expect <= 50; expect += 10) {
        int v = q.Pop();
        std::cout << "Pop() returns: " << v << " (expected " << expect << ")\n";
        assert(v == expect);
    }
    assert(q.Empty());
    std::cout << "Empty after pops: OK\n";

    // 5) 원형 래핑 테스트
    for (int i = 1; i <= 3; ++i) q.Push(i);   // queue: [1,2,3]
    for (int i = 0; i < 2; ++i) {             // pop 두 개 → [3]
        std::cout << "Pop() wraps: " << q.Pop() << "\n";
    }
    for (int i = 4; i <= 7; ++i) {            // push 4,5,6,7 → should wrap head
        q.Push(i);
        std::cout << "Pushed (wrapping) " << i << "\n";
    }
    // 남은 요소들을 차례로 꺼내면 3,4,5,6,7
    std::cout << "Final queue contents: ";
    while (!q.Empty()) {
        std::cout << q.Pop() << ' ';
    }
    std::cout << "\n(Expected sequence: 3 4 5 6 7)\n";

    std::cout << "All tests passed!\n";

    return 0;
}