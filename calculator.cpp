#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Currency {
    string name;
    int value;
};

vector<Currency> currencies = {
    {"0.1 agora", 40},
    {"0.5 half", 12},
    {"1 shekel", 3},
    {"5 shekel", 8},
    {"10 shekel", 6}
};

void print_currencies() {
    int num = 1;
    cout << "Select a currency:\n";
    for (const auto& c : currencies) {
        cout << num << ". " << c.name << endl;
        num++;
    }
}

int main() {
    int weight_input, type_corrency;
    while (true) {
        cout << "Enter weight of currency: ";
        
        // check if input is a number
        string input;
        bool is_input_valid = false;
        while (!is_input_valid) {
            cin >> input;
            is_input_valid = std::all_of(input.begin(), input.end(), ::isdigit);
            if (!is_input_valid) {
                cout << "Invalid input. \nEnter weight of currency: " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        weight_input = stoi(input);
        
        print_currencies();
        cout << "Select currency from the list: ";
        
        // check if input is a number within valid range
        while (!(cin >> type_corrency) || type_corrency < 1 || type_corrency > currencies.size()) {
            cout << "Invalid input. \nSelect currency from the list: " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        const auto& currency = currencies[type_corrency - 1];
        double total = static_cast<double>(weight_input) / currency.value;
        cout << "Based on the data given, the weight is equal to " << total << " ₪\n";
        char again;
        cout << "Do you want to calculate again? (y/n) ";
        cin >> again;
        if (again != 'y' && again != 'Y') {
            cout << "See you again...\n";
            break;
        }
    }
    return 0;
}
