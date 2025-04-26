// Shrinkable 

int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[i]
    }
    ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
}
return ans;


// Non Shrinkable (Fantastic Approach)
// When you aim for window size to be max.

int i = 0, j = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    if (invalid()) { // Increment the left edge ONLY when the window is invalid. In this way, the window GROWs when it's valid, and SHIFTs when it's invalid
        // CODE: update state using A[i]
        ++i;
    }
    // after `++j` in the for loop, this window `[i, j)` of length `j - i` MIGHT be valid.
}
return j - i; // There must be a maximum window of size `j - i`.


// Say, if you get 'k' as a valid window for current iteration.
// In next iteration, you will go and check if 'k+1' window can be valid. If yes, it doesn't go into invalid check, hence, 'i' won't get incremented.
// (Imp) If no, you just want to slide this 'k+1' window by 1, to repeat the same scenario for next iteration.
// Meaning, once you get 'k' as a valid window, you will NEVER EVER go "less than or equal" to it. you always aim for 'k+1',
// (j - i) gives size, because you would go out of loop, till N, which covers that extra +1.
