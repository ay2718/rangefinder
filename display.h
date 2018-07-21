#ifndef DISPLAY_H
#define DISPLAY_H

const uint8_t digits[10] = {0b11111100,  // 0
                            0b01100000,  // 1
                            0b11011010,  // 2
                            0b11110010,  // 3
                            0b01100110,  // 4
                            0b10110110,  // 5
                            0b10111110,  // 6
                            0b11100000,  // 7
                            0b11111110,  // 8
                            0b11110110}; // 9

class Display {
 private:
    int pins[8];
 public:
    Display(int, int, int, int, int, int, int, int);
    bool write(int);
    void clear()
};

Display::Display(int A, int B, int C, int D, int E, int F, int G, int DP) {
    pins[0] = A;
    pins[1] = B;
    pins[2] = C;
    pins[3] = D;
    pins[4] = E;
    pins[5] = F;
    pins[6] = G;
    pins[7] = DP;

    for (int i = 0; i < 8; i++) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], HIGH);
    }
}

void Display::clear() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(pins[i], HIGH);
    }
}

bool Display::write(int digit) {
    if (digit < 0 || digit > 9) {
        clear();
        return false;
    } else {
        for(uint8_t shifter = 0b10000000, uint8_t i = 0; shifter > 0; shifter >>= 1, i++) {
            bool value = digits[digit] & shifter;
            digitalWrite(pins[i], value);
        }
    }
}

#endif // DISPLAY_H
