#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Function to count descendants recursively
int countDescendants(const string& name, const map<string, vector<string>>& tree) {
    // If the person has no children, return 0
    if (tree.find(name) == tree.end()) {
        return 0;
    }

    int total = 0;
    // Count this child's descendants recursively
    for (const string& child : tree.at(name)) {
        total += 1 + countDescendants(child, tree); // Count this child and all their descendants
    }
    return total;
}

// Function to count generations recursively
int countGenerations(const string& name, const map<string, vector<string>>& tree) {
    // If the person has no children, return 0
    if (tree.find(name) == tree.end()) {
        return 0;
    }

    int maxGen = 0;
    // Find the maximum generations from the children
    for (const string& child : tree.at(name)) {
        maxGen = max(maxGen, countGenerations(child, tree)); // Update max generations
    }
    return maxGen + 1; // Add one for the current generation
}

int main() {
    map<string, vector<string>> tree; // Family tree
    string child, parent;

    // Input phase for the family tree
    while (true) {
        cin >> child;
        if (child == "***") break; // End input

        cin >> parent;
        tree[parent].push_back(child); // Build the tree
    }

    // Query phase
    string command, name;
    while (true) {
        cin >> command >> name;
        if (command == "***") break; // End input for queries

        if (command == "descendants") {
            int descendantsCount = countDescendants(name, tree);
            cout << descendantsCount << endl; // Output descendants count
        } else if (command == "generation") {
            int generationsCount = countGenerations(name, tree);
            cout << generationsCount << endl; // Output generations count
        }
    }

    return 0;
}
