//
// Created by bazylip on 09.05.18.
//

#ifndef JIMP_EXERCISES_ACADEMIASERIALIZER_H
#define JIMP_EXERCISES_ACADEMIASERIALIZER_H

#include "string"
#include "vector"

namespace academia {

    using std::vector;
    using std::reference_wrapper;

    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *input) : out_{*input}{}
        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

        int integer_field_called = 0;
        int double_field_called = 0;
        int boolean_field_called = 0;
        int serializable_field_called = 0;
        int string_field_called = 0;
        int array_field_called = 0;
        int header_field_called = 0;
        int footer_field_called = 0;

    protected:
        std::ostream &out_;
    };

    class XmlSerializer : public Serializer{
    public:

    };


    class JsonSerializer : public Serializer{
    public:

    };

    class Serializable {
    public:
        virtual void Serialize(Serializer *ser) const =0;
    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB
            LECTURE_HALL
        };

        Room(int Number, const std::string &Name, Type Enum) : Id_{Number}, Name_{Name}, EnumType_{Enum}{}
        std::string EnumToString(Type EnumType) const;

        void Serialize(Serializer *ser) const override {
            ser->Header("room");
            ser->IntegerField("id", Id_);
            ser->StringField("name", Name_);
            ser->StringField("type", EnumToString(EnumType_));
            ser->Footer("room");
        }

    private:
        int Id_;
        std::string Name_;
        Type EnumType_;
    };

    class Building : public Serializable{
    public:
        Building(int id, std::string name, vector<reference_wrapper<const academia::Serializable>> rooms): Id_{id}, Name_{name}, Rooms_{rooms}{}

        void Serialize(Serializer *ser) const override {
            ser->Header("building");
            ser->IntegerField("id", Id_);
            ser->StringField("name", Name_);
            ser->ArrayField("rooms", Rooms_);
            ser->Footer("building");
        }

    private:
        int Id_;
        std::string Name_;
        vector<reference_wrapper<const academia::Serializable>> Rooms_;

    };
}

#endif //JIMP_EXERCISES_ACADEMIASERIALIZER_H
