#include <iostream>
#include "MyDeck.h"

int main() {
    MyDeck<int> deck;
    // 1
    deck.push_back(1);
    // 1 2
    deck.push_back(2);
    // 1 2 3
    deck.push_back(3);
    // 1 2 3 4
    deck.push_back(4);
    // 0 1 2 3 4
    deck.push_front(0);
    // -1 0 1 2 3 4
    deck.push_front(-1);

    // 6, [-1, 0, 1, 2, 3, 4]
    std::cout << deck.size() << ", " << deck << std::endl;

    // 4 -1 3 2 0 1
    std::cout << deck.pop_back() << " " << deck.pop_front() << " " << deck.pop_back()
              << " " << deck.pop_back() << " " << deck.pop_front() << " " << deck.pop_back() << std::endl;

    // 0, []
    std::cout << deck.size() << ", " << deck << std::endl;

    try {
        deck.pop_back();
    } catch (std::out_of_range &exception) {
        std::cout << "Cannot pop empty back [correct]" << std::endl;
    }
    try {
        deck.pop_front();
    } catch (std::out_of_range &exception) {
        std::cout << "Cannot pop empty front [correct]" << std::endl;
    }
    return 0;
}
