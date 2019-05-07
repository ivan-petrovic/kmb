#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


// std::vector<std::string> split(std::string const &input) { 
//     std::istringstream buffer(input);
//     std::vector<std::string> ret;

//     std::copy(std::istream_iterator<std::string>(buffer), 
//               std::istream_iterator<std::string>(),
//               std::back_inserter(ret));
//     return ret;
// }

std::vector<std::string> split(std::string const &input) { 
    std::istringstream buffer(input);
    // std::vector<std::string> ret((std::istream_iterator<std::string>(buffer)), 
    //                              std::istream_iterator<std::string>());

    std::vector<std::string> ret {
        std::istream_iterator<std::string>(buffer),
        std::istream_iterator<std::string>()
    };

    // std::vector<std::string> ret(std::istream_iterator<std::string>{buffer},
    //                              std::istream_iterator<std::string>());
    return ret;
    
}

int main(int argc, char* argv[]) 
{
    string input = "move    a  little   to   the      left";

    vector<string> results;
    results = split(input);
    //    stringstream s(input);
    //    while(!s.eof()) {
    //       string tmp;
    //       s >> tmp;
    //       results.push_back(tmp);
    //    }

    // items now stored in results:
    for(vector<string>::const_iterator i = results.begin();
        i != results.end();
        ++i) {
        cout << *i << " - " << (*i).size() << endl;
    }
}
