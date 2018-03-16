//
// Created by bazylip on 16.03.18.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference{
    using ::std::string;
    using ::std::vector;
    unsigned int ToMinutes(const string &time_HH_MM) {
        using ::std::regex;
        using ::std::smatch;
        using ::std::cout;
        using ::std::endl;
        regex pattern{R"(^([0-9]*):([0-9]*)$)"};
        smatch matches;
        regex_match(time_HH_MM, matches, pattern);
        string hour = matches[1];
        string minutes = matches[2];
        unsigned int output = 0;
        if(hour.size() != 1)
            output = (((int)hour[0] - 48)*10 + (int)hour[1] - 48)*60 + (((int)minutes[0] - 48)*10 + (int)minutes[1] - 48);
        else
            output = 60 * ((int) hour[0] - 48) + (((int) minutes[0] - 48) * 10 + ((int) minutes[1] - 48));

        return output;
    }
    unsigned int MinimalTimeDifference(vector<string> times){
        vector<unsigned int> minutes;
        unsigned int minimal;

        for(auto h : times){
            minutes.push_back(ToMinutes(h));
        }

        std::sort(minutes.begin(), minutes.end());

        for(auto j : minutes){
            std::cout<<j<<std::endl;
        }
        int i = 0;
        for(i = 0; i < minutes.size()-1; ++i){
            if(i == 0){
                minimal = minutes[i+1] - minutes[i];
            }else{
                if(minutes[i+1] - minutes[i] < minimal){
                    minimal = minutes[i+1] - minutes[i];
                }
            }
        }
        if(1440-minutes[minutes.size()-1] + minutes[0] < minimal)
            minimal = 1440-minutes[minutes.size()-1] + minutes[0];

        return minimal;
    }
}
