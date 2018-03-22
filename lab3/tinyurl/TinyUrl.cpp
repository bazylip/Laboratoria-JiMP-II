//
// Created by bazylip on 21.03.18.
//

#include "TinyUrl.h"

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init(){
        auto codec = std::make_unique<TinyUrlCodec>();
        codec->PreviousCodec = {'0','0','0','0','0','0'};

        return codec;
    }

    void NextHash(std::array<char, 6> *state) {
        using ::std::array;
        int i = 5;

        while (i >= 0) {


            if ((*state)[i] != 57 and (*state)[i] != 90 and (*state)[i] != 122) {
                (*state)[i] += 1;
                break;
            } else if ((*state)[i] == 57) {
                (*state)[i] = 65;
                break;
            } else if ((*state)[i] == 90) {
                (*state)[i] = 97;
                break;
            } else {
                (*state)[i] = 48;
                --i;
            }
        }
    };

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        (*codec)->map.emplace(url, (*codec)->PreviousCodec);
        std::string output;
        for(auto c : (*codec)->PreviousCodec){
            output += c;
        }
        NextHash(& (*codec)->PreviousCodec);

        return output;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        std::array<char, 6> NewHash;
        int i = 0;
        for(char c : hash){
            NewHash[i] = c;
            ++i;
        }
        for(auto element : codec->map){
            if(element.second == NewHash){
                return element.first;
            }
        }
    }

}