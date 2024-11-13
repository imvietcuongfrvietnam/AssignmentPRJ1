#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

typedef struct _dataCitizen{
char code[8];
char dob[12];
char fathher_code[8];
char mother_code[8];
char isAlive[2];
char region_code[8];}dataCitizen;
 inline vector<string> splitString(string &s) {
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

typedef struct _Node{
char code[8];
struct _Node *father_code;
struct _Node *father_code;
}Node
int main(){

vector<dataCitizen> database;
string input;
getline(cin, input);
while (input != "*"){
    stringstream ss(input);
    string word;
    dataCitizen data;
    vector<string> dt = splitString(input);
    strcpy(data.code, dt[0]);
    strcpy(data.dob, dt[1]);
    strcpy(data.fathher_code, dt[2]);
    strcpy(data.mother_code, dt[3]);
    strcpy(data.isAlive,dt[4]);
    strcpy(data.region_code, dt[5]);
    database.push_back(data);
    getline(cin, input);
    }

    int cnt = 0;
    getline(cin, input);
    while(input!="***"){
        vector<string> query = splitString(input);
        if(query[0] == "NUMBER_PEOPLE") cout<<database.size()<<endl;
    }
    else if(query[0] == "NUMBER_PEOPLE_BORN_AT"){
        for(dataCitizen &data : database){
            if(strcmp(data.dob,query[1]) == 0) cnt++;
        }
        cout<<cnt<<endl;
        cnt = 0;
    }
    else if(query[0] == " NUMBER_PEOPLE_BORN_BETWEEN"){
        for(dataCitizen &data : database){
            if(data.dob >= query[1] && data.dob <= query[2]) cnt++;
        }
        cout<<cnt<<endl;
        cnt = 0;
    }
    else if(query[0] == "MOST_ALIVE_ANCESTOR"){
        string user = query[1];

    }




}
