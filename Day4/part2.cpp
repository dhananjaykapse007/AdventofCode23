
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
    vector<int> arr;
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
        arr.push_back(cnt);
    }
    vector<int> res(arr.size(), 1);

    for (int i = 0; i < arr.size(); i++)
    {
        int d = res[i];
        while (d--)
        {
            int temp = arr[i];
            int size;
            if (i + temp <= arr.size() - 1)
            {
                size = i + temp;
            }
            else
                size = arr.size() - 1;
            for (int j = i + 1; j <= size; j++)
            {
                res[j]++;
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        ans += res[i];
    }

    inputFile.close();
    cout << ans << endl;

    return 0;
}

