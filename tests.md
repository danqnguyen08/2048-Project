# CS211 Group Project — Test Results


## Part A — 2048 Movement Tests

| Test | Starting board / action | Expected result | Actual result | Status |
|---|---|---|---|---|
| A01: Left through gaps | Row `[0,2,0,2,0]`, left | `[4,0,0,0,0]`, +4 score | `[4,0,0,0,0]`, +4 | PASS |
| A02: Three equal tiles | Row `[2,2,2,0,0]`, left | `[4,2,0,0,0]`, +4 | `[4,2,0,0,0]`, +4 | PASS |
| A03: Four equal tiles | Row `[2,2,2,2,0]`, left | `[4,4,0,0,0]`, +8 | `[4,4,0,0,0]`, +8 | PASS |
| A04: Five equal tiles | Row `[2,2,2,2,2]`, left | `[4,4,2,0,0]`, +8 | `[4,4,2,0,0]`, +8 | PASS |
| A05: Two merges | Row `[4,4,8,8,0]`, left | `[8,16,0,0,0]`, +24 | `[8,16,0,0,0]`, +24 | PASS |
| A06: Move right | Row `[2,2,2,0,0]`, right | `[0,0,0,2,4]`, +4 | `[0,0,0,2,4]`, +4 | PASS |
| A07: Move up through gaps | Column `[0,2,0,2,0]`, up | `[4,0,0,0,0]`, +4 | `[4,0,0,0,0]`, +4 | PASS |
| A08: Move down through gaps | Column `[2,0,2,0,0]`, down | `[0,0,0,0,4]`, +4 | `[0,0,0,0,4]`, +4 | PASS |
| A09: Unchanged move | Row `[2,4,8,0,0]`, left | Unchanged, +0 | Unchanged, +0 | PASS |
| A10: Slide with no merge | Row `[2,0,4,0,0]`, left | `[2,4,0,0,0]`, +0 | `[2,4,0,0,0]`, +0 | PASS |
| A11: Reach 2048 | Row `[1024,1024,0,0,0]`, left | `[2048,0,0,0,0]`, +2048 | `[2048,0,0,0,0]`, +2048 | PASS |
| A12: Full board with merge | Full board shown below, two adjacent `2`s | Not game over | `is_game_over()` returned false | PASS |
| A13: Full board without merge | Alternating `2`/`4` full board below | Game over | `is_game_over()` returned true | PASS |
| A14: Starting tiles | 200 new games | Every board starts with exactly two `2` tiles | 153 of 200 games did not have two `2` tiles | FAIL |
| A15: Number of inserted tiles | 200 insertions into board with one existing tile | Exactly one additional tile each time | 0 cases inserted the wrong number of tiles | PASS |
| A16: Value of inserted tile | 200 insertions into board with one existing tile | Every new tile is `2` | 99 inserted tiles were `4` | FAIL |
| A17: Unchanged move counters | `[2,4,8,0,0]`, left | No board change and no move counted | Board equality check true; gained 0 | PASS |
| A18: Slide counted as move | `[2,0,4,0,0]`, left | Board changes, move counted, +0 score | Board equality check false; gained 0 | PASS |

### Full board used for A12 (merge available)

```text
2 2 2 4 2
4 2 4 2 4
2 4 2 4 2
4 2 4 2 4
2 4 2 4 2
```

### Full board used for A13 (no available moves)

```text
2 4 2 4 2
4 2 4 2 4
2 4 2 4 2
4 2 4 2 4
2 4 2 4 2
```

## Part A — Save and Load Tests

The save/load test board contained tiles of `2`, `4`, `8`, and `16`. The saved score was `18` and successful-move count was `7`. Failed loads were checked to make sure the active board, score, and moves remained unchanged.

| Test | Expected result | Actual result | Status |
|---|---|---|---|
| S01: Save format | Correct marker, counters, 25 cells | Exact required format written | PASS |
| S02: Save/change/load | Original board, score 18, moves 7 restored | Exact board restored; score 18; moves 7 | PASS |
| S03: Missing save | Reject and preserve current game | Rejected; state preserved | PASS |
| S04: Wrong version marker | Reject and preserve state | Rejected; state preserved | PASS |
| S05: Invalid tile `3` | Reject and preserve state | Rejected; state preserved | PASS |
| S06: Only 24 tile values | Reject and preserve state | Rejected; state preserved | PASS |
| S07: Extra number after board | Reject and preserve state | Rejected; state preserved | PASS |
| S08: Negative score | Reject and preserve state | Rejected; state preserved | PASS |
| S09: Negative move count | Reject and preserve state | Rejected; state preserved | PASS |
| S10: Non-numeric counter | Reject and preserve state | Rejected; state preserved | PASS |
| S11: Out-of-range counter | Reject and preserve state | Rejected; state preserved | PASS |
| S12: Negative tile | Reject and preserve state | Rejected; state preserved | PASS |
| S13: Tile value `1` | Reject and preserve state | Rejected; state preserved | PASS |
| S14: Tile not a power of two | Reject and preserve state | Rejected; state preserved | PASS |
| S15: Extra text after board | Reject and preserve state | Rejected; state preserved | PASS |
| S16: Trailing whitespace | Accept otherwise valid file | Loaded successfully; score 12, moves 4 | PASS |
| S17: Save again | Replace previous save | Previous save replaced | PASS |
| S18: Cannot open output file | Report saving failure | `save_game()` returned false | PASS |

## Part A — Game Controls and Interaction

| Test | Expected result | Actual result | Status |
|---|---|---|---|
| G01: Help and invalid command | Help shown; invalid command rejected; no state change | Help and error displayed; state unchanged | PASS |
| G02: Cancel new game | Current game preserved | Cancellation displayed; no reset | PASS |
| G03: Confirm new game | Game restarts; score and moves reset | New game displayed; moves 0 | PASS |
| G04: Exit with `e` | Clean exit | `Goodbye.` displayed | PASS |
| G05: End of input | Clean exit | Program exited | PASS |
| G06: Load missing file | Error displayed | Missing-file error displayed | PASS |
| G07: Save and load commands | `s` saves and `o` loads | Both commands accepted | PASS |
| G08: Successful slide without merge | Moves +1, score unchanged | Moves 1, score 0 | PASS |
| G09: Unchanged move | Moves stays at 0 | Moves remained 0 | PASS |
| G10: Win announcement | 2048 reached, score +2048 | Win message and score 2048 | PASS |
| G11: Game-over controls | Block movement; allow save/help/exit | Movement blocked; other commands worked | PASS |
| G12: Full board with legal merge | Movement still allowed | Moved; score changed from 12 to 16 | PASS |

## Part B — Luhn Validation Tests

| Test | Input / action | Expected result | Actual result | Status |
|---|---|---|---|---|
| L01: Valid checksum | `4532015112830366` | Pass | `Luhn checksum PASSED!` | PASS |
| L02: Invalid checksum | `4532015112830367` | Fail | `Luhn checksum FAILED!` | PASS |
| L03: Leading zeros | `0000000000000018` | Pass | `Luhn checksum PASSED!` | PASS |
| L04: Too short | `453201511283036` | Reject format | `Invalid input.` | PASS |
| L05: Too long | `45320151128303666` | Reject format | `Invalid input.` | PASS |
| L06: Letter | `453201511283036X` | Reject format | `Invalid input.` | PASS |
| L07: Internal space | `45320151 12830366` | Reject format | `Invalid input.` | PASS |
| L08: Multiple checks | Pass, fail, pass, then `q` | Three results and clean exit | Two passes, one fail, then exited | PASS |
| L09: End of input | Clean exit | Exited normally | PASS |
| L10: Very long input | Reject 130 digits, accept next valid line | Invalid input then successful check | Rejected, then passed next number | PASS |
| L11: Quit | Enter `q` | Program exits | `Goodbye!` displayed | PASS |
