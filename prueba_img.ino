/***   Included libraries  ***/
#include <BitbloqSoftwareSerial.h>


/***   Global variables and function definition  ***/
float getLight(bqSoftwareSerial & phone) {
    phone.println(String("readLight-"));
    String data = "";
    while (data == "") {
        data = phone.readString();
    }
    return data.toFloat();
}

void setEyes1(bqSoftwareSerial & phone) {
    phone.println(String("im1-"));
}

void setEyes2(bqSoftwareSerial & phone) {
    phone.println(String("im2-"));
}

bqSoftwareSerial bluetooth_de_la_placa(0, 1, 19200);




/***   Setup  ***/
void setup() {
    bluetooth_de_la_placa.begin(19200);

}


/***   Loop  ***/
void loop() {
  float light = getLight(bluetooth_de_la_placa);
  //bluetooth_de_la_placa.println(String("write-")+String(light));
    if (light < 100) {
        setEyes1(bluetooth_de_la_placa);
        delay(1000);
    } else {
        setEyes2(bluetooth_de_la_placa);
        delay(1000);
    }
}
