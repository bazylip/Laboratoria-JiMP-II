//
// Created by bazylip on 02.04.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets {
    class View {
    public:
        View(const std::string &Template);
        std::string Render(const std::unordered_map<std::string, std::string> &model);
        std::string GetTemplate();
    private:
        std::string Template_;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
