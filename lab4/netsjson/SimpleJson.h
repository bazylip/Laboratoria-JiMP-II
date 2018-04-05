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

    class JsonValue{
    public:
        JsonValue();
        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        int Int_;
//        optional<double> Double_;
//        optional<string> String_;
//        optional<bool> Bool_;
//        optional< vector<JsonValue> > Vector_;
//        optional<JsonValue> Json_;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
