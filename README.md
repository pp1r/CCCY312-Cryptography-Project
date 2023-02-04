# CCCY 312 – Cryptography Project
## By:  SULAIMAN & SARI

## Introduction:
Cryptography is the study of secure communication in the presence of outside parties, often known as adversaries. The focus is on developing and examining protocols that prevent malicious third parties from accessing information shared between two entities. In this project, we focused on using an encryption technique that ensures confidentiality, confusion, and diffusion by converting ordinary text into cipher text.

## Convertors:
The project contains a few converters that are ready to use in case the function requires data in binary, decimal, or hexadecimal format:

`binaryToDecimal():` To change the value of Binary to Decimal.

`DecimalToBinary():` To change the value of Decimal to Binary.

`HexTobin():` To change the value of Hexa Decimal to Binary.

`convertBinToHex():` To change the value of Binary to Hexa Decimal.

### Tables:
*Tables are used to implement the function. These are static and their values should not be changed to run the function:*

`Hex:` Used to read the integer in hexadecimal.

`Binary reader` table: Used to read the value in Binary.

`S-Box table:` A set of numbers that are arranged in a specific way to substitute a given binary.

`Initial permutation table:` A setting table used for substitution.

### Function:
*The following functions are used to achieve the desired encryption:*

`ip_key():` Initial Permutation. Used for both encryption and decryption. Changes the order of the bits in a prescribed manner.

`S-Box(),` `s_boxkey()`: S-Box. Used for encryption. Substitutes the relationship between the key and the ciphertext.

`s_boxinv()`: Inversed S-Box. Used for decryption.

`xor()`: eXclusive OR. Used for both encryption and decryption. Compares two input bits and generates one output bit.


The encryption process is as follows:

The string `plaintext` stores the text written in (Plain.txt).

This value of hexadecimal will be used in the S-Box function.

The `S_box()` function takes the value of `plaintext` and implements it in a 16 x 16 S-Box. The result is stored in the string `sub`.

The hexadecimal value of `sub` is converted to binary using the `HexToBin()` function and stored back in `plaintext`.

The key entered by the user is in hexadecimal. To implement the initial permutation, it must be converted to binary using the `HexToBin()` function.

The `s_boxkey()` function, a S-Box function, uses the value of `key` to increase the complexity of the encryption method.

It also uses the `dectobin()` function to convert from decimal to binary to implement the S-Box.
 
The result is stored in the string `generatedKey`.

Both `generatedKey` and `plaintext` are set to the `xor()` function, and the result is stored in the string `xored`.

The final encrypted value is stored in `ciphertext`.

The decryption process is implemented in the `Decrypt.cpp` file.

### Conclusion
In conclusion, the cryptography project was focused on creating a secure communication method by using an encryption technique that ensures confidentiality, confusion, and diffusion. We used a few functions, tables, and converters to convert the plaintext into ciphertext. The project was implemented using C++, and the encryption was done using the Initial Permutation, S-Box, and XOR functions. Our method is strong enough to protect the data from outside adversaries, ensuring that the data transmitted remains secure. The project was a great learning experience for us as we were able to understand the importance of cryptography in secure communication and how to implement it effectively.
