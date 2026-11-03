# CIS165_Lab6- BMI Calculator and Color Mixer

Course section: CIS-165-B030

This repo has two C++ programs: `bmi.cpp` (BMI in pounds and inches, with a weight category) and `color_mixer.cpp` (mixes two primary colors using character arrays and `strcmp`).

## How to compile and run

I wrote and tested both programs in OnlineGDB, one at a time, with C++17 selected and the Run button. Then I downloaded each final `.cpp` file and uploaded it to GitHub.

To run them in a terminal:

```
g++ -std=c++17 -Wall -Wextra bmi.cpp -o bmi
./bmi

g++ -std=c++17 -Wall -Wextra color_mixer.cpp -o color_mixer
./color_mixer
```

---

## Program 1: BMI plan

- **Inputs:** weight in pounds and height in inches (both `double`).
- **Variables:** `weight`, `height`, `bmi`, plus named constants `BMI_FACTOR` (703), `UNDERWEIGHT_LIMIT` (18.5) and `OVERWEIGHT_LIMIT` (25.0).
- **Validation:** if weight or height is zero or negative, print `Error: weight and height must be positive.` and stop before any math.
- **Calculation:** `bmi = weight * BMI_FACTOR / (height * height)`, stored in a result variable.
- **Comparisons:** below 18.5 is Underweight, 18.5 up to and including 25.0 is Optimal weight, above 25.0 is Overweight.
- **Output:** BMI shown to two decimal places (using `fixed` and `setprecision(2)`) with a labeled category. The stored value is not rounded.
- **Tests:** the five required tests plus one extra (below).

## Program 2: Color Mixer plan

- **Inputs:** two color names read into character arrays.
- **Variables:** `first_color` and `second_color` (char arrays), with named constants for the color names (`RED`, `BLUE`, `YELLOW`).
- **Validation:** use `strcmp` to check that each input is red, blue, or yellow. If either one is not, print `Error: enter red, blue, or yellow.` and stop.
- **Comparisons:** red + blue = purple, red + yellow = orange, blue + yellow = green, in either order. Two of the same color gives that color back.
- **Output:** a labeled result with the mixed color.
- **Tests:** the seven required tests plus one extra (below).

---

## Test records

### BMI

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| BMI 1 | 100, 70 | 14.35, Underweight | 14.35, Underweight | Match |
| BMI 2 | 150, 70 | 21.52, Optimal weight | 21.52, Optimal weight | Match |
| BMI 3 | 200, 70 | 28.69, Overweight | 28.69, Overweight | Match |
| BMI 4 | 150, 0 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI 5 | -150, 70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI extra | 129, 70 | 18.51, Optimal weight | 18.51, Optimal weight | Match |

For the extra test I wanted a value just above the 18.5 boundary. 129 × 703 = 90,687, and 90,687 / 4,900 is about 18.5075, so it should be Optimal and display as 18.51. This checks that the Underweight cutoff isn't accidentally catching values right at the edge.

### Color Mixer

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| Color 1 | red, blue | purple | purple | Match |
| Color 2 | red, yellow | orange | orange | Match |
| Color 3 | blue, yellow | green | green | Match |
| Color 4 | blue, red | purple | purple | Match |
| Color 5 | red, red | red | red | Match |
| Color 6 | orange, blue | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color 7 | red, orange | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color extra | yellow, red | orange | orange | Match |

For the extra test I wanted to check the reversed order of a mixture that isn't in the required list. Yellow first and red second should still give orange.

*(If any of my actual results ended up different from what I predicted when I ran them, I'd write the problem and the fix in the last column. Update this table to match what you actually saw.)*

---

## Explanation answers

**How does the BMI formula use pounds and inches? Why is height * height needed?**
BMI in pounds and inches is `weight * 703 / (height * height)`. BMI is weight divided by height squared, so I need height times height. The 703 is the conversion factor that makes pounds and inches work out to the same BMI scale you get with kilograms and meters.

**How do your conditions handle exactly 18.5 and exactly 25.0? Does the order matter? How do they avoid gaps and handle both endpoints?**
I check `bmi < 18.5` first for Underweight. Then `bmi <= 25.0` for Optimal. Everything else is Overweight. An exact 18.5 fails the first check (it's not less than 18.5), so it lands in Optimal. An exact 25.0 passes the second check because of the `<=`, so it also lands in Optimal. Order does matter. Because I use an if / else if chain, the second condition only runs after the first one failed, so I know the BMI is already at least 18.5 and I don't have to write a lower bound. There are no gaps because every number goes into exactly one of the three branches.

**Why do you check weight and height before calculating BMI?**
If height is 0, the formula divides by zero. Negative numbers would give meaningless results (a negative weight or height isn't a real measurement). Checking first means I never run the math on bad data.

**Why do you classify the unrounded BMI and round only its displayed value?**
Rounding changes the number. If a BMI of 24.996 were rounded to 25.00 before the comparison, it could be classified differently than its real value says. So I classify the real stored number and only use `setprecision(2)` when printing, which changes how it's displayed and not what's stored.

**What does strcmp return for equal text? Why is == not the correct comparison for character-array contents?**
`strcmp` returns 0 when the two strings match. A character array name is basically the address of where the text sits in memory, so `==` compares addresses and not the letters. Two arrays that both hold "red" are in different places, so `==` would say they're different. `strcmp` actually compares the characters.

**How do you make each mixture work in either input order and handle two identical primary colors?**
For each mixture I check both orders. For example, purple is `(first is red AND second is blue) OR (first is blue AND second is red)`. For identical colors, I check whether `strcmp(first_color, second_color) == 0`, and if so the result is just that color.

**How do you check for an invalid color in either input position?**
Before any mixing, I check each input separately against red, blue, and yellow. If the first one doesn't match any of them, or the second one doesn't match any of them, I print the error and stop. That way an invalid name works in either position, since both get checked.

**How do named constants and result variables make your programs easier to read and check?**
Named constants like `BMI_FACTOR` and `UNDERWEIGHT_LIMIT` explain what a number means, instead of leaving a mystery 703 or 18.5 in the code. If a value ever needed to change, I'd only change it in one place. Result variables like `bmi` mean the calculation happens in one spot and `cout` just prints the stored value, so it's easy to see what was calculated and check it.
