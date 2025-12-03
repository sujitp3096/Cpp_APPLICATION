#include <iostream>
#include <chrono>
#include <thread>   // for sleep_for()
using namespace std;

void showLight(string color) {
    cout << "Light: " << color << endl;
}

int main() {
    while (true) {   // infinite simulation
        showLight("RED");
        this_thread::sleep_for(chrono::seconds(3));

        showLight("YELLOW");
        this_thread::sleep_for(chrono::seconds(2));

        showLight("GREEN");
        this_thread::sleep_for(chrono::seconds(3));

        cout << "------------------------\n";
    }
    return 0;
}
