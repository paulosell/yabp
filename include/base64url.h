#ifndef __BASE64URL_H__
#define __BASE64URL_H__

#include <stddef.h>
#include <stdint.h>

namespace base64url {

#ifdef BUILD_TEST
bool invalid_char(char c);
size_t __encoded_size(size_t decoded_length);
size_t __decoded_size(size_t encoded_length);
#endif

/**
 * @brief Encode binary data into Base64 format.
 *
 * This function takes binary data as input and encodes it into Base64 format.
 *
 * @param decoded Pointer to the binary data buffer to be encoded.
 * @param decoded_length Length of the binary data buffer.
 * @param encoded Pointer to the buffer where the Base64-encoded output will be
 * stored.
 * @param encoded_length Length of the buffer allocated for the encoded output.
 * @return If successful, returns the size of the encoded data (excluding the
 * null terminator). If the encoded data is larger than the allocated buffer, if
 * the input is empty, or if the input pointer is nullptr, returns -1.
 */
size_t encode(const uint8_t *decoded, size_t decoded_length, uint8_t *encoded,
              size_t encoded_length);

/**
 * @brief Decode a Base64-encoded input to its original binary representation.
 *
 * This function takes a Base64-encoded input and decodes it into its original
 * binary form.
 *
 * @param encoded Pointer to the Base64-encoded input buffer.
 * @param encoded_length Length of the Base64-encoded input buffer.
 * @param decoded Pointer to the buffer where the decoded output will be stored.
 * @param decoded_length Length of the buffer allocated for the decoded output.
 * @return If successful, returns the size of the decoded data. If the decoded
 * data is larger than the allocated buffer or if the input is invalid, returns
 * -1.
 */
size_t decode(const uint8_t *encoded, size_t encoded_length, uint8_t *decoded,
              size_t decoded_length);

} // namespace base64url
#endif /*__BASE64URL_H__*/
