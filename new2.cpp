#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Object {
    string name;
    int weight;
    int profit;
    double ratio; // Profit-to-Weight ratio

    void calculateRatio() {
        ratio = (double)profit / weight;
    }
};

// Comparator for sorting by ratio descending
bool cmp(Object a, Object b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    //cout << "Enter number of objects: ";
    cin >> n;

    vector<Object> objects(n);

    //cout << "Enter Name, Weight, and Profit for each object:\n";
    for (int i = 0; i < n; ++i) {
        cin >> objects[i].name >> objects[i].weight >> objects[i].profit;
        objects[i].calculateRatio();
    }

    sort(objects.begin(), objects.end(), cmp);

    cout << "\nSorted List based on Profit/Weight Ratio:\n";
    cout << left << setw(10) << "Name"
         << setw(10) << "Weight"
         << setw(10) << "Profit"
         << setw(10) << "P/W" << endl;

    for (auto obj : objects) {
        cout << left << setw(10) << obj.name
             << setw(10) << obj.weight
             << setw(10) << obj.profit
             << fixed << setprecision(2) << obj.ratio << endl;
    }

    return 0;
}
