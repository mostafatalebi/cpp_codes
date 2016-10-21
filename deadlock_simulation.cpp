#include <iostream>
#include <thread>
#include <mutex>

class SampleObject
{
public:

    std::mutex _mutex;

    void print()
    {
        std::cout << "ID: #" << std::this_thread::get_id() << std::endl;
    }
};

void set_operation(SampleObject &S1, SampleObject &S2)
{
    std::cout << "Try to lock..." << std::endl;
    std::unique_lock<std::mutex> l1(S1._mutex);
    std::cout << "Locked successfully." << std::endl;
    S1.print();
    std::unique_lock<std::mutex> l2(S2._mutex);
    S2.print();
}
void set_operation2(SampleObject &S1, SampleObject &S2)
{
    std::cout << "Try to lock..." << std::endl;
    std::unique_lock<std::mutex> l2(S2._mutex);
    std::cout << "Locked successfully." << std::endl;
    S1.print();
    std::unique_lock<std::mutex> l1(S1._mutex);

    S2.print();
}

int main() {

    SampleObject S11;
    SampleObject S22;
    std::thread th(set_operation, std::ref(S11), std::ref(S22));
    std::thread th2(set_operation2, std::ref(S11), std::ref(S22));
    std::thread th3(set_operation, std::ref(S11), std::ref(S22));
    std::thread th4(set_operation2, std::ref(S11), std::ref(S22));
    std::thread th5(set_operation, std::ref(S11), std::ref(S22));
    std::thread th6(set_operation2, std::ref(S11), std::ref(S22));
    std::thread th7(set_operation, std::ref(S11), std::ref(S22));
    std::thread th8(set_operation2, std::ref(S11), std::ref(S22));
//    std::thread th2(set_operation, std::ref(S33), std::ref(S44));
    th.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    return 0;
}
