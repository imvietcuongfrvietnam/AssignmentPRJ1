#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> splitString(const string &s) {
    vector<string> result;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

inline int turnToSec(const string &time) {
    return ((time[0] - '0') * 10 + (time[1] - '0')) * 3600 +
           ((time[3] - '0') * 10 + (time[4] - '0')) * 60 +
           ((time[6] - '0') * 10 + (time[7] - '0'));
}

struct Submit {
    string userID, problemID, timePoint, status;
    int point;
};

int countErrors(const vector<Submit> &submits) {
    return count_if(submits.begin(), submits.end(), [](const Submit &v) {
        return v.status == "ERR";
    });
}

int countUserErrors(const vector<Submit> &submits, const string &user) {
    return count_if(submits.begin(), submits.end(), [&user](const Submit &v) {
        return v.userID == user && v.status == "ERR";
    });
}

int calculateTotalPoints(const vector<Submit> &submits, const string &user) {
    map<string, int> maxPoints;
    for (const auto &v : submits) {
        if (v.userID == user) {
            maxPoints[v.problemID] = max(maxPoints[v.problemID], v.point);
        }
    }
    int total = 0;
    for (const auto &entry : maxPoints) {
        total += entry.second;
    }
    return total;
}

int countSubmissionsInPeriod(const vector<Submit> &submits, int startSec, int finishSec) {
    return count_if(submits.begin(), submits.end(), [startSec, finishSec](const Submit &v) {
        int sec = turnToSec(v.timePoint);
        return sec >= startSec && sec <= finishSec;
    });
}

int main() {
    vector<Submit> submits;
    string input;

    while (getline(cin, input) && input != "#") {
        auto res = splitString(input);
        submits.push_back({res[0], res[1], res[2], res[3], stoi(res[4])});
    }

    bool countedErrors = false;
    int counterError = 0;
    string user, start, finish;

    while (cin >> input && input != "#") {
        if (input == "?total_number_submissions") {
            cout << submits.size() << endl;
        } else if (input == "?number_error_submision") {
            if (!countedErrors) {
                counterError = countErrors(submits);
                countedErrors = true;
            }
            cout << counterError << endl;
        } else if (input == "?number_error_submision_of_user") {
            cin >> user;
            cout << countUserErrors(submits, user) << endl;
        } else if (input == "?total_point_of_user") {
            cin >> user;
            cout << calculateTotalPoints(submits, user) << endl;
        } else if (input == "?number_submission_period") {
            cin >> start >> finish;
            cout << countSubmissionsInPeriod(submits, turnToSec(start), turnToSec(finish)) << endl;
        }
    }

    return 0;
}
