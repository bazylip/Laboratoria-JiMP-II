//
// Created by bazylip on 05.04.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include<experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

namespace nets{
    using ::std::experimental::optional;
    using ::std::string;
    using ::std::vector;
    using ::std::map;

    class JsonValue{
    public:
        JsonValue(int input);
        JsonValue(double input);
        JsonValue(bool input);
        JsonValue(string input);
        JsonValue(const vector<JsonValue> &input);
        JsonValue(const map<string, JsonValue> &input);
        ~JsonValue() = default;

        std::experimental::optional<JsonValue> ValueByName(const std::string &name);
        std::string ToString();

    private:
        string Json_;
        vector<JsonValue> JsonVector_;
        map<string, JsonValue> JsonMap_;
        string output_;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
