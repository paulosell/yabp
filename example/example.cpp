#include "../include/base64url.h"
#include <iostream>
#include <string.h>

int main() {
  char encoded[32];
  char decoded[16];
  char hello_world_decoded[] = "Hello, World!";
  char hello_world_encoded[] = "SGVsbG8sIFdvcmxkIQ";

  base64url::encode(reinterpret_cast<uint8_t *>(hello_world_decoded),
                    strlen(hello_world_decoded),
                    reinterpret_cast<uint8_t *>(encoded), sizeof(encoded));
  std::cout << "Hello, World! encoded to Base64URL: ";
  std::cout << encoded << '\n';

  base64url::decode(reinterpret_cast<uint8_t *>(hello_world_encoded),
                    strlen(hello_world_encoded),
                    reinterpret_cast<uint8_t *>(decoded), sizeof(decoded));
  std::cout << "SGVsbG8sIFdvcmxkIQ decoded from Base64URL: ";
  std::cout << decoded << '\n';
}
