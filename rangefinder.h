#ifndef RANGEFINDER_H
#define RANGEFINDER_H

const float microsToCM = 343.f / 20000.f;

class Rangefinder {
 private:
    int trigPin, echoPin;
    float distance;
 public:
    Rangefinder();
    Rangefinder(int, int);
    float pulse() {return pulse(200.0f); };
    float pulse(float);
    float get() { return distance; };
    bool print();
};

Rangefinder::Rangefinder() {
    trigPin = 7;
    echoPin = 6;
    distance = 0;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

Rangefinder::Rangefinder(int _trigPin, int _echoPin) {
    trigPin = _trigPin;
    echoPin = _echoPin;
    distance = 0;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

float Rangefinder::pulse(float maxDistance) {
    unsigned long duration, timeout;
    timeout = maxDistance / microsToCM;

    // Send a 10 us pulse to trigPin
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Read a pulse
    duration = pulseIn(echoPin, HIGH, timeout);
    distance = duration * microsToCM;   // compute distance in cm
    return distance;
}

bool Rangefinder::print() {
    Serial.print("Distance = "); 
    if (distance <= 2.0){                  // If distance is too short (< 2 cm), ignore it
        Serial.println("Out of range");
        return false;
    } else {
        Serial.print(distance); Serial.println(" cm");
        return true;
    }
}
    
#endif
