#pragma once

std::string caesarCipher(std::string s, int k) {
    k = k % 26;
    for (int i = 0; i < s.size(); i += 1)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = (s[i] + k > 90) ? (s[i] + k + 64) % 90 : (s[i] + k);
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = (s[i] + k > 122) ? (s[i] + k + 96) % 122 : (s[i] + k);
        }
    }
    return s;
}

