# Luhn Checksum Validation

A console program that checks whether a 16-digit number passes the Luhn
checksum. This validates the checksum only. A passing number does not mean a
card exists or is authorized for payment.

## Implementation plan

**Input**
- Read the input as a string so leading zeros are kept.
- Accept exactly 16 characters, each a digit from 0 to 9.
- Reject wrong length, letters, punctuation, and spaces inside the number with
  a clear message, then let the user try again.

**Checksum (`checkLuhn`)**
1. Start at the rightmost digit and move left.
2. Leave the first digit unchanged, then double every second digit.
3. If a doubled value is greater than 9, subtract 9 (same as adding its digits).
4. Add up all the values.
5. The number passes if the sum is divisible by 10.

**Program structure**
- `main.cpp`: the menu loop, so the user can check several numbers and exit.
- `luhn.h` / `luhn.cpp`: input-format validation and `checkLuhn`, kept as
  separate functions. The original input string is not modified.

**Interaction**
- Report malformed input differently from a number that is correctly formatted
  but fails the checksum.
- Offer a clear way to exit, and handle end of input cleanly.

## Tests to run

| Input | Expected result |
|---|---|
| 4532015112830366 | Correct format, checksum passes |
| 4532015112830367 | Correct format, checksum fails |
| 0000000000000018 | Correct format, passes (leading zeros kept) |
| 453201511283036 | Rejected: 15 digits |
| 45320151128303666 | Rejected: 17 digits |
| 453201511283036X | Rejected: non-digit |
| A number with a space inside | Rejected: malformed |
| Several checks, then exit | Results correct, exits cleanly |

## Status

Not started. To be completed on the `feature/luhn` branch.
