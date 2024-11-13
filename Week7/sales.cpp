#include <bits/stdc++.h>
using namespace std;

struct Transaction {
    string customerId;
    string productId;
    int amount;
    string shopId;
    int timeInSeconds;
};

vector<Transaction> transactions;
unordered_map<string, int> shopSales;
unordered_map<string, unordered_map<string, int>> customerShopSales;
vector<int> cumulativeSales(86401, 0);

int totalOrders = 0;
int totalRevenue = 0;

int timeToSeconds(const string &time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    int ss = stoi(time.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

void recordTransaction(string customerId, string productId, int amount, string shopId, string timePoint) {
    int timeInSeconds = timeToSeconds(timePoint);
    Transaction transaction = {customerId, productId, amount, shopId, timeInSeconds};
    
    totalRevenue += amount;
    shopSales[shopId] += amount;
    customerShopSales[customerId][shopId] += amount;
    transactions.push_back(transaction);
    totalOrders++;

    cumulativeSales[timeInSeconds] += amount;
}

void buildCumulativeSales() {
    for (int i = 1; i <= 86400; ++i) {
        cumulativeSales[i] += cumulativeSales[i - 1];
    }
}

int getSalesInPeriod(int fromSeconds, int toSeconds) {
    if (fromSeconds > 86400) fromSeconds = 86400;
    if (toSeconds > 86400) toSeconds = 86400;
    return cumulativeSales[toSeconds] - (fromSeconds > 0 ? cumulativeSales[fromSeconds - 1] : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    
    while (getline(cin, line)) {
        if (line == "#") break;
        istringstream iss(line);
        string customerId, productId, shopId, timePoint;
        int amount;
        iss >> customerId >> productId >> amount >> shopId >> timePoint;
        recordTransaction(customerId, productId, amount, shopId, timePoint);
    }

    buildCumulativeSales();

    while (getline(cin, line)) {
        if (line == "#") break;

        if (line == "?total_number_orders") {
            cout << totalOrders << '\n';
        } else if (line == "?total_revenue") {
            cout << totalRevenue << '\n';
        } else if (line.find("?revenue_of_shop") != string::npos) {
            istringstream iss(line);
            string query, shopId;
            iss >> query >> shopId;
            cout << shopSales[shopId] << '\n';
        } else if (line.find("?total_consume_of_customer_shop") != string::npos) {
            istringstream iss(line);
            string query, customerId, shopId;
            iss >> query >> customerId >> shopId;
            cout << customerShopSales[customerId][shopId] << '\n';
        } else if (line.find("?total_revenue_in_period") != string::npos) {
            istringstream iss(line);
            string query, fromTime, toTime;
            iss >> query >> fromTime >> toTime;
            int fromSeconds = timeToSeconds(fromTime);
            int toSeconds = timeToSeconds(toTime);
            cout << getSalesInPeriod(fromSeconds, toSeconds) << '\n';
        }
    }

    return 0;
}
