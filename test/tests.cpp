// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(TEST1, TrueOrFalse) {
    Automata automata;
    automata.On();
    EXPECT_EQ(STATES::WAIT, automata.GetState());
}

TEST(TEST2, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(100);
    EXPECT_EQ(STATES::ACCEPT, automata.GetState());
}

TEST(TEST3, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(100);
    automata.Coin(10);
    EXPECT_EQ(STATES::ACCEPT, automata.GetState());
}

TEST(TEST4, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(100);
    automata.Choice(2);
    EXPECT_EQ(STATES::CHECK, automata.GetState());
}

TEST(TEST5, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(100);
    automata.Choice(2);
    automata.Check();
    EXPECT_EQ(STATES::WAIT, automata.GetState());
}

TEST(TEST6, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(120);
    automata.Choice(2);
    automata.Check();
    EXPECT_EQ(STATES::COOK, automata.GetState());
}

TEST(TEST7, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(120);
    automata.Choice(2);
    automata.Check();
    automata.Cook();
    EXPECT_EQ(0, automata.GetCash());
}

TEST(TEST8, TrueOrFalse) {
    Automata automata;
    automata.On();
    automata.Coin(120);
    automata.Choice(2);
    automata.Check();
    automata.Cook();
    automata.Finish();
    automata.Off();
    EXPECT_EQ(STATES::OFF, automata.GetState());
}
