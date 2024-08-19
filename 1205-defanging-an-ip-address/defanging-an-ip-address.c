char* defangIPaddr(char* address) {
    // Calculate the new length of the result string
    int original_len = strlen(address);
    int dot_count = 0;

    for (int i = 0; i < original_len; i++) {
        if (address[i] == '.') {
            dot_count++;
        }
    }

    // The length of the new string should be the original length + 2 extra characters per dot
    int new_len = original_len + 2 * dot_count;
    char* result = (char*)malloc((new_len + 1) * sizeof(char)); // +1 for the null terminator

    int j = 0;
    for (int i = 0; i < original_len; i++) {
        if (address[i] == '.') {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        } else {
            result[j++] = address[i];
        }
    }

    result[j] = '\0';  // Null-terminate the result string
    return result;
}