//
// Created by nicco on 30/09/2021.
//

#include "gtest/gtest.h"
#include "../Event.h"


TEST(Event, TestEvent) {
    Event event1 = Event("description", "title", Date(5, 7, 1999), false);
    ASSERT_EQ(event1.getEventTitle(), "title");
    ASSERT_EQ(event1.getEventDescription(), "description");
    ASSERT_FALSE(event1.isDone());
    ASSERT_FALSE(event1.isDone());
    event1.setDone(true);
    ASSERT_EQ(event1.isDone(), true);
}