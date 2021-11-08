//
// Created by nicco on 30/09/2021.
//

#include "gtest/gtest.h"
#include "../Date.h"

TEST(Date, DateTest) {

    Date data1 = Date(15, 8, 2020);
    ASSERT_EQ(data1.getDay(), 15);
    ASSERT_EQ(data1.getMonth(), 8);
    ASSERT_EQ(data1.getYear(), 2020);
    ASSERT_ANY_THROW(Date(30, 2, 2015));
}