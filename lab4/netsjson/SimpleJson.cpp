//
// Created by bazylip on 05.04.18.
//

#include "SimpleJson.h"

namespace nets{
    using ::std::experimental::optional;
    JsonValue::JsonValue(int input) {
        Json_ = std::to_string(input);
        output_ = Json_;
    }
    JsonValue::JsonValue(double input) {
        Json_ = std::to_string(input);
        Json_.erase(Json_.find_last_not_of('0') + 1, string::npos);
        output_ = Json_;
    }
    JsonValue::JsonValue(string input) {
        Json_ =  std::move(input);

        string output = "\"";
        for(int i = 0; i < Json_.size(); ++i){
            if(Json_[i] == '\"' or Json_[i] == '\\')
                output += '\\';
            output += Json_[i];
        }
        output_ = output + '\"';
    }
    JsonValue::JsonValue(bool input) {
        input ? Json_ = "true" : Json_ = "false";
        output_ = Json_;
    }

    JsonValue::JsonValue(const vector<JsonValue> &input) {
        JsonVector_ = input;
        string output = "[";
        for(auto it = JsonVector_.begin(); it != JsonVector_.end(); it = std::next(it)){
            output += it->ToString();
            if(std::next(it) != JsonVector_.end())
                output += ", ";
        }

        output_ = output +  "]";
    }

    JsonValue::JsonValue(const map<string, JsonValue> &input) {
        JsonMap_ = input;
        string output = "{";
        for(auto it = JsonMap_.begin(); it != JsonMap_.end(); it = std::next(it)){
            JsonValue buf(it->first);
            output += buf.ToString() + ": " + it->second.ToString();
            if(std::next(it) != JsonMap_.end())
                output += ", ";
        }

        output_ = output +  "}";
    }

    optional<JsonValue> JsonValue::ValueByName(const std::string &name){
        auto got = JsonMap_.find(name);
        if(got != JsonMap_.end()){

            return got->second;
        }
    }

    std::string JsonValue::ToString(){
        return output_;
    }
}
