#include <iostream>
#include <algorithm>
using namespace std;

struct Object {
    string name;
    double weight, profit, ratio;
};

// Comparator for sorting by P/W ratio descending
bool compare(Object a, Object b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cout << "Enter number of objects: ";
    cin >> n;
    
    Object objects[n];
    
    // Input data
    for (int i = 0; i < n; i++) {
        cout << "Enter Name, Weight and Profit for object " << i+1 << ": ";
        cin >> objects[i].name >> objects[i].weight >> objects[i].profit;
        objects[i].ratio = objects[i].profit / objects[i].weight;
    }

    // Sort by P/W ratio descending
    sort(objects, objects + n, compare);

    // Output sorted list
    cout << "\nSorted Objects:\n";
    cout << "Name\tWeight\tProfit\tP/W\n";
    for (int i = 0; i < n; i++) {
        cout << objects[i].name << "\t" 
             << objects[i].weight << "\t" 
             << objects[i].profit << "\t" 
             << objects[i].ratio << endl;
    }

    return 0;
}