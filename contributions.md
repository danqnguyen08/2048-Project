# CS211 Group Project — Contributions

**Project:** 2048 Game and Luhn Checksum Validation  
**Course / section:** CS211 — MW  
**Group:** 22  

## Group Members

| Group member | GitHub username | Work described in our project discussion |
|---|---|---|
| [Dan Nguyen] | `dangnguyen08` | Check points 1-3 |
| [Alex Nguyen] | `alxxnguyen` | Checkpoints 4–6 |

## Project Responsibilities

### Checkpoints 1–3 — Project Setup and 2048 Game

 Dan Nguyen

- Set up the shared GitHub repository and initial project folders.
- Added the 2048 starter files and group project plan.
- Implemented the 2048 movement functions: `move_left()`, `move_right()`, `move_up()`, and `move_down()`.
- Implemented game features, including board display, merging, scoring, move counting, controls, new game, and game-over checks.
- Prepared the initial repository README and Luhn implementation plan.

**Review/testing contribution:** [Describe exactly what the other member tested or reviewed; include PR link and comment if available.]

### Checkpoint 4 — 2048 Save and Load

Alex Nguyen

- Added `valid_tile()` to check saved board values.
- Added `save_game()` to write the version marker, score, successful-move count, and 25 board cells into `savegame.txt`.
- Added `load_game()` to verify the saved data before restoring the game.
- Updated `game2048/main.cpp` with `s` (save) and `o` (open/load) commands and related help text.
- Compiled the updated game, launched it, and checked basic save/load behavior.
- Submitted the `feature/save-load` branch for review.

### Checkpoint 5 — Luhn Validation

Alex Nguyen

- Created the separate Luhn console program in `luhn/main.cpp`, `luhn.cpp`, and `luhn.h`.
- Wrote `validInput()` to reject entries that are not exactly 16 digits.
- Wrote `checkLuhn()` to double every second digit from the right, subtract 9 when needed, add transformed digits, and check whether the sum is divisible by 10.
- Added repeated input, an exit option, and messages that distinguish malformed input from a failed checksum.
- Compiled and tested the Luhn program; detailed automated results are recorded in `tests.md` and must be verified against the final submitted code.

### Checkpoint 6 — Final Documentation and Packaging

Alex Nguyen

- Prepared or updated the project `README.md` with program descriptions, controls, save/load behavior, and build/run commands.
- Prepared `tests.md` with starting inputs, expected results, actual results, and PASS/FAIL records for both programs.
- Prepared `report.pdf` with program design explanations, a 2048 dry run, a Luhn dry-run table, a Luhn flowchart, and a function workflow diagram.
- Prepared `contributions.md` with member responsibilities, PR history, reviews, and tools used.
- Added `game2048/sample_save.txt` and checked that it follows the required format.

## Pull Request Record

| Checkpoint | Branch | PR link | Author | Reviewer | Merger | Status |
|---|---|---|---|---|---|---|
| 1: Setup | `setup/project-plan` | [https://github.com/danqnguyen08/2048-Project/pull/1] | [Dan] | [Alex] | [Alex] | [Merged] |
| 2: Left move | `feature/move-left` | [https://github.com/danqnguyen08/2048-Project/pull/2] | [Dan] | [Alex] | [Alex] | [Merged] |
| 3: Other directions | `feature/other-directions` | [https://github.com/danqnguyen08/2048-Project/pull/3] | [Dan] | [Alex] | [Alex] | [Merged] |
| 4: Add Score, move counter, and tile insertion | `feature/score,move-counter,tile-insertion` | [https://github.com/danqnguyen08/2048-Project/pull/4] | [Dan] | [Alex] | [Alex] | [Merged] |
| 4: Feature/menu-gameover | `feature/menu-gameover` | [https://github.com/danqnguyen08/2048-Project/pull/5] | [Dan] | [Alex] | [Alex] | [Merged] |
| 5: Save/load | `save/load` | [https://github.com/danqnguyen08/2048-Project/pull/6] | [Alex] | [Dan] | [Dan] | [Merged] |
| 6: Luhn | `feature/luhn` | [https://github.com/danqnguyen08/2048-Project/pull/7] | [Alex] | [Dan] | [Dan] | [Merged] |
| 7: Final package | `docs/final-package` | | [Alex] | [Dan] | [Dan] |

