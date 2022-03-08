#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std; 

vector <string> word;

int main(){
    string temp;
    while(getline(cin, temp) && temp[0] != '0'){
        int value = 0;
        string s = "";
        for(int i = 0; i < temp.size(); i++){
            if(isalpha(temp[i])){
                while(isalpha(temp[i])){
                    s.insert(s.end(), temp[i]);
                    i++;
                }
                word.push_back(s);
                i--;
                cout << s;
                s = "";
            }
            else if(isalnum(temp[i])){
                value = 0;
                while(isalnum(temp[i])){
                    value = value * 10 + temp[i] - '0';
                    i++;
                }
                s = word[word.size() - value];
                word.erase(word.end() - value);
                word.push_back(s);
                i--;
                cout << s;
                s = "";
            }
            else{
                printf("%c", temp[i]);
            }
        }
        puts("");
    }
    return 0;
}