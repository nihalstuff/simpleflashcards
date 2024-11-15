#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>

int main() {
    std::vector<std::string> fronts;
    std::string prefront;
    std::vector<std::string> backs;
    std::string preback;
    int endcheck;
    std::string card;
    std::string delimiter = "|";
    std::string response;
    std::string correctans;
    int ind;
    std::cout<<"welcome to flashcards. add cards with the format front|back. if you're done say end after\n";
    while (endcheck == 0) {
        std::cin>>card;
        std::cout<<"\n";
        if (card == "end") {
            endcheck = 1;
        } else {
            std::stringstream ss(card);
            size_t pos = card.find(delimiter);
            prefront = card.substr(0, pos);
            preback = card.substr(pos + 1);
            fronts.push_back(prefront);
            backs.push_back(preback);
        }
    }
    std::cout<<"created a set with "<<size(fronts)<< " cards. type ^^^^^^ to end review session\n\n";
    while (response != "^^^^^^") {
        ind = rand()%size(fronts);
        std::cout<<fronts[ind]<<"\n";
        correctans = backs[ind];
        std::cin>>response;
        if (response == correctans) {
            std::cout<<"\ncorrect\n";
        } else if(response == "^^^^^^"){
            std::cout<<"\ngoodbye";
        } else {
            std::cout<<"\nincorrect, correct answer was "<<correctans<<"\n";
        }
    }
}
