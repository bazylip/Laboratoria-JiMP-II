//
// Created by bazylip on 21.05.18.
//

#include "Scheduler.h"

void academia::Schedule::InsertScheduleItem(const SchedulingItem &item) {
    Items_.push_back(item);
}

size_t academia::Schedule::Size() const {
    return(Items_.size());
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    academia::Schedule Result;

    std::copy_if(Items_.begin(), Items_.end(), std::back_inserter(Result.Items_), [room_id](SchedulingItem Item)  {return room_id == Item.RoomId();});

    return Result;
}

academia::Schedule academia::Schedule::OfYear(int year_id) const {
    academia::Schedule Result;

    std::copy_if(Items_.begin(), Items_.end(), std::back_inserter(Result.Items_), [year_id](SchedulingItem Item)  {return year_id == Item.Year();});

    return Result;
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    academia::Schedule Result;

    std::copy_if(Items_.begin(), Items_.end(), std::back_inserter(Result.Items_), [teacher_id](academia::SchedulingItem Item)  {return teacher_id == Item.TeacherId();});

    return Result;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> Result;
    for(int i = 1; i <= n_time_slots; ++i ){
        Result.push_back(i);
    }
    if(Items_.size() != 0) {
        for (auto it : Items_) {
            Result.erase(std::remove_if(Result.begin(), Result.end(), [&it](int slot) { return slot == it.TimeSlot(); }), Result.end());
        }
    }

    return Result;
}


academia::SchedulingItem academia::Schedule::operator[](int Id) const {
    return Items_[Id];
}

int academia::SchedulingItem::TimeSlot() const {
    return TimeSlot_;
}

int academia::SchedulingItem::CourseId() const {
    return CourseId_;
}

int academia::SchedulingItem::RoomId() const {
    return RoomId_;
}

int academia::SchedulingItem::TeacherId() const {
    return TeacherId_;
}

int academia::SchedulingItem::Year() const {
    return Year_;
}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                       const std::map<int, std::vector<int> > &teacher_courses_assignment,
                                                       const std::map<int, std::set<int> > &courses_of_year,
                                                       int n_time_slots) {
    int Room = 0;

    Schedule NewSchedule;



    for(const auto &Teacher : teacher_courses_assignment){
        if(Teacher.second.size() >= n_time_slots){
            throw NoViableSolutionFound("Too many teacher courses!");
        }else{

            for(const auto &TCourse : Teacher.second){

                for(const auto &Year : courses_of_year){

                    if(Year.second.size() >= n_time_slots){
                        throw NoViableSolutionFound("Too many year courses!");
                    } else{

                        for(const auto &YCourse: Year.second) {

                            if (YCourse == TCourse) {

                                academia::SchedulingItem NewItem = SchedulingItem(TCourse, Teacher.first,
                                                                                  rooms[Room], Room, Year.first);
                                ++Room;


                                NewSchedule.InsertScheduleItem(NewItem);
                            }
                        }
                    }
                }
            }
        }
    }

    return NewSchedule;
}