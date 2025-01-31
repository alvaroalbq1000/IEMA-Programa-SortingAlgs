// Autor: Álvaro Gabriel Alves Albuquerque
// Criado em: 2023
// Apenas para exibição e estudo

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void sleep_sort(int num) {
    std::this_thread::sleep_for(std::chrono::milliseconds(num));
    std::cout << num << " ";
}

void sleep_sort_all(std::vector<int> nums) {
    std::vector<std::thread> threads;
    
    for (int n : nums) {
        threads.push_back(std::thread(sleep_sort, n));
    }
    
    for (std::thread& thread : threads) {
        thread.join();
    }
    
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {5, 3, 8, 1, 2, 9, 4, 7, 6};
    sleep_sort_all(nums);
    
    return 0;
}