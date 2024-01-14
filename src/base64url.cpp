#include <cctype>
#include <iostream>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

namespace base64url {

static constexpr char encoding_alphabet[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '_'};

static constexpr char decoding_alphabet[] = {
    62, -1, -1, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1,
    -1, -1, -1, -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1,
    -1, -1, 63, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1};

size_t __encoded_size(size_t decoded_length) {
  return ceil((float)decoded_length * 4 / 3);
}

size_t __decoded_size(size_t encoded_length) {
  return floor(encoded_length * 6) / 8;
}

bool invalid_char(char c) {

  if (c == '-' || c == '_') return false;

  if (std::isalnum(c)) return false;

  return true;
}

static bool invalid_encoded(const uint8_t *encoded, size_t encoded_length) {

  int i;

  for (i = 0; (size_t)i < encoded_length; i++) {
    if (invalid_char(encoded[i])) return true;
  }

  return false;
}

size_t encode(const uint8_t *decoded, size_t decoded_length, uint8_t *encoded,
              size_t encoded_length) {
  size_t encoded_size;
  int i, j;

  encoded_size = __encoded_size(decoded_length);

  if (encoded_size > encoded_length) return -1;

  if (decoded_length == 0) return -1;

  if (decoded == nullptr) return -1;

  for (i = 0, j = 0; (size_t)i < decoded_length; i += 3, j += 4) {

    uint32_t pos = decoded[i] << 16 |
                   ((size_t)i + 1 < decoded_length ? decoded[i + 1] << 8 : 0) |
                   ((size_t)i + 2 < decoded_length ? decoded[i + 2] : 0);

    encoded[j] = encoding_alphabet[(pos >> 18) & 0x3F];
    encoded[j + 1] = encoding_alphabet[(pos >> 12) & 0x3F];
    encoded[j + 2] = ((size_t)i + 1 < decoded_length)
                         ? encoding_alphabet[(pos >> 6) & 0x3F]
                         : encoded[j + 2];
    encoded[j + 3] = ((size_t)i + 2 < decoded_length)
                         ? encoding_alphabet[pos & 0x3F]
                         : encoded[j + 3];
  }

  encoded[encoded_size] = '\0';

  return strlen(reinterpret_cast<const char *>(encoded));
}

size_t decode(const uint8_t *encoded, size_t encoded_length, uint8_t *decoded,
              size_t decoded_length) {

  size_t decoded_size;
  int i, j;

  decoded_size = __decoded_size(encoded_length);

  if (decoded_size > decoded_length) return -1;

  if (encoded == nullptr) return -1;

  if (invalid_encoded(encoded, encoded_length)) return -1;

  for (i = 0, j = 0; (size_t)i < encoded_length; i += 4, j += 3) {

    uint32_t pos = decoding_alphabet[encoded[i] - 45];
    uint32_t k = 1;

    if ((size_t)(i + 1) < encoded_length) {
      pos = (pos << 6) | decoding_alphabet[encoded[i + 1] - 45];
      k++;
    }
    if ((size_t)(i + 2) < encoded_length) {
      pos = (pos << 6) | decoding_alphabet[encoded[i + 2] - 45];
      k++;
    }
    if ((size_t)(i + 3) < encoded_length) {
      pos = (pos << 6) | decoding_alphabet[encoded[i + 3] - 45];
      k++;
    }

    switch (k) {
    case 1:
      decoded[j] = pos;
      break;
    case 2:
      decoded[j] = pos >> 4;
      break;
    case 3:
      decoded[j] = pos >> 10;
      decoded[j + 1] = (pos >> 2) & 0xFF;
      break;
    case 4:
      decoded[j] = pos >> 16;
      decoded[j + 1] = (pos >> 8) & 0xFF;
      decoded[j + 2] = pos & 0xFF;
    }
  }

  return decoded_size;
}
} // namespace base64url
