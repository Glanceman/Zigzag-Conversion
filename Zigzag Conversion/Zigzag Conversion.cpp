// Zigzag Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void print2DVector(vector<vector<char>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

string convert(string s, int numRows) {
    vector<vector<char>> row(numRows);
    string ans = "";
    int pointer = 0;
    int direction = 1;
    //read string zig zac
    for (int i = 0; i < s.size(); i++) {
        row[pointer].push_back((char)s[i]);
        pointer = pointer + direction;
        if (pointer  <= 0 || pointer  >= numRows-1) {
            if (pointer > numRows - 1) {
                pointer = numRows - 1;
            }
            if (pointer < 0) {
                pointer = 0;
            }
            direction = direction * -1;
        }
    }
    //create new string 
    for (int i = 0; i < row.size(); i++) {
        string temp(row[i].begin(), row[i].end() );
        ans.append(temp, 0, temp.size());
    }
    print2DVector(row);
    return ans;
}

int main()
{
    string s = "PAYPALISHIRING";
    string ans = convert("AB", 1);
    cout << ans;
 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
