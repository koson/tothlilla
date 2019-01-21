/*
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

    std::vector<int> ages = {24, 32, 22, 55, 105, 68};
    ages.push_back(48);
    std::cout << ages[2] << std::endl;    // 2? Who is 2?


    std::map<std::string, int> namesToAges;    // Both the key and the value types are declared

    namesToAges["Peti"] = 22;
    namesToAges["Marci"] = 48;

    std::cout << namesToAges["Peti"] << std::endl;    // prints 22 as expected

    for (std::map<std::string, int>::iterator it = namesToAges.begin(); it != namesToAges.end(); ++it) {
        std::cout << it->first << " is " << it->second << " years old" << std::endl;
    }
    return 0;
}
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(int argc, char* args[])
{
    std::string out = "";
    std::vector<int> notSoCrypticMessage = {1, 12, 1, 2, 11, 1, 7, 11, 1, 49, 1, 3, 11, 1, 50, 11};

    std::map<int, std::string> map;

    map[7] = "run around and desert you";
    map[50] = "tell a lie and hurt you ";
    map[49] = "make you cry, ";
    map[2] = "let you down";
    map[12] = "give you up, ";
    map[1] = "Never gonna ";
    map[11] = "\n";
    map[3] = "say goodbye ";


    for (int i = 0; i < notSoCrypticMessage.size(); ++i) {
        out += map[notSoCrypticMessage[i]];
    }

    /* így is meg lehet cinálni
    std::vector<std::string> goodvector;
    for (int i = 0; i < notSoCrypticMessage.size(); ++i) {
        goodvector.push_back(map[notSoCrypticMessage[i]]);
        out += goodvector[i];
    }
    */

    /* így is meg lehet csinálni
    std::string good = map[1];
    out += good;
    for (int i = 0; i < notSoCrypticMessage.size(); ++i) {
        good = map[notSoCrypticMessage[i]];
        out += good;
    }
    */
    // Things are a little bit messed up
    // Your job is to decode the notSoCrypticMessage by using the map as a look up table
    // Assemble the fragments into the out variable


    std::cout << out << std::endl;

    return 0;
}