int scoreOfString(char* s) {
    int score = 0;
    int i = 1;

    while(s[i] != '\0') {
        score += abs(s[i - 1] - s[i]);
        i += 1;
    }

    return score;
}