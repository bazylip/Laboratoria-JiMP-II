#include "gtest/gtest.h"
#include "ArabicRoman.h"

TEST(ArabicToRomanTest, ArabicToRomanOf1ReturnsI){
    EXPECT_EQ("I", ArabicToRoman(1));
}

TEST(ArabicToRomanTest, ArabicToRomanOf4ReturnsIV){
    EXPECT_EQ("IV", ArabicToRoman(4));
}

TEST(ArabicToRomanTest, ArabicToRomanOf399ReturnsCCCXCIX){
    EXPECT_EQ("CCCXCIX", ArabicToRoman(399));
}

TEST(ArabicToRomanTest, ArabicToRomanOf400ReturnsCD){
    EXPECT_EQ("CD", ArabicToRoman(400));
}

TEST(ArabicToRomanTest, ArabicToRomanCaseSensitive){
    EXPECT_NE("Iv", ArabicToRoman(4));
}

TEST(ArabicToRomanTest, ArabicToRomanOfMoreThan3999GeneratesError){
    EXPECT_THROW(ArabicToRoman(4000), std::invalid_argument);
}

TEST(ArabicToRomanTest, ArabicToRomanOfMoreThan3999GeneratesCorrectError){
    try{
        ArabicToRoman(4000);
        FAIL();
    }catch(const std::invalid_argument &error){
        EXPECT_EQ("Number too big!",error.what());
    }catch (...){
        FAIL();
    }
}

TEST(ArabicToRomanTest, ArabicToRomanOfLessThan1GeneratesError){
    EXPECT_THROW(ArabicToRoman(-1), std::invalid_argument);
}
