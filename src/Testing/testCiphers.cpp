//! Unit Tests for MPAGSCipher Cipher Class
#include "gtest/gtest.h"

#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText)
{
    return cipher.applyCipher(inputText, mode) == outputText;
}


TEST(PlayfairCipher, Encrypt)
{
    PlayfairCipher cc{"hello"};
    EXPECT_EQ(testCipher(cc, CipherMode::Encrypt, "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ",
                       "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"),
              true);
}

TEST(PlayfairCipher, Decrypt)
{
    PlayfairCipher cc{"hello"};
    EXPECT_EQ(testCipher(cc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA",
                       "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"),
              true);
}

TEST(CaesarCipher, Encrypt)
{
    CaesarCipher cc{10};
    EXPECT_EQ(testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"), true);
}

TEST(CaesarCipher, Decrypt)
{
    CaesarCipher cc{10};
    EXPECT_EQ(testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"), true);
}

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_EQ(testCipher(cc, CipherMode::Encrypt,
                       "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES",
                       "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ"),
              true);
}

TEST(VigenereCipher, Decrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_EQ(testCipher(cc, CipherMode::Decrypt,
                       "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ",
                       "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES"),
              true);
}

