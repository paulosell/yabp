#ifndef __BASE64URL_UTIL_H__
#define __BASE64URL_UTIL_H__

#include <stddef.h>
#include <stdint.h>

namespace Base64Url {

class Base64UrlUtil{
public:
  Base64UrlUtil(){};
  ~Base64UrlUtil(){};

  /**
  * @brief Checks whether a character is invalid for Base64Url encoding.
  *
  * This function evaluates whether a given character is invalid for Base64Url encoding.
  * It checks if the character is one of the allowed characters ('-' or '_') or if it is an alphanumeric character.
  * If the character is not valid for Base64Url encoding, the function returns true; otherwise, it returns false.
  *
  * @param c The character to be checked for validity in Base64Url encoding.
  * @return true if the character is invalid for Base64Url encoding, false otherwise.
  */
  static bool invalid_char(char c);

  /**
  * @brief Checks if Base64Url-encoded data contains invalid characters.
  *
  * This function iterates through the provided Base64Url-encoded data and checks if any of the characters are invalid.
  * It uses the `invalid_char` function internally to perform the character validation.
  *
  * @param encoded Pointer to the Base64Url-encoded data.
  * @param encoded_length The length of the Base64Url-encoded data (in bytes).
  * @return true if the encoded data contains any invalid characters, false otherwise.
  */
  bool invalid_encoded(const uint8_t *encoded, size_t encoded_length);

  /**
  * @brief Calculates the size of Base64Url-encoded data based on the size of decoded data.
  *
  * This function computes the size required for Base64Url encoding of a given amount of decoded data.
  * It uses the formula ceil((decoded_length * 4) / 3) to determine the size of the resulting encoded data.
  *
  * @param decoded_length The size of the data to be encoded (in bytes).
  * @return The calculated size needed for the Base64Url-encoded data.
  */
  static size_t encoded_size(size_t decoded_length);

  /**
  * @brief Calculates the size of Base64Url-decoded data based on the size of encoded data.
  *
  * This function computes the size required for Base64Url decoding of a given amount of encoded data.
  * It uses the formula floor((encoded_length * 6) / 8) to determine the size of the resulting decoded data.
  *
  * @param encoded_length The size of the data to be decoded (in bytes).
  * @return The calculated size needed for the Base64Url-decoded data.
  */
  static size_t decoded_size(size_t encoded_length);
};

}// namespace Base64Url
#endif /*__BASE64URL_UTIL_H__*/

