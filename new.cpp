#include <bits/stdc++.h>
using namespace std;

struct Equipment {
    string name;
    int weight;
    int value;

    Equipment(string n, int w, int v) {
        name = n;
        weight = w;
        value = v;
    }
};

bool cmp(Equipment a, Equipment b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Equipment>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    cout << "Selected Items:\n";

    for (auto item : items) {
        if (capacity == 0) break;

        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
            cout << "- " << item.name << " (100%)\n";
        } else {
            double fraction = (double)capacity / item.weight;
            totalValue += item.value * fraction;
            cout << "- " << item.name << " (" << fixed << setprecision(2) << fraction * 100 << "%)\n";
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int maxCapacity = 35;

    vector<Equipment> items = {
        {"Life Support Module", 14, 95},
        {"High-Res Camera", 12, 80},
        {"Soil Analysis Kit", 9, 70},
        {"Star Tracker", 10, 60},
        {"Communication Array", 6, 45}
    };

    double maxValue = fractionalKnapsack(maxCapacity, items);
    cout << "\nMaximum Scientific Value = " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}
