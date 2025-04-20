#include <iostream>
#include <fstream>
#include <streambuf>

// Function for pointer as function argument
void increment(int* ptr) {
    (*ptr)++;
}

// Function returning pointer
int* getMax(int* a, int* b) {
    return (*a > *b) ? a : b;
}

void pointerFunction() {
    // 1. Basic Pointer Declaration
    int x = 10;
    int* p = &x;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x (&x): " << &x << std::endl;
    std::cout << "Pointer p pointing to x: " << p << std::endl;
    std::cout << "Value at pointer p (*p): " << *p << std::endl;
    

    // 2. Null Pointer
    int* np = nullptr;
    std::cout << "\nNull pointer: " << np << std::endl;

    // 3. Pointer Arithmetic
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    std::cout << "\nPointer Arithmetic on array:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "*(ptr + " << i << ") = " << *(ptr + i) << std::endl;
    }

    // 4. Array of Pointers
    const char* fruits[] = {"Apple", "Banana", "Cherry"};
    std::cout << "\nArray of pointers to strings:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << fruits[i] << std::endl;
    }

    // 5. Pointer to Pointer
    int y = 20;
    int* py = &y;
    int** ppy = &py;
    std::cout << "\nPointer to pointer:" << std::endl;
    std::cout << "Value of y: " << y << std::endl;
    std::cout << "Value at *py: " << *py << std::endl;
    std::cout << "Value at **ppy: " << **ppy << std::endl;

    // 6. Function with Pointer Argument
    int z = 5;
    std::cout << "\nBefore increment: " << z << std::endl;
    increment(&z);
    std::cout << "After increment using pointer: " << z << std::endl;

    // 7. Function Returning Pointer
    int a = 100, b = 200;
    int* maxPtr = getMax(&a, &b);
    std::cout << "\nMax value using pointer return: " << *maxPtr << std::endl;

    // 8. Dynamic Memory Allocation with new and delete
    int* dyn = new int;
    *dyn = 50;
    std::cout << "\nDynamically allocated int: " << *dyn << std::endl;
    delete dyn;

    // 9. Dynamic Array Allocation
    int* darr = new int[3]{10, 20, 30};
    std::cout << "\nDynamic array:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << darr[i] << " ";
    }
    std::cout << std::endl;
    delete[] darr;

    // 10. Void Pointer
    void* vptr;
    int vi = 99;
    vptr = &vi;
    std::cout << "\nVoid pointer pointing to int: " << *(static_cast<int*>(vptr)) << std::endl;

}


int main()
{
    // Redirect standard input to read from input.txt
    std::ifstream inFile("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(inFile.rdbuf());

    // Redirect standard output to write to output.txt
    std::ofstream outFile("output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(outFile.rdbuf());

    // Your Code Goes Here
    pointerFunction();

    // Restore the original buffers (optional)
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    return 0;
}