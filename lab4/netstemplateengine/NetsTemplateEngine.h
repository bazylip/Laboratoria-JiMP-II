//
// Created by bazylip on 02.04.18.
//

#ifndef JIMP_EXERCISES_NETSTEMPLATEENGINE_H
#define JIMP_EXERCISES_NETSTEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets {
    class View {
    public:
        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string Template_;
    };
}

#endif //JIMP_EXERCISES_NETSTEMPLATEENGINE_H
