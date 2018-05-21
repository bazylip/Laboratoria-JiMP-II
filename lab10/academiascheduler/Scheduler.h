//
// Created by bazylip on 21.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include "vector"
#include <cstdio>
#include "stdexcept"
#include "map"
#include "set"
#include "string"
#include "algorithm"

namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem(int Course, int Teacher, int Room, int Time, int Year): CourseId_{Course}, TeacherId_{Teacher}, RoomId_{Room}, TimeSlot_{Time}, Year_{Year}{}
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

    private:
        int CourseId_;
        int TeacherId_;
        int RoomId_;
        int TimeSlot_;
        int Year_;
    };

    class Schedule{
    public:
        Schedule() = default;
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

        SchedulingItem operator[](int Id) const;

    private:
        std::vector<academia::SchedulingItem> Items_;
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int> > &teacher_courses_assignment, const std::map<int, std::set<int> > &courses_of_year, int n_time_slots) =0;
    };

    class NoViableSolutionFound : public std::invalid_argument{
    public:
        NoViableSolutionFound(const std::string &message): invalid_argument(message){}
    };

    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int> > &teacher_courses_assignment, const std::map<int, std::set<int> > &courses_of_year, int n_time_slots) override;
    };

}


#endif //JIMP_EXERCISES_SCHEDULER_H
