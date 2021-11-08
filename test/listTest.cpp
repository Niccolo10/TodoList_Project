//
// Created by nicco on 08/11/2021.
//

#include <gtest/gtest.h>
#include "../List.h"

TEST(List, listTest) {
    Event event1 = Event("description", "title", Date(5, 7, 1999), false);
    List list1("lista");
    EXPECT_EQ(list1.getSize(), 0);
    list1.addEvent(event1);
    EXPECT_EQ(list1.getSize(), 1);
    list1.addEvent(event1);
    EXPECT_EQ(list1.getSize(), 2);
    list1.deleteEvent(1);
    list1.deleteEvent(event1);
    EXPECT_EQ(list1.getSize(), 0);

}