# CIS-165 Lab 8: Geometry Calculator
## Plan

I’ll read one menu choice and use a `switch` to handle it. The program will ask for only the dimensions needed for that choice. I’ll use `PI` for the circle, multiply length and width for the rectangle, and multiply base by height and `0.5` for the triangle. Each area will be saved in `area` before it is displayed. I’ll reject negative dimensions, allow zero, print an error for other menu numbers, and let choice 4 quit without asking for dimensions.

## Compile and run

From this folder, compile the program with:

```sh
g++ -std=c++17 -Wall -Wextra geometry.cpp -o geometry
```

Then run it with:

```sh
./geometry
```

Choose one menu item. The program handles that choice and then ends.

## Test records

The expected results were calculated before the runs. The final source compiled with the command above and produced no warnings or errors. Each test supplied its inputs through standard input. The actual output column shows the result or error line printed after the menu and prompts.

| Input | Expected result | Actual output | Match |
| --- | --- | --- | --- |
| Choice `1`, radius `2` | Area `12.56636` | `Circle area: 12.5664` (default display rounding) | Yes |
| Choice `2`, length `5`, width `3` | Area `15` | `Rectangle area: 15` | Yes |
| Choice `3`, base `4`, height `3` | Area `6` | `Triangle area: 6` | Yes |
| Choice `1`, radius `0` | Area `0` | `Circle area: 0` | Yes |
| Choice `1`, radius `-2` | Negative-radius error; no area | `Error: radius cannot be negative.` | Yes |
| Choice `2`, length `-5`, width `3` | Negative-dimension error; no area | `Error: length and width cannot be negative.` | Yes |
| Choice `2`, length `5`, width `-3` | Negative-dimension error; no area | `Error: length and width cannot be negative.` | Yes |
| Choice `3`, base `-4`, height `3` | Negative-dimension error; no area | `Error: base and height cannot be negative.` | Yes |
| Choice `3`, base `4`, height `-3` | Negative-dimension error; no area | `Error: base and height cannot be negative.` | Yes |
| Choice `9` | Invalid-choice error | `Error: choice must be between 1 and 4.` | Yes |
| Choice `4` | End without asking for dimensions or calculating an area | `Goodbye.` | Yes |

Temporary test changes restored: none. The inputs were supplied through standard input, and the source was not changed for individual tests.

## Explanation

The `switch` compares `choice` with each `case`. A matching case runs its calculation, and `break` stops that case from falling through to the next one. `default` handles a number that does not match choices 1 through 4.

`radius * radius` multiplies the radius by itself. In C++, `^` is a bitwise XOR operator, not an exponent operator.

The triangle formula uses `0.5` so the multiplication uses a floating-point value. With integer arithmetic, `1 / 2` would evaluate to `0` before it was multiplied by the dimensions.

Each case checks its dimensions for negative values before calculating the area. Zero passes the check and gives an area of zero. Choice 4 only prints a goodbye message, then exits the switch without asking for dimensions or calculating an area.

## Course reference

The menu and `switch` structure follow the geometry calculator exercise and Section 4.12 in Tony Gaddis et al., *Starting Out with C++: Early Objects*, 10th edition. The circle formula is also shown in the book's Chapter 3 examples.
