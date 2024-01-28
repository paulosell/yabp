#include <cctype>
#include <math.h>
#include "base64url_util.h"

namespace Base64Url {

bool Base64UrlUtil::invalid_char(char c){
  if (c == '-' || c == '_') return false;

  if (std::isalnum(c)) return false;

  return true;
}

bool Base64UrlUtil::invalid_encoded(const uint8_t *encoded, size_t encoded_length) {

  int i;

  for (i = 0; (size_t)i < encoded_length; i++) {
    if (this->invalid_char(encoded[i])) return true;
  }

  return false;
}

size_t Base64UrlUtil::encoded_size(size_t decoded_length) {
  return ceil((float)decoded_length * 4 / 3);
}

size_t Base64UrlUtil::decoded_size(size_t encoded_length) {
  return floor(encoded_length * 6) / 8;
}
} // namespace Base64Url
