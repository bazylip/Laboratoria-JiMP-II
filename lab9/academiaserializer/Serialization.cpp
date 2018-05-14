//
// Created by bazylip on 09.05.18.
//

#include "Serialization.h"
#include "functional"

namespace academia{

    std::string Room::EnumToString(Type EnumType) const {
        switch(EnumType){
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    void JsonSerializer::Header(const std::string &object_name) {
        out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        out_ << "}";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if(field_name!="type"){
            out_ << "\"" << field_name <<"\": \""<<value<<"\", ";
        }else{
            out_ << "\"" << field_name <<"\": \""<<value<<"\"";
        }
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        out_ << "\"" << field_name <<"\": "<<value<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        out_ << "\"" << field_name <<"\": "<<value<<", ";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        if(value){
            out_ << "\"" << field_name <<"\": \"true\", ";
        }else{
            out_ << "\"" << field_name <<"\": \"false\", ";
        }
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        out_ << "\"" << field_name << "\"";
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const vector<reference_wrapper<const Serializable>> &value) {
        out_ << "\""<<field_name<<"\": [";
        int count = 0;
        for(auto SerializableField : value){
            if (count != 0){
                out_ << ", ";
            }
            SerializableField.get().Serialize(this);
            ++count;
        }
        out_ << "]";
    }

    vector<reference_wrapper<const Serializable>> Building::WrapperOfRooms() const {
        vector<std::reference_wrapper<const academia::Serializable>> out;
        for(auto &Room : Rooms_){
            out.emplace_back(std::cref(Room));
        }


        return out;
    }

    void XmlSerializer::Header(const std::string &object_name) {
        out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        out_ << "<\\" << object_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        if(value){
            out_ << "<" << field_name << ">" << "true" << "<\\" << field_name << ">";
        }else{
            out_ << "<" << field_name << ">" << "false" << "<\\" << field_name << ">";
        }
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const vector<reference_wrapper<const Serializable>> &value) {
        out_ << "<" << field_name << ">";
        for(auto &SerializableField : value){
            SerializableField.get().Serialize(this);
        }
        out_ << "<\\" << field_name << ">";

    }

    void BuildingRepository::StoreAll(Serializer *ser) {
        ser->Header("building_repository");
        ser->ArrayField("buildings", this->WrapperOfBuildings());
        ser->Footer("building_repository");

    }

    vector<reference_wrapper<const academia::Serializable>> BuildingRepository::WrapperOfBuildings() const {
        vector<std::reference_wrapper<const academia::Serializable>> out;

        for(auto &Building : Buildings_){
            out.emplace_back(std::cref(Building));
        }


        return out;

    }

    void BuildingRepository::Add(const Building &NewBuilding) {
        Buildings_.emplace_back(NewBuilding);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int Id) const {
        for (auto &Building : Buildings_){
            if(Building.Id() == Id){
                return Building;
            }
        }
    }

    int Building::Id() const {
        return Id_;
    }
}
