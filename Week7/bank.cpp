#include <bits/stdc++.h>

using namespace std;

struct Transaction
{
    string sender_account;
    string receiver_account;
    int amount;
    string transaction_time;
    string atm_id;
};

int total_transactions = 0;
int total_transaction_amount = 0;

vector<Transaction> transactions;
unordered_map<string, int> account_revenue;
set<string> accounts;
unordered_map<string, vector<string>> transaction_graph;
unordered_set<string> visited;
bool has_cycle = false;

void addTransaction(string sender_account, string receiver_account, int amount, string transaction_time, string atm_id)
{
    Transaction new_transaction = {sender_account, receiver_account, amount, transaction_time, atm_id};
    total_transactions++;
    total_transaction_amount += amount;
    transactions.push_back(new_transaction);
    account_revenue[sender_account] += amount;
    accounts.insert(sender_account);
    accounts.insert(receiver_account);
    transaction_graph[sender_account].push_back(receiver_account);
}

void depthFirstSearch(const string &current_account, const string &start_account, int depth, int max_depth)
{
    if (depth == max_depth)
    {
        for (const string &neighbor : transaction_graph[current_account])
        {
            if (neighbor == start_account)
            {
                has_cycle = true;
                return;
            }
        }
        return;
    }

    visited.insert(current_account);

    for (const string &neighbor : transaction_graph[current_account])
    {
        if (visited.find(neighbor) == visited.end())
        {
            depthFirstSearch(neighbor, start_account, depth + 1, max_depth);
            if (has_cycle)
                return;
        }
    }

    visited.erase(current_account);
}

bool checkCycle(const string &account, int max_depth)
{
    visited.clear();
    has_cycle = false;
    depthFirstSearch(account, account, 0, max_depth);
    return has_cycle;
}

void displaySortedAccounts()
{
    for (const string &account : accounts)
    {
        cout << account << " ";
    }
    cout << endl;
}

int convertToSeconds(const string &time)
{
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    int seconds = stoi(time.substr(6, 2));
    return hours * 3600 + minutes * 60 + seconds;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;

    while (getline(cin, line))
    {
        if (line == "#")
            break;
        istringstream iss(line);
        string sender_account, receiver_account, transaction_time, atm_id;
        int amount;
        iss >> sender_account >> receiver_account >> amount >> transaction_time >> atm_id;
        addTransaction(sender_account, receiver_account, amount, transaction_time, atm_id);
    }

    while (getline(cin, line))
    {
        if (line == "#")
            break;

        if (line == "?number_transactions")
        {
            cout << total_transactions << '\n';
        }
        else if (line == "?total_money_transaction")
        {
            cout << total_transaction_amount << '\n';
        }
        else if (line.find("?list_sorted_accounts") != string::npos)
        {
            displaySortedAccounts();
        }
        else if (line.find("?total_money_transaction_from") != string::npos)
        {
            istringstream iss(line);
            string query, account;
            iss >> query >> account;
            cout << account_revenue[account] << '\n';
        }
        else if (line.find("?inspect_cycle") != string::npos)
        {
            istringstream iss(line);
            string query, account;
            int max_depth;
            iss >> query >> account >> max_depth;
            cout << checkCycle(account, max_depth - 1) << '\n';
        }
    }

    return 0;
}
