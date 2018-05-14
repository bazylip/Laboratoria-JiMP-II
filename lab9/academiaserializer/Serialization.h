//
// Created by bazylip on 09.05.18.
//

#ifndef JIMP_EXERCISES_ACADEMIASERIALIZER_H
#define JIMP_EXERCISES_ACADEMIASERIALIZER_H

#include "string"
#include "vector"
#include "ostream"
#include "experimental/optional"

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
        explicit XmlSerializer(std::ostream *input): Serializer{input}{}
        void IntegerField(const std::string &field_name, int value) override ;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };


    class JsonSerializer : public Serializer{
    public:
        explicit JsonSerializer(std::ostream *input): Serializer{input}{}
        void IntegerField(const std::string &field_name, int value) override ;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class Serializable {
    public:
        virtual void Serialize(Serializer *ser) const =0;
    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
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
        Building(int id, std::string name, const vector<Room> &rooms): Id_{id}, Name_{name}, Rooms_{rooms}{}

        void Serialize(Serializer *ser) const override {
            ser->Header("building");
            ser->IntegerField("id", Id_);
            ser->StringField("name", Name_);
            ser->ArrayField("rooms", this->WrapperOfRooms());
            ser->Footer("building");
        }

        vector<std::reference_wrapper<const academia::Serializable>> WrapperOfRooms() const;

        int Id() const;

    private:
        int Id_;
        std::string Name_;
        vector<Room> Rooms_;

    };

    class BuildingRepository{
    public:
        BuildingRepository(std::initializer_list<Building> Buildings): Buildings_{Buildings}{}

        void Add(const Building &NewBuilding);
        void StoreAll(Serializer *ser);
        vector<std::reference_wrapper<const academia::Serializable>> WrapperOfBuildings() const;

        std::experimental::optional<Building> operator[](int Id) const;
    private:
        vector<Building> Buildings_;
    };

    
}

#endif //JIMP_EXERCISES_ACADEMIASERIALIZER_H
