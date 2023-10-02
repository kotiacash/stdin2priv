#include <iostream>
#include <string>
#include <openssl/sha.h>

int main() {
    std::string input;

    while (true) {
        // Leggi una riga da stdin
        if (!std::getline(std::cin, input)) {
            // Se l'input è finito o si è verificato un errore, esci dal ciclo
            break;
        }

        // Calcola la chiave privata utilizzando SHA-256
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, input.c_str(), input.length());
        SHA256_Final(hash, &sha256);

        // Converti l'hash in una rappresentazione esadecimale
        char chiave_privata_hex[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            snprintf(&chiave_privata_hex[i * 2], 3, "%02x", hash[i]);
        }

        // Stampa l'hash esadecimale risultante
        std::cout << chiave_privata_hex << std::endl;
    }

    return 0;
}
