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