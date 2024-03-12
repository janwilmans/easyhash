#include "fnv1a_hash.h"

#include <gtest/gtest.h>

TEST(basic_uniquenness, unsafe_hash)
{
    auto dynamic_string = std::make_unique<std::string>("Hello, world!");
    static_assert("Hello, world!"_unsafe_hash != "HellO, world!"_unsafe_hash, "Hash not unique");
    static_assert("Hello, world!"_unsafe_hash != "HellO, world!"_unsafe_hash, "Hash not unique");
    static_assert("Hello, world!"_unsafe_hash != "Hello, world1"_unsafe_hash, "Hash not unique");
    EXPECT_EQ(details::fnv1a_hash(*dynamic_string), "Hello, world!"_unsafe_hash);
}

TEST(basic_stability, unsafe_hash)
{
    EXPECT_EQ(""_unsafe_hash, 0x811c9dc5);
    EXPECT_EQ(" "_unsafe_hash, 0x76f6ae7f);
    EXPECT_EQ("A"_unsafe_hash, 0x15f615cc);
    EXPECT_EQ("B"_unsafe_hash, 0x18f61a85);
    EXPECT_EQ("C"_unsafe_hash, 0x17f618f2);
    EXPECT_EQ("D"_unsafe_hash, 0x12f61113);

    EXPECT_EQ("The"_unsafe_hash, 0x3a93e4bc);
    EXPECT_EQ("Restaurant"_unsafe_hash, 0xd19b1456);
    EXPECT_EQ("at"_unsafe_hash, 0x45a99f88);
    EXPECT_EQ("the"_unsafe_hash, 0x1f5be51c);
    EXPECT_EQ("end"_unsafe_hash, 0xbcade8aa);
    EXPECT_EQ("of"_unsafe_hash, 0x739c7068);
    EXPECT_EQ("The"_unsafe_hash, 0x3a93e4bc);
    EXPECT_EQ("universe"_unsafe_hash, 0x5ac719f6);
}