#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <vector>
typedef std::vector<std::string> rule;
typedef std::map<std::string, rule> ruleMap;


using namespace std;

rule tokenize(string s, string del = " ") {
    int start = 0;
    int end = s.find(del);
    rule rules;
    while (end != -1) {
        rules.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    rules.push_back(s.substr(start, end - start));
    return(rules);
}

ruleMap convert_line(string row){
    string toErase = " bags";
    string stopwords [2] = {" bags", " bag"};
    for (string word: stopwords){
        regex pattern(word);
        row = regex_replace(row, pattern, "");
    }
    row = row.substr(0, row.size()-1);

    string delimiter = " contain ";
    string outer_color = row.substr(0, row.find(delimiter));
    string inner = row.substr(row.find(delimiter) + delimiter.length());
    rule inner_str = tokenize(inner, ", ");
    rule inner_colors;
    for (string desc: inner_str)
    {
        string inner = desc.substr(desc.find(" ") + 1);
        inner_colors.push_back(inner);
    }
    if (find(inner_colors.begin(), inner_colors.end(), "other") != inner_colors.end())
    {
        while (!inner_colors.empty()) {
            inner_colors.pop_back();
        }
    }
    ruleMap m;
    m[outer_color] = inner_colors;
    return(m);
}

int has_gold(rule colors, ruleMap rules){
    if (colors.size() == 0){
        return(0);
    }
    else {
        string color = colors[0];
        if (color == "shiny gold"){
            return(1);
        }
        else{
            colors.erase(colors.begin());
            for (string c: rules[color]){
                colors.push_back(c);
            }
            return(has_gold(colors, rules));
        }
    }
}

int main () {
    string line;
    ifstream myfile ("../data/day07.txt");
    if (myfile.is_open()) 
    {
        ruleMap rules;
        while ( getline (myfile, line) ) 
        {
            ruleMap m = convert_line(line);
            rules.insert(m.begin(), m.end());
        }
        cout << "finished reading \n";
        int count = 0;
        for (auto const& [key, val] : rules)
        {
            count += has_gold(rules[key], rules);
        }
        myfile.close();
        cout << count << "\n";
    }
    else cout << "Unable to open file"; 
}
