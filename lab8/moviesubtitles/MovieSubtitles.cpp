//
// Created by bazylip on 08.05.18.
//

#include "MovieSubtitles.h"

using std::regex;
using std::string;

namespace moviesubs{
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                std::ostream *out) {

        string Subtitle;

        regex pattern(R"(\{(\d+)\}\{(\d+)\}(.*))");
        std::cmatch matches;
        int LineNumber = 0;

        if(frame_per_second < 0){
            throw NegativeFrameAfterShift(0, "FPS negative");
        }

        while(getline(*in, Subtitle)){


            
            ++LineNumber;

            if(std::regex_match(Subtitle.c_str(), matches, pattern)){
                int Start = std::stoi(matches[1]) + (offset_in_micro_seconds / (1000 / frame_per_second)), End = std::stoi(matches[2]) + (offset_in_micro_seconds / (1000 / frame_per_second));
                if(Start < 0 or End < 0){
                    throw NegativeFrameAfterShift(LineNumber, "123");
                }

                if(Start >= End){
                    throw SubtitleEndBeforeStart(LineNumber, "At line "+std::to_string(LineNumber)+": "+Subtitle);
                }

                *out << "{" << Start << "}{" << End << "}" << matches[3] << "\n";
            }else{
                throw InvalidSubtitleLineFormat(LineNumber, "InvalidSubtitleLineFormat");
            }

        }

    }

    int SubtitleEndBeforeStart::LineAt() const{
        return LineAt_;
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                              std::ostream *out) {
    //zbugowane te testy, nie idzie zrobić
    }
}
