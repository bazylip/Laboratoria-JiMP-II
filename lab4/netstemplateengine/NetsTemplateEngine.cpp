//
// Created by bazylip on 02.04.18.
//

#include "NetsTemplateEngine.h"

namespace nets{
    View::View(std::string Template){
        Template_ = Template;
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        return "123";
    }

}
