constexpr uint8_t gcdTable[10][10] = {
    {},
    {1},
    {2, 1},
    {3, 1, 1},
    {4, 1, 2, 1},
    {5, 1, 1, 1, 1},
    {6, 1, 2, 3, 2, 1},
    {7, 1, 1, 1, 1, 1, 1},
    {8, 1, 2, 1, 4, 1, 2, 1},
    {9, 1, 1, 3, 1, 1, 3, 1, 1},
};

constexpr int LIMIT = 200001;

long long remainingFactor[LIMIT];
char answerBuffer[LIMIT + 1];

class Solution {
public:
    string smallestNumber(string number, long long target) {

        long long check = target >> __builtin_ctzll(target);

        for (int prime : {3, 5, 7}) {
            while (check % prime == 0)
                check /= prime;
        }

        if (check > 1)
            return "-1";

        int len = number.length();

        remainingFactor[0] = target;
        remainingFactor[len] = 0;

        int firstZeroPos = len - 1;

        for (int i = 0; i < len; i++) {
            if (number[i] == '0') {
                firstZeroPos = i;
                break;
            }

            long long digit = number[i] - '0';
            remainingFactor[i + 1] =
                remainingFactor[i] /
                gcdTable[digit][remainingFactor[i] % digit];
        }

        if (remainingFactor[len] == 1)
            return number;

        for (int i = firstZeroPos; i >= 0; i--) {

            while (++number[i] <= '9') {

                long long digit = number[i] - '0';

                long long need =
                    remainingFactor[i] /
                    gcdTable[digit][remainingFactor[i] % digit];

                int largestDigit = 9;

                for (int j = len - 1; j > i; j--) {

                    while (need % largestDigit)
                        largestDigit--;

                    need /= largestDigit;
                    number[j] = largestDigit + '0';
                }

                if (need == 1)
                    return number;
            }
        }

        int start = LIMIT + 1;

        for (int digit = 9; digit > 1; digit--) {
            while (target % digit == 0) {
                answerBuffer[--start] = digit + '0';
                target /= digit;
            }
        }

        while (LIMIT - start < len)
            answerBuffer[--start] = '1';

        return string(answerBuffer + start, LIMIT + 1 - start);
    }
};