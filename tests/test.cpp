// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "firstex.h"
#include "secondex.h"

class StackFixture : public ::testing::Test {
protected:
    struct Copyable {
        Copyable() = default;
        Copyable(const Copyable &) = default;
        Copyable(Copyable &&) = default;

        int value = 0;
    };

    struct NotCopyable {
        NotCopyable() = default;
        NotCopyable(const NotCopyable &) = delete;
        NotCopyable(NotCopyable &&) = default;

        int value = 0;
    };

    FirstStack<Copyable> copyableStack{};
    SecondStack<NotCopyable> notCopyableStack{};

    void SetUp() override {
        copyableStack.push({1});
        copyableStack.push({2});

        notCopyableStack.push({5});
        notCopyableStack.push({6});
    }
};

TEST_F(StackFixture, StructTest) {
    EXPECT_EQ(std::is_move_constructible_v<Copyable>, true);
    EXPECT_EQ(std::is_copy_constructible_v<Copyable>, true);

    EXPECT_EQ(std::is_move_constructible_v<NotCopyable>, true);
    EXPECT_EQ(std::is_copy_constructible_v<NotCopyable>, false);
}

TEST_F(StackFixture, ConstructorTest) {
    EXPECT_EQ(std::is_move_constructible_v<FirstStack<int>>, true);
    EXPECT_EQ(std::is_copy_constructible_v<FirstStack<int>>, false);
    EXPECT_EQ(std::is_move_assignable_v<FirstStack<int>>, true);
    EXPECT_EQ(std::is_copy_assignable_v<FirstStack<int>>, false);

    EXPECT_EQ(std::is_move_constructible_v<SecondStack<int>>, true);
    EXPECT_EQ(std::is_copy_constructible_v<SecondStack<int>>, false);
    EXPECT_EQ(std::is_move_assignable_v<SecondStack<int>>, true);
    EXPECT_EQ(std::is_copy_assignable_v<SecondStack<int>>, false);
}

TEST_F(StackFixture, Copy_push) {
    Copyable x{3};
    copyableStack.push(x);
    EXPECT_EQ(copyableStack.Head().value, 3);
}

TEST_F(StackFixture, Move_push) {
    NotCopyable x{7};
    notCopyableStack.push(std::move(x));
    EXPECT_EQ(notCopyableStack.Head().value, 7);
}

TEST_F(StackFixture, push_emplace) {
    int a = 8;
    notCopyableStack.push_emplace(a);
    EXPECT_EQ(notCopyableStack.Head().value, a);
}

TEST_F(StackFixture, pop) {
    EXPECT_EQ(copyableStack.Head().value, 2);
    copyableStack.pop();
    EXPECT_EQ(copyableStack.Head().value, 1);
}
