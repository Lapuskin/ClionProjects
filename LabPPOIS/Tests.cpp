#include <gtest/gtest.h>
#include "header.h"

//арифметические операции
class Addition : public ::testing::Test {
public:
  Long l1 = 123;
  Long l2 = 735;
  int i = 735;
};
class Multiplication : public ::testing::Test {
public:
    Long l1 = 123;
    Long l2 = 735;
    int i = 735;
};
class Division : public ::testing::Test {
public:
    Long l1 = 123;
    Long l2 = 735;
    int i = 735;
};
class Subtraction : public ::testing::Test {
public:
    Long l1 = 123;
    Long l2 = 735;
    int i = 735;
};

class Compare : public ::testing::Test {
public:
    Long l1 = -123;
    Long l2 = 753;
    int i = 753;
};

class KreMent : public ::testing::Test {
public:
    Long l1 = -123;
};


//длинные
TEST_F(Addition, Long) {
    EXPECT_EQ(858, l1 + l2);
}
TEST_F(Division, Long) {
    EXPECT_EQ(0, l1 / l2);
}
TEST_F(Subtraction, Long) {
    Long l3 = l1 - l2;
    cout << l3;
    EXPECT_EQ(612, l1 - l2);
}
TEST_F(Multiplication, Long) {
    EXPECT_EQ(90405, l1 * l2);
}
//целые
TEST_F(Addition, Int) {
    EXPECT_EQ(858, l1 + i);
}
TEST_F(Division, Int) {
    EXPECT_EQ(0, l1 / i);
}
TEST_F(Subtraction, Int) {
    Long l3 = l1 - i;
    cout << l3;
    EXPECT_EQ(612, l1 - i);
}
TEST_F(Multiplication, Int) {
    EXPECT_EQ(90405, l1 * i);
}

//короткое сравнение
//длинные
TEST_F(Addition, AppropriationLong) {
    l1+=l2;
    EXPECT_EQ(858, l1);
}
TEST_F(Division, AppropriationLong) {
    l1/=l2;
    EXPECT_EQ(0, l1);
}
TEST_F(Subtraction, AppropriationLong) {
    l1-=l2;
    EXPECT_EQ(612, l1);
}
TEST_F(Multiplication, AppropriationLong) {
    l1*=l2;
    EXPECT_EQ(90405, l1);
}
//целые
TEST_F(Addition, AppropriationInt) {
    l1+=i;
    EXPECT_EQ(858, l1);
}
TEST_F(Division, AppropriationInt) {
    l1/=i;
    EXPECT_EQ(0, l1);
}
TEST_F(Subtraction, AppropriationInt) {
    l1-=i;
    EXPECT_EQ(612, l1);
}
TEST_F(Multiplication, AppropriationInt) {
    l1 *= i;
    EXPECT_EQ(90405, l1);
};
TEST(Dec, Post){
    Long l = 123;
    l++;
    EXPECT_EQ(124, l);
};
TEST(Dec, Pre){
    Long l = 123;
    ++l;
    EXPECT_EQ(124, l);
};
TEST(Incr, Post){
    Long l = 123;
    l--;
    EXPECT_EQ(122, l);
};
TEST(Incr, Pre){
    Long l = 123;
    --l;
    EXPECT_EQ(122, l);
};

//сравнение длинные
TEST_F(Compare, MoreLong) {
    EXPECT_EQ(0, l1 > l2);
};
TEST_F(Compare, MoreEqLong) {
    EXPECT_EQ(0, l1 >= l2);
};
TEST_F(Compare, LessLong) {
    EXPECT_EQ(1, l1 < l2);
};
TEST_F(Compare, LessEqLong) {
    EXPECT_EQ(1, l1 <= l2);
};

//целые сравнение
TEST_F(Compare, MoreInt) {
    EXPECT_EQ(0, l1 > i);
};
TEST_F(Compare, MoreEqInt) {
    EXPECT_EQ(0, l1 >= i);
};
TEST_F(Compare, LessInt) {
    EXPECT_EQ(1, l1 < i);
};
TEST_F(Compare, LessEqInt) {
    EXPECT_EQ(1, l1 <= i);
};