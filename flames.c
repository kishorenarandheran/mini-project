#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove common characters and return the length of the remaining string
int removeCommonChars(char *str1, char *str2) {
    int count = 0;
    int freq1[26] = {0};
    int freq2[26] = {0};

    // Convert to lowercase and count frequency of each character
    for (int i = 0; i < strlen(str1); i++) {
        if (isalpha(str1[i])) {
            freq1[tolower(str1[i]) - 'a']++;
        }
    }
    for (int i = 0; i < strlen(str2); i++) {
        if (isalpha(str2[i])) {
            freq2[tolower(str2[i]) - 'a']++;
        }
    }

    // Calculate the number of characters left after removing common ones
    for (int i = 0; i < 26; i++) {
        count += abs(freq1[i] - freq2[i]);
    }
    return count;
}

// Function to determine the FLAMES result
char* flamesResult(int count) {
    char flames[] = "FLAMES";
    int flamesLen = strlen(flames);
    int index = 0;

    while (flamesLen > 1) {
        index = (index + count - 1) % flamesLen;
        for (int i = index; i < flamesLen - 1; i++) {
            flames[i] = flames[i + 1];
        }
        flames[flamesLen - 1] = '\0';
        flamesLen--;
    }

    switch (flames[0]) {
        case 'F': return "Friends";
        case 'L': return "Love";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemies";
        case 'S': return "Siblings";
        default: return "Unknown";
    }
}

int main() {
    char name1[100], name2[100];

    printf("Enter the first name: ");
    fgets(name1, sizeof(name1), stdin);
    printf("Enter the second name: ");
    fgets(name2, sizeof(name2), stdin);

    // Remove newline characters from the input
    name1[strcspn(name1, "\n")] = '\0';
    name2[strcspn(name2, "\n")] = '\0';

    // Calculate the remaining character count
    int remainingCount = removeCommonChars(name1, name2);

    // Determine the FLAMES result
    char *result = flamesResult(remainingCount);

    printf("The relationship is: %s\n", result);

    return 0;
}

