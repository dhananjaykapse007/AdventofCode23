
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

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
    string nums;
    string str;
    int cnt = 0;
    while (getline(inputFile, line))
    {
        cnt = 0;
        size_t pos = line.find(':');
        line = line.substr(pos + 2);

        size_t lpos = line.find('|');
        nums = line.substr(lpos + 2);
        str = line.substr(0, lpos - 1);

        stringstream iss(str);
        string token;
        unordered_map<int, int> temp;

        while (getline(iss, token))
        {
            stringstream setStream(token);
            int count;
            while (setStream >> count)
            {
                temp[count]++;
            }
        }

        stringstream jss(nums);
        while (getline(jss, token))
        {
            stringstream setStream(token);
            int count;
            while (setStream >> count)
            {
                if (temp.find(count) != temp.end())
                {
                    cnt++;
                }
            }
        }
        if (cnt == 0)
            continue;
        ans += pow(2, cnt - 1);
    }

    inputFile.close();
    cout << ans << endl;

    return 0;
}

