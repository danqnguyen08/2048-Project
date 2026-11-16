# CS211 Group Project: 2048 and Luhn

**Session/Group:** MW, Group 22

**Members (GitHub usernames):**
- Dan Nguyen / danqnguyen08 
- Alex Nguyen / alxxnguyen

## Repository URL
https://github.com/danqnguyen08/2048-Project.git
## Program Summaries

**2048 (game2048/)**: A coded version of the 2048 puzzle game on a 5x5 board. The player slides tiles up, down, left, or right. Equal tiles merge and add to the score, and a new tile appears after each successful move. The game can be saved to and loaded from a text file, and it ends when no moves are left.

**Luhn validation (luhn/)**: A separate console program that checks whether a 16-digit number passes the Luhn checksum. It rejects badly formatted input (wrong length, letters, spaces) and lets the user check several numbers in one run.

## Task plan

- Set up the repository and folders (this PR)
- Left movement for 2048, then right, up and down
- Game controls, scoring, and win/game-over behavior
- Save and load
- Luhn program
- Final tests, report, and documentation

## 2048 game controls

| Command | Purpose |
|---|---|
| `u` | Move tiles up |
| `d` | Move tiles down |
| `l` | Move tiles left |
| `r` | Move tiles right |
| `s` | Save the current game |
| `o` | Open / load the saved game |
| `n` | Start a new game, with confirmation |
| `h` | Display help |
| `e` | Exit |

When two equal tiles merge, the new tile's value is added to the score. A slide without a merge can still be a successful move. If the board does not change, the game does not count a move or add a new tile. Game over occurs only if there are no empty cells and no horizontal or vertical equal neighbors.

### Saving and loading

- Enter `s` to save to **`savegame.txt`** in the *current working directory*. Saving again overwrites this single slot.
- Enter `o` to load from the same file. A valid save contains the marker `CS211_2048_V1`, the score and successful-move count, and five rows of five integers.
- Loading must validate the entire file before replacing the current board and counters. A missing, incomplete, or malformed file must produce an error and preserve the active game.
- Loading does not count a move or insert a tile. Random generator state is not preserved.
- The submission includes a separate example `sample_save.txt`; it is not automatically loaded by the `o` command unless copied/renamed to `savegame.txt` in the working directory.

## Luhn usage

1. Run `luhn_app` and enter a 16-digit number (digits `0`-`9` only; no spaces or punctuation).
2. The program reports invalid format, checksum pass, or checksum fail as distinct outcomes.
3. Enter another number to repeat, or `q` to quit (if using the group's current implementation).

Examples: `4532015112830366` passes; `4532015112830367` fails; `0000000000000018` is accepted with its leading zeros.

# Known limitations and pre-submission checks

- **Confirm tile insertion is always `2`:** an earlier uploaded revision of `2048_helper.h` randomly inserted `2` *or* `4`, which does not meet this assignment's rule.
- **Confirm final source organization:** an earlier revision put helper implementations in `2048_helper.h`. The final package requires include guards, declarations in headers, and implementations in `.cpp` files.
- **Confirm actual input behavior:** test overlong and malformed saves, game-over controls, and Luhn EOF handling. Record results in `tests.md`.
- **No graphical interface:** both applications are text-based by assignment design.