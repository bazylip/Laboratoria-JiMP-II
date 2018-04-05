//
// Created by bazylip on 02.04.18.
//

#include "SimpleTemplateEngine.h"
#include "iostream"

namespace nets{
    using ::std::cout;
    using ::std::endl;
    View::View(const std::string &Template){
        Template_ = Template;
    }

    std::string View::GetTemplate() {
        return Template_;
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) {
        std::string CopyOfTemplate = GetTemplate();
        std::string OutputString;
        for(int i = 0; i < CopyOfTemplate.length(); ++i){
            if(CopyOfTemplate[i] == '{' && CopyOfTemplate[i+1] == '{'){
                while(CopyOfTemplate[i+2] == '{') {
                    OutputString += '{';
                    ++i;
                }
                bool Flag = false;
                int PositionBegin = i;
                std::string Key;
                i += 2;
                while(i < CopyOfTemplate.length()){
                    if (CopyOfTemplate[i] == '}' && CopyOfTemplate[i+1] == '}')
                        break;
                    if (CopyOfTemplate[i] == ' '){
                        Flag = true;
                        break;
                    }
                    Key += CopyOfTemplate[i];
                    ++i;
                }
                if(Flag){
                    OutputString += "{{" + Key + ' ';
                    continue;
                }
                i++;
                if(Key.length() > 0) {
                    std::unordered_map<std::string, std::string>::const_iterator Found = model.find(Key);
                    if (Found != model.end())
                        OutputString += Found->second;
                }
            }else
                OutputString += CopyOfTemplate[i];
        }

        return OutputString;
    }

}