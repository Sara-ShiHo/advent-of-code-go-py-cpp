#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int valid_size(map<string, string> m)
{
    return m.size() == 7;
}

int bounds(int value, int lower, int upper)
{
    return (value >= lower) && (value <= upper);
}

int invalid_int(string s)
{
    char* p;
    strtol(s.c_str(), &p, 10);
    if (*p)
    {
        return 1;
    }
    return 0;
}

int valid_years(map<string, string> m)
{
    if (m.count("iyr") == 0 || m.count("byr") == 0 || m.count("eyr") == 0)
    {
        return 0;
    }
    if (!bounds(stoi(m["byr"]), 1920, 2002) || !bounds(stoi(m["iyr"]), 2010, 2020) || !bounds(stoi(m["eyr"]), 2020, 2030))
    {
        return 0;
    }
    return 1;
}

int valid_height(map<string, string> m)
{
    if (m.count("hgt") == 0)
    {
        return 0;
    }
    string hgt_unit = m["hgt"].substr(m["hgt"].length() - 2);
    string hgt_str = m["hgt"].substr(0, m["hgt"].length() - 2);
    if (invalid_int(hgt_str) || hgt_str == "")
    {
        return 0;
    }
    int hgt = stoi(hgt_str);
    if (hgt_unit == "cm")
    {
        if (!bounds(hgt, 150, 193))
        {
            return 0;
        }
    }
    else if (hgt_unit == "in")
    {
        if (!bounds(hgt, 59, 76))
        {
            return 0;
        }
    }
    else {
        return 0;
    }
    return 1;
}

bool invalid_string(string word, string valid)
{
    for(const char c:word)
    {
        if (valid.find(c) != std::string::npos) {
            return false;
        }
    }
    return true;
}

int valid_hair_eyes(map<string, string> m)
{
    if (m.count("hcl") == 0 || m.count("ecl") == 0)
    {
        return 0;
    }
    string hcl = m["hcl"];
    if ((hcl[0] != '#') || (hcl.length() != 7))
    {
        return 0;
    }
    string hcl_check = hcl.substr(1);
    if (invalid_string(hcl, "0123456789abcdef")){
        return 0;
    }

    string ecl = m["ecl"];
    const string ecls[] {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    if (find(std::begin(ecls), std::end(ecls), ecl) == std::end(ecls))
    {
        return 0;
    }
    return 1;
}

int valid_id(map<string, string> m)
{
    if (m.count("pid") == 0)
    {
        return 0;
    }
    string pid = m["pid"];
    if ((pid.length() != 9) || invalid_string(pid, "0123456789"))
    {
        return 0;
    }
    return 1;
}

map<string, string> parse_map(string contents)
{
    map<string, string> m {};
    int start = 0;
    int end = contents.find(" ");
    while (end != string::npos)
    {
        string subcontents = contents.substr(start, end - start);
        string key = subcontents.substr(0, subcontents.find(":"));
        string value = subcontents.substr(subcontents.find(":") + 1);
        if (key != "cid")
        {
            m[key] = value;
        }
        start = end + 1;
        end = contents.find(" ", start);
    }
    return m;
}

int main () {
    string line;
    map<string, string> m {};
    string contents = "";
    int count1 = 0;
    int count2 = 0;
    ifstream myfile ("../data/day04.txt");
    if (myfile.is_open()) 
    {
        while ( getline (myfile,line) ) 
        {
            if (line == "")
            {
                m = parse_map(contents);
                count1 += valid_size(m);
                count2 += (valid_size(m) * valid_id(m) * valid_years(m) * valid_height(m) * valid_hair_eyes(m));
                m.clear();
                contents = "";
            }
            else
            {
                contents = contents + line + " ";
            }
        }
        // manually run once for the last content
        m = parse_map(contents);
        count1 += valid_size(m);
        count2 += (valid_size(m) * valid_id(m) * valid_years(m) * valid_height(m) * valid_hair_eyes(m));
        myfile.close();
        cout << "Part I: " << count1 << "\n";
        cout << "Part II: " << count2 << "\n";
    }
}
