# Exercise Notes
## Chapter 1
### Exercise 1-2
- When `printf()`'s argument string contains `\c`, the compiler gives a warning stating that `\c` is an *unknown* escape sequence.
- When the programme is executed, it prints `c` in place of `\c`, seemingly ignoring the `\`.

### Exercise 1-9
- A character is printed on two conditions, of which at least one must be true.
	- Character is not a blank.
	- The previous character was not a blank.
- If either of these conditions is `true`, then the character is printed.
- If both conditions are `false`, then the character is not printed.
- The rationale is that,
	- Any character that is **not** a blank should be printed (first condition).
	- If a blank should be printed, it should be ensured that it is essential to separate words, and is not an extra blank (second condition).
	- Under no circumstances should a blank be printed when the previous character printed was a blank itself.

### Exercise 1-18
- Everything from the end of the string that is a **whitespace** character is replaced by a null character (`\0`).
- When a **non-whitespace** character is found, the function is **returned**.
- Before returning, however, a **newline** character is added to the end of the string to preserve the same formatting as the original string.
	- To add the newline, the programme ensures that the character next to the last non-whitespace character is **not** the terminating character (last character of string which is `\0`).
	- The reason is that if it was the terminating character, replacing it with a newline would leave the string with **no** terminating null character.

### Exercise 1-19
- The terminating null character (`\0`) is ignored when reversing.
- If the string contains a newline before the null character, it is ignored as well.
	- Otherwise, reversing the string would put the newline at the front, leaving a blank line before the string, and with no newline after.
- Both the newline and the null character are added at the end of the string after the reversing of other characters is done.
	- Note that a newline is only added if one was present in the original string in the first place.

### Exercise 1-20
- Once a tab (`\t`) has been identified in the **original string** (`srcIdx`), the **position in the destination string** (`destIdx`) is used to figure out the **position of the next tabstop** (`nextTabstop`). Then that result is used to calculate the **required number of spaces** (`requiredSpaces`) to reach that tabstop position.
	- `nextTabstop = ((destIdx + tabstop) / tabstop) * tabstop;`
	- `requiredSpaces = nextTabstop - destIdx;`