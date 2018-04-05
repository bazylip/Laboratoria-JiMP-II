//
// Created by bazylip on 05.04.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include<experimental/optional>

namespace nets{
    using ::std::experimental::optional;

    class JsonValue{
    public:
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        

    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
