// Mercúrio
#define merR 1
#define merG 2
#define merB 3
#define merM 4

// Vênus
#define venR 5
#define venG 6
#define venB 7
#define venM 8

// Terra
#define terR 9
#define terG 10
#define terB 11
#define terM 12

// Marte
#define marR 13
#define marG 14
#define marB 15
#define marM 16

// Júpiter
#define jupR 17
#define jupG 18
#define jupB 19
#define jupM 20

// Saturno
#define satR 21
#define satG 22
#define satB 23
#define satM 24

// Urano
#define uraR 25
#define uraG 26
#define uraB 27
#define uraM 28

// Netuno
#define netR 29
#define netG 30
#define netB 31
#define netM 32

#include "SoftwareSerial.h"

const int RXpin = 2;
const int TXpin = 3;
const int ledPin = 11;
int incomingByte = 0;

SoftwareSerial bluetooth(TXpin, RXpin);

void setup() {
    Serial.begin(9600);
    bluetooth.begin(9600);

    bluetooth.print("ok");
    delay(100);

    for(int i=1; i<=32; i++){
        pinMode(i, OUTPUT);
    } 
    desligar();
}

void loop() {
    if (bluetooth.available()) {
        String comando = bluetooth.readStringUntil('\n');
        resposta();

        comando.toLowerCase();

        if (comando.equals("mer")) {
            resposta();
            mercurio();
        } else if (comando.equals("ven")) {
            resposta();
            venus();
        } else if (comando.equals("ter")) {
            resposta();
            terra();
        } else if (comando.equals("mar")) {
            resposta();
            marte();
        } else if (comando.equals("jup")) {
            resposta();
            jupiter();
        } else if (comando.equals("sat")) {
            resposta();
            saturno();
        } else if (comando.equals("ura")) {
            resposta();
            urano();
        } else if (comando.equals("net")) {
            resposta();
            netuno();
        } else if (comando.equals("desligar")) {
            resposta();
            desligar();
        }
    }
}

void mercurio() {
    digitalWrite(merR, HIGH);
    digitalWrite(merG, LOW);
    digitalWrite(merB, LOW);
    digitalWrite(merM, HIGH);
}

void venus() {
    digitalWrite(venR, HIGH);
    digitalWrite(venG, HIGH);
    digitalWrite(venB, LOW);
    digitalWrite(venM, HIGH);
}

void terra() {
    digitalWrite(terR, LOW);
    digitalWrite(terG, HIGH);
    digitalWrite(terB, HIGH);
    digitalWrite(terM, HIGH);
}

void marte() {
    digitalWrite(marR, HIGH);
    digitalWrite(marG, LOW);
    digitalWrite(marB, LOW);
    digitalWrite(marM, HIGH);
}

void jupiter() {
    digitalWrite(jupR, HIGH);
    digitalWrite(jupG, HIGH);
    digitalWrite(jupB, LOW);
    digitalWrite(jupM, HIGH);
}

void saturno() {
    digitalWrite(satR, HIGH);
    digitalWrite(satG, HIGH);
    digitalWrite(satB, LOW);
    digitalWrite(satM, HIGH);
}

void urano() {
    digitalWrite(uraR, LOW);
    digitalWrite(uraG, HIGH);
    digitalWrite(uraB, HIGH);
    digitalWrite(uraM, HIGH);
}

void netuno() {
    digitalWrite(netR, LOW);
    digitalWrite(netG, LOW);
    digitalWrite(netB, HIGH);
    digitalWrite(netM, HIGH);
}

void desligar() {
    for(int i=1; i<=32; i++) {
        digitalWrite(i,LOW);
    }
}

void resposta() {
    bluetooth.println("OK");
}