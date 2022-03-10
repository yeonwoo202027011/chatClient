#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int trigger;
void one1()
{
    while (trigger == 0)
    {
        cout << "사랑해\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void two2()
{
    while (trigger == 0)
    {
        this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "나도\n";
        this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main()
{
    trigger = 0;
    cout << "\n--그들의 사랑이 시작된다\n\n";
    thread one(one1);
    thread two(two2);
    while (trigger == 0)
    {
        cin >> trigger;
    }
    one.join();
    two.join();
    cout << "\n--그들의 사랑이 끝났다\n";
}
