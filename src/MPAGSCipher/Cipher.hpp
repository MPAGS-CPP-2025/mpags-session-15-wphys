#ifndef CIPHER_HPP
#define CIPHER_HPP

#include "CipherMode.hpp"
#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher class
 */

/**
 * \class Cipher
 * \brief Abstract base class for ciphers, providing a common interface for applying a cipher to text
 */
class Cipher {
  public:
    /**
     * \brief Default constructor and defaulted copy/move constructors and assignment operators
     */
    Cipher() = default;
    Cipher(const Cipher&) = default;
    Cipher(Cipher&&) = default;
    Cipher& operator=(const Cipher&) = default;
    Cipher& operator=(Cipher&&) = default;
    /**
     * \brief Virtual destructor to allow for proper cleanup of derived classes
     */
    virtual ~Cipher() = default;

    /**
     * \brief Pure virtual function to apply the cipher to the provided text
     */
    virtual std::string applyCipher(const std::string& inputText,
                                    const CipherMode mode) const = 0;
};
#endif    // CIPHER_HPP