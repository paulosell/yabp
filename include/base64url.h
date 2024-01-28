#ifndef __BASE64URL_H__
#define __BASE64URL_H__

#include <stddef.h>
#include <stdint.h>
#include "base64url_util.h"

namespace Base64Url {

class Base64Url {

  Base64UrlUtil b;

public:
  Base64Url(){};
  ~Base64Url(){};

  /**
  * @brief Encode binary data into Base64Url format.
  *
  * This function takes binary data as input and encodes it into Base64Url format.
  *
  * @param decoded Pointer to the binary data buffer to be encoded.
  * @param decoded_length Length of the binary data buffer.
  * @param encoded Pointer to the buffer where the Base64Url-encoded output will be
  * stored.
  * @param encoded_length Length of the buffer allocated for the encoded output.
  * @return If successful, returns the size of the encoded data (excluding the
  * null terminator). If the encoded data is larger than the allocated buffer, if
  * the input is empty, or if the input pointer is nullptr, returns -1.
  */
  size_t encode(const uint8_t *decoded, size_t decoded_length, uint8_t *encoded,
                size_t encoded_length);

  /**
  * @brief Decode a Base64Url-encoded input to its original binary representation.
  *
  * This function takes a Base64Url-encoded input and decodes it into its original
  * binary form.
  *
  * @param encoded Pointer to the Base64Url-encoded input buffer.
  * @param encoded_length Length of the Base64Url-encoded input buffer.
  * @param decoded Pointer to the buffer where the decoded output will be stored.
  * @param decoded_length Length of the buffer allocated for the decoded output.
  * @return If successful, returns the size of the decoded data. If the decoded
  * data is larger than the allocated buffer or if the input is invalid, returns
  * -1.
  */
  size_t decode(const uint8_t *encoded, size_t encoded_length, uint8_t *decoded,
                size_t decoded_length);    
  
};



} // namespace Base64Url
#endif /*__BASE64URL_H__*/
