Bitwise operators in C are operators that perform operations on the individual bits of integer operands. They are commonly used in low-level programming, device driver development, and embedded systems programming. Here's an overview of bitwise operators in C:

1. **Bitwise AND (`&`)**:
   - Performs a bitwise AND operation on each pair of corresponding bits. The result is 1 if both bits are 1; otherwise, it's 0.

2. **Bitwise OR (`|`)**:
   - Performs a bitwise OR operation on each pair of corresponding bits. The result is 1 if either of the bits is 1; otherwise, it's 0.

3. **Bitwise XOR (`^`)**:
   - Performs a bitwise XOR (exclusive OR) operation on each pair of corresponding bits. The result is 1 if the bits are different; otherwise, it's 0.

4. **Bitwise NOT (`~`)**:
   - Performs a bitwise NOT operation on each bit, flipping 1s to 0s and 0s to 1s.

5. **Left Shift (`<<`)**:
   - Shifts the bits of the left operand to the left by the number of positions specified by the right operand. It's equivalent to multiplying the left operand by 2 raised to the power of the right operand.

6. **Right Shift (`>>`)**:
   - Shifts the bits of the left operand to the right by the number of positions specified by the right operand. For unsigned integers, it fills the leftmost positions with 0s. For signed integers, the behavior depends on the implementation-defined sign extension.

Advanced Usage:

1. **Bit Manipulation**:
   - Bitwise operators can be used to manipulate individual bits within integers. This can be useful for tasks such as setting, clearing, or toggling specific bits within bitfields.

2. **Masking**:
   - Bitwise AND (`&`) is commonly used to mask out specific bits within an integer while preserving others. This is often used in combination with bitwise OR (`|`) to set specific bits to desired values.

3. **Checking for Bit Flags**:
   - Bitwise AND (`&`) can be used to check if specific bits are set within an integer. This is often used in conjunction with bitwise OR (`|`) to set or unset flags within a bitfield.

4. **Arithmetic Operations**:
   - Bitwise operations can sometimes be used to optimize arithmetic operations, especially when dealing with powers of 2. For example, left shifting (`<<`) is equivalent to multiplication by powers of 2, and right shifting (`>>`) is equivalent to division by powers of 2.

Understanding bitwise operators and their advanced usage can greatly enhance your ability to write efficient and compact code, particularly in scenarios where low-level manipulation of binary data is required.
