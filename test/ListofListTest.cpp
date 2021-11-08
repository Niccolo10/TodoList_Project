//
// Created by nicco on 08/11/2021.
//

#include <gtest/gtest.h>
#include "../ListOfLists.h"
#include "../List.h"

class Tester : public ::testing::Test {
protected:
    virtual void SetUp() {
        List list1 = List("lista 1");
        List list2 = List("lista 2");
        List list3 = List("lista 3");
        LoL.addList(list1);
        LoL.addList(list2);
        LoL.addList(list3);

    }

    ListOfLists LoL;
};

TEST_F(Tester, test) {
    Event event1 = Event("Concerto", "Andare al concerto al forum", Date(15, 11, 2021), false);
    Event event2 = Event("Dottore", "visita sportiva", Date(22, 11, 2021), false);
    Event event3 = Event("Spesa", "comprare carne e patate", Date(10, 11, 2021), false);
    LoL.addEventToList("lista 1", event1);
    LoL.addEventToList("lista 2", event2);
    LoL.addEventToList("lista 3", event3);
    EXPECT_EQ(LoL.getSize(), 3);
    LoL.moveList("lista 2", "lista 3", event2);
    EXPECT_EQ(LoL.getSize(), 3);
    EXPECT_EQ(LoL.getList("lista 3").getSize(), 2);
    EXPECT_EQ(LoL.getList("lista 2").getSize(), 0);

}