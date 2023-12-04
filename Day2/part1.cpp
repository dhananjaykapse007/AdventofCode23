
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

map<string, int> mp = {{"red,", 12}, {"blue,", 14}, {"green,", 13}, {"red;", 12}, {"blue;", 14}, {"green;", 13}};

int main()
{
    // Open the file
    ifstream inputFile("data.txt");
    int ans = 0;

    // Check if the file is open
    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    int cnt = 0;
    while (getline(inputFile, line))
    {
        cnt++;
        size_t pos = line.find(':');
        line = line.substr(pos + 1);

        stringstream iss(line);
        string token;
        bool flag = true;

        while (getline(iss, token))
        {
            unordered_map<string, int> temp;

            stringstream setStream(token);
            string color;
            int count;

            while (setStream >> count >> color)
            {
                if (color.back() == ',' || color.back() == ';')
                    color.pop_back();
                temp[color] = max(temp[color], count);
            }
            if (temp["red"] <= 12 && temp["green"] <= 13 && temp["blue"] <= 14)
                ans += cnt;
        }
    }

    inputFile.close();
    cout << ans << endl;

    return 0;
}
