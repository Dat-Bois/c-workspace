#include <iostream>

int i = 3;
double d = 12.75;
std::string s = "Boo";

void readAndConvert() {
    int trades;
    int shares;
    double price;
    std::string id;
    std::string symbol;
    std::string description;
    std::string garbage; // empties buffer
    std::cin >> trades;
    std::cin >> symbol;
    std::getline(std::cin, garbage); 
    std::getline(std::cin, description);
    std::cout << symbol << " (" << description << ") " << std::endl;
    for(int i=0;i<trades;i++) {
        std::cin >> id >> price >> shares;
        std::cout << "["+id+"] " << (int) price*shares << std::endl;
    }
}

void reverse(int* first, int* last) {
    // You are given pointers to the first and last element of an array
    int size = last-first;
    for(int i=0;i< (int) size/2;i++) {
        int temp = *(first+i);
        *(first+i) = *(last-i);
        *(last-i) = temp;
    }
}

int main() {
    // std::cout << i << d << s << std::endl;
    // std::cout << s << " " << d << std::endl;
    // //std::cin >> i >> s >> d;
    // std::cin >> i >> s >> d; //does not empty input buffer after reading since it leaves "\n" in buffer
    // std::getline(std::cin, s); //this executes immediately if input buffer is not empty
    // std::cout << i << s << d << std::endl;
    //readAndConvert();
    // int i = 3;
    // double d = 3.5;
    // std::string s = "Boo is perfect";
    // int& j = i;
    // int* k = new int{5};
    // std::cout << *k*2 << std::endl;
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // //std::cout << arr << std::endl;
    // //std::cout << &arr[4] << std::endl;
    // reverse(arr, &arr[9]);
    // for(int i=0;i<10;i++) {
    //     std::cout << arr[i] << std::endl;
    // }

    short l = 12;
    
    return 0;
}
