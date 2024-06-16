If you could divide a problem into acting at each levels, think of recursion!

**Brute Force** 
-  Trying out all combinations 
- Constraints used as-
-  Generator + Checker 

<!-- => Trying out all combinations => Generator + Checker <-- Constraints -->

**Back-Tracking:**  Brute Force implemented with Recursion

---

## LCCM Framework

- Level     : 
- Choices   : Possible values to fill in at a level
- Check     : Check if it is valid choice based on previous choices
- Move      : Make the move
    - Update the current solution
    - Recursion : Go to next level
    - Undo Move once done with next level exploration


**Code Snippet:**
```cpp

    vector<int> curr_soln;  // DS to store current soln

    void rec(int level){    // recursion with levels
        // base case
        if(level==n){
            // we have a soln (curr_soln)
            // print soln
            return;
        }

        // enumerate choices
        for(auto ch : choices){     // choices ?
            // check if valid choice based on previous choices (curr_soln)
            if(check(ch)){
                // make move
                curr_soln.push_back(ch);    // update curr_soln
                rec(level+1);               // go to next level (recursion)
                curr_soln.pop_back();       // undo move once done with next level exploration
            }
        }
    }

```


