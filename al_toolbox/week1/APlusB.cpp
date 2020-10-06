#include <iostream>

int sum_of_two(int a, int b){
    return a + b;
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << sum_of_two(a, b) << std::endl;
    return 0;
}
