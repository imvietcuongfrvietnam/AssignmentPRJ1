#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <map> // Thêm thư viện map để lưu điểm cao nhất

using namespace std;

vector<string> splitString(string &s) {
    vector<string> result;
    stringstream ss(s);
    string word;
    while (getline(ss, word, ' ')) {
        if (!word.empty()) {
            result.push_back(word);
        }
    }
    return result;
}

inline int turnToSec(const string &start) {
    return ((start[0] - '0') * 10 + (start[1] - '0')) * 60 * 60 +
           ((start[3] - '0') * 10 + (start[4] - '0')) * 60 +
           ((start[6] - '0') * 10 + (start[7] - '0'));
}

struct Submit {
    char userID[10];
    char problemID[4];
    char timePoint[9];
    char status[4];
    int point;
};

int main() {
    vector<Submit> submits;
    string input;

    // Đọc các submissions từ đầu vào
    getline(cin, input);
    while (input != "#") {
        vector<string> res = splitString(input);
        Submit v;
        strncpy(v.userID, res[0].c_str(), sizeof(v.userID) - 1);
        v.userID[sizeof(v.userID) - 1] = '\0';
        strncpy(v.problemID, res[1].c_str(), sizeof(v.problemID) - 1);
        v.problemID[sizeof(v.problemID) - 1] = '\0';
        strncpy(v.timePoint, res[2].c_str(), sizeof(v.timePoint) - 1);
        v.timePoint[sizeof(v.timePoint) - 1] = '\0';
        strncpy(v.status, res[3].c_str(), sizeof(v.status) - 1);
        v.status[sizeof(v.status) - 1] = '\0';
        v.point = stoi(res[4]);
        submits.push_back(v);

        getline(cin, input);
    }

    int counterError = 0;
    bool countedErrors = false;
    int cnt;
    string user, start, finish;

    cin >> input;
    while (input != "#") {
        if (input == "?total_number_submissions") {
            cout << submits.size() << endl;
        } else if (input == "?number_error_submision") {
            if (!countedErrors) {
                counterError = 0;
                for (const Submit &v : submits) {
                    if (strcmp(v.status, "ERR") == 0) {
                        counterError++;
                    }
                }
                countedErrors = true;
            }
            cout << counterError << endl;
        } else if (input == "?number_error_submision_of_user") {
            cin >> user;
            cnt = 0;
            for (const Submit &v : submits) {
                if (strcmp(v.userID, user.c_str()) == 0 && strcmp(v.status, "ERR") == 0) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        } else if (input == "?total_point_of_user") {
    cin >> user;
    map<string, int> maxPoints;
    cnt = 0;
    for (const Submit &v : submits) {
        if (strcmp(v.userID, user.c_str()) == 0 && strcmp(v.status, "OK") == 0) {
            string problemID(v.problemID);

            maxPoints[problemID] = max(maxPoints[problemID], v.point);
        }
    }
    // In ra các điểm trong map để kiểm tra
    for (const auto &entry : maxPoints) {
        cnt += entry.second;
    }
    cout << cnt<<endl;
}
 else if (input == "?number_submission_period") {
            cin >> start >> finish;
            int sec_start = turnToSec(start);
            int sec_finish = turnToSec(finish);
            cnt = 0;
            for (const Submit &v : submits) {
                int sec = turnToSec(v.timePoint);
                if (sec >= sec_start && sec <= sec_finish) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        cin >> input;
    }

    return 0;
}
