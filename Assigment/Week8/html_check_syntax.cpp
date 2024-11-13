#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

map<string, string> html_tags;

void initialize() {
    html_tags.insert(std::make_pair("<body>", "</body>"));
    html_tags.insert(std::make_pair("<center>", "</center>"));
    html_tags.insert(std::make_pair("<h1>", "</h1>"));
    html_tags.insert(std::make_pair("<p>", "</p>"));
    html_tags.insert(std::make_pair("<ol>", "</ol>"));
    html_tags.insert(std::make_pair("<li>", "</li>"));
}

bool checkSyntaxHTML(string html) {
    vector<string> result;
    size_t pos = 0;

    // Tìm tất cả các thẻ HTML
    while ((pos = html.find('<', pos)) != string::npos) { //hàm find tìm vị trí thẻ mở
        size_t end_pos = html.find('>', pos); //Tìm vị trí thẻ đóng, ko thấy trả về string::npos
        if (end_pos == string::npos) break;
        result.push_back(html.substr(pos, end_pos - pos + 1)); //push vào vector thẻ mở hoặc thẻ đóng
        pos = end_pos + 1;
    }

    stack<string> s;
    for (string &word : result) {
        if (html_tags.count(word)) { //Tra về 1 nếu word tồn tại là 1 key trong map
            // Nếu là thẻ mở
            s.push(word);
        } else {
            // Nếu là thẻ đóng
            bool found = false;
            for (auto &entry : html_tags) {
                if (word == entry.second) {
                    found = true;
                    if (s.empty() || s.top() != entry.first) {
                        return false;
                    }
                    s.pop();
                    break;
                }
            }
            // Nếu không tìm thấy thẻ đóng hợp lệ
            if (!found) return false;
        }
    }

    return s.empty();
}

int main() {
    string html = R"(
<body>
<center>
 <h1> The Little Boat </h1>
 </center>
 <p> The storm tossed the little
 boat like a cheap sneaker in an
 old washing machine. The three
 drunken fishermen were used to
 such treatment, of course, but
 not the tree salesman, who even as
 a stowaway now felt that he
 had overpaid for the voyage. </p>
 <ol>
 <li> Will the salesman die? </li>
 <li> What color is the boat? </li>
 <li> And what about Naomi? </li>
 </ol>
 </body>)";

    initialize();
    cout << (checkSyntaxHTML(html) ? "Valid HTML syntax" : "Invalid HTML syntax") << endl;

    return 0;
}
