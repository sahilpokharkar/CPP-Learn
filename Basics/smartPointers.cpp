#include <iostream>
#include <fstream>
#include <streambuf>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) {
        std::cout << "MyClass constructor: " << value << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor: " << value << std::endl;
    }
    void display() {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

void uniquePtrDemo() {
    std::cout << "\n--- unique_ptr Demo ---" << std::endl;
    std::unique_ptr<MyClass> uptr = std::make_unique<MyClass>(10);
    uptr->display();

    // Transferring ownership
    std::unique_ptr<MyClass> uptr2 = std::move(uptr);
    if (!uptr) {
        std::cout << "uptr is now nullptr after move." << std::endl;
    }
    uptr2->display();
}

void sharedPtrDemo() {
    std::cout << "\n--- shared_ptr Demo ---" << std::endl;
    std::shared_ptr<MyClass> sptr1 = std::make_shared<MyClass>(20);
    std::shared_ptr<MyClass> sptr2 = sptr1;  // Reference count increases

    std::cout << "sptr1 use_count: " << sptr1.use_count() << std::endl;
    std::cout << "sptr2 use_count: " << sptr2.use_count() << std::endl;

    sptr1->display();
    sptr2->display();
}

void weakPtrDemo() {
    std::cout << "\n--- weak_ptr Demo ---" << std::endl;
    std::shared_ptr<MyClass> sptr = std::make_shared<MyClass>(30);
    std::weak_ptr<MyClass> wptr = sptr;  // Doesn't increase use_count

    std::cout << "sptr use_count: " << sptr.use_count() << std::endl;
    std::cout << "wptr expired? " << (wptr.expired() ? "Yes" : "No") << std::endl;

    if (std::shared_ptr<MyClass> temp = wptr.lock()) {
        temp->display();
    }

    sptr.reset(); // Destroy the object

    std::cout << "After resetting sptr:" << std::endl;
    std::cout << "wptr expired? " << (wptr.expired() ? "Yes" : "No") << std::endl;
}

void smartPointerFunction() {
    uniquePtrDemo();
    sharedPtrDemo();
    weakPtrDemo();
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
    smartPointerFunction();

    // Restore the original buffers (optional)
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    return 0;
}