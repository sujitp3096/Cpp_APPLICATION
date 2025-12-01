#include <iostream>
#include <iomanip>
using namespace std;

// Function to calculate bill based on units
double calculateBill(int units) {
    double bill = 0;

    if (units <= 100) {
        bill = units * 1.50;
    } 
    else if (units <= 300) {
        bill = (100 * 1.50) + ((units - 100) * 2.50);
    } 
    else {
        bill = (100 * 1.50) + (200 * 2.50) + ((units - 300) * 4.00);
    }

    return bill;
}

int main() {
    string name;
    int units;

    cout << "===== ELECTRICITY BILL CALCULATOR =====\n\n";

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Units Consumed: ";
    cin >> units;

    double energyCharge = calculateBill(units);
    double fixedCharge = 50.00;   // fixed cost
    double gst = (energyCharge + fixedCharge) * 0.18; // 18% GST
    double total = energyCharge + fixedCharge + gst;

    cout << "\n=======================================\n";
    cout << "              BILL SUMMARY             \n";
    cout << "=======================================\n";

    cout << left << setw(25) << "Customer Name:" << name << endl;
    cout << left << setw(25) << "Units Consumed:" << units << endl;
    cout << left << setw(25) << "Energy Charge:" << energyCharge << " Rs\n";
    cout << left << setw(25) << "Fixed Charge:" << fixedCharge << " Rs\n";
    cout << left << setw(25) << "GST (18%):" << gst << " Rs\n";
    cout << "---------------------------------------\n";
    cout << left << setw(25) << "Total Bill:" << total << " Rs\n";
    cout << "=======================================\n";

    return 0;
}
