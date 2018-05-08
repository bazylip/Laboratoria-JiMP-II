//
// Created by bazylip on 08.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include "istream"
#include "regex"
#include "string"
#include "stdexcept"


namespace moviesubs{

    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) =0;
        virtual ~MovieSubtitles() = default;
    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;
    };

    class SubtitlesException : public std::invalid_argument{
    public:
        SubtitlesException(int LineNumber, const std::string &Text): invalid_argument(Text){}
    };

    class NegativeFrameAfterShift : public SubtitlesException{
    public:
        NegativeFrameAfterShift(int LineNumber, const std::string &Text) : SubtitlesException(LineNumber, Text){}
    };

    class SubtitleEndBeforeStart : public SubtitlesException{
    public:
        SubtitleEndBeforeStart(int LineNumber, const std::string &Text) : SubtitlesException(LineNumber, Text), LineAt_(LineNumber){}
        int LineAt() const;

    private:
        int LineAt_;
    };

    class InvalidSubtitleLineFormat : public SubtitlesException{
    public:
        InvalidSubtitleLineFormat(int LineNumber, const std::string &Text) : SubtitlesException(LineNumber, Text){}
    };




    class SubRipSubtitles : public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
