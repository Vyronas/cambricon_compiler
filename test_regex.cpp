#include <regex>
#include <iostream>
#include <string>

using namespace std;
int main(){
    string s = "  %input = WeightVar float<8 x 28 x 28 x 1> mutable // size: 25088 // Users: @in 62, @in 1";
    // string s = "  Hello, everyone! This is: COSC-1436, SP18";


    // const std::string s = "Hello, everyone! This is: COSC-1436, SP18";

    std::regex words_regex("[^\\s,=:%;!\<\>?x]+");
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        std::cout << (*i).str() << '\n';


}
