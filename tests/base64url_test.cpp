#include "base64url.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(Base64UrlUtilTest, InvalidChar) {

  Base64Url::Base64UrlUtil b;
  int i;

  for (i = 0; i < 127; i++) {

    if (i >= 48 && i <= 57)
      EXPECT_FALSE(b.invalid_char((char)i));
    else if (i >= 65 && i <= 90)
      EXPECT_FALSE(b.invalid_char((char)i));
    else if (i >= 97 && i <= 122)
      EXPECT_FALSE(b.invalid_char((char)i));
    else if (i == 45)
      EXPECT_FALSE(b.invalid_char((char)i));
    else if (i == 95)
      EXPECT_FALSE(b.invalid_char((char)i));
    else
      EXPECT_TRUE(b.invalid_char((char)i));
  }
}

TEST(Base64UrlUtilTestTest, EncodingSize) {
  Base64Url::Base64UrlUtil b;
  EXPECT_TRUE(b.encoded_size((size_t)16) == 22);
  EXPECT_TRUE(b.encoded_size((size_t)32) == 43);
  EXPECT_TRUE(b.encoded_size((size_t)64) == 86);
}

TEST(Base64UrlUtilTest, DecodingSize) {
  Base64Url::Base64UrlUtil b;
  EXPECT_TRUE(b.decoded_size((size_t)22) == 16);
  EXPECT_TRUE(b.decoded_size((size_t)43) == 32);
  EXPECT_TRUE(b.decoded_size((size_t)86) == 64);
}

TEST(Base64UrlTest, Encoding) {
  
  Base64Url::Base64Url b;
  char encoded[500];

  b.encode((uint8_t *)"f", strlen("f"), (uint8_t *)encoded,
                    sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "Zg", 2) == 0);

  b.encode((uint8_t *)"fo", strlen("fo"), (uint8_t *)encoded,
                    sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "Zm8", 3) == 0);

  b.encode((uint8_t *)"foo", strlen("foo"), (uint8_t *)encoded,
                    sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "Zm9v", 4) == 0);

  b.encode((uint8_t *)"foob", strlen("foob"), (uint8_t *)encoded,
                    sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "Zm9vYg", 6) == 0);

  b.encode((uint8_t *)"fooba", strlen("fooba"), (uint8_t *)encoded,
                    sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "Zm9vYmE", 7) == 0);

  b.encode((uint8_t *)"foobar", strlen("foobar"), (uint8_t *)encoded,
                    sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "Zm9vYmFy", 8) == 0);

  b.encode((uint8_t *)"Hello, World!", strlen("Hello, World!"),
                    (uint8_t *)encoded, sizeof(encoded));
  EXPECT_TRUE(strncmp(encoded, "SGVsbG8sIFdvcmxkIQ", 18) == 0);
}

TEST(Base64UrlTest, Decoding) {
  
  Base64Url::Base64Url b;
  char decoded[500];

  b.decode((uint8_t *)"Zg", strlen("Zg"), (uint8_t *)decoded,
                    sizeof(decoded));
  EXPECT_TRUE(strncmp(decoded, "f", 1) == 0);

  b.decode((uint8_t *)"Zm8", strlen("Zm8"), (uint8_t *)decoded,
                    sizeof(decoded));
  EXPECT_TRUE(strncmp(decoded, "fo", 2) == 0);

  b.decode((uint8_t *)"Zm9v", strlen("Zm9v"), (uint8_t *)decoded,
                    sizeof(decoded));
  EXPECT_TRUE(strncmp(decoded, "foo", 3) == 0);

  b.decode((uint8_t *)"Zm9vYg", strlen("Zm9vYg"), (uint8_t *)decoded,
                    sizeof(decoded));
  EXPECT_TRUE(strncmp(decoded, "foob", 4) == 0);

  b.decode((uint8_t *)"Zm9vYmE", strlen("Zm9vYmE"), (uint8_t *)decoded,
                    sizeof(decoded));
  EXPECT_TRUE(strncmp(decoded, "fooba", 5) == 0);

  b.decode((uint8_t *)"Zm9vYmFy", strlen("Zm9vYmFy"),
                    (uint8_t *)decoded, sizeof(decoded));
  EXPECT_TRUE(strncmp(decoded, "foobar", 6) == 0);

  b.decode((uint8_t *)"SGVsbG8sIFdvcmxkIQ",
                    strlen("SGVsbG8sIFdvcmxkIQ"), (uint8_t *)decoded,
                    sizeof(decoded));

  EXPECT_TRUE(strncmp(decoded, "Hello, World!", 13) == 0);
}

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
