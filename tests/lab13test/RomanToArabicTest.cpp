#include "gtest/gtest.h"
#include "ArabicRoman.h"

TEST(RomanToArabic, RomanToArabicOfIReturns1){
    EXPECT_EQ(1, RomanToArabic("I"));
}