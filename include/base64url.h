#ifndef __BASE64URL_H__
#define __BASE64URL_H__

#include <stddef.h>
#include <stdint.h>

namespace base64url {

#if BUILD_TEST
bool invalid_char(char c);
size_t __encoded_size(size_t decoded_length);
size_t __decoded_size(size_t encoded_length);
#endif
size_t encode(const uint8_t *decoded, size_t decoded_length, uint8_t *encoded,
              size_t encoded_length);

size_t decode(const uint8_t *encoded, size_t encoded_length, uint8_t *decoded,
              size_t decoded_length);

} // namespace base64url
#endif /*__BASE64URL_H__*/
