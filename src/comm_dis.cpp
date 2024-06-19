// comm_dis.cpp
#include <ArduinoJson.h>
#include "comm_dis.h"

// Definiciones de las instancias de datos
DataOutDis currentDataOutDis, previousDataOutDis;
DataInDis currentDataInDis, previousDataInDis;
extern char Tecla;

// Función para calcular checksum
unsigned char calculateChecksumDis(const String& data) {
    unsigned char checksum = 0;
    for (unsigned int i = 0; i < data.length(); i++) {
        checksum ^= data[i];
    }
    return checksum;
}

// Función para enviar datos parciales
void sendDataDis(const DataOutDis& data) {
    StaticJsonDocument<256> doc;
    if (data.Bomba != previousDataOutDis.Bomba) {
        doc["BOMBA"] = data.Bomba;
    }
    if (data.Pulso_Tomamuestras != previousDataOutDis.Pulso_Tomamuestras) {
        doc["P_TM"] = data.Pulso_Tomamuestras;
    }
    if (data.Sentido_Tomamuestras != previousDataOutDis.Sentido_Tomamuestras) {
        doc["S_TM"] = data.Sentido_Tomamuestras;
    }
    if (data.Valvula != previousDataOutDis.Valvula) {
        doc["VALVULA"] = data.Valvula;
    }
    if (data.GPRS != previousDataOutDis.GPRS) {
        doc["GPRS"] = data.GPRS;
    }
    if (data.LCB_ON != previousDataOutDis.LCB_ON) {
        doc["LCB"] = data.LCB_ON;
    }
    if (data.Impresora != previousDataOutDis.Impresora) {
        doc["IMPRESORA"] = data.Impresora;
    }
    if (data.caudalimetro != previousDataOutDis.caudalimetro) {
        doc["Caudalimetro"] = data.caudalimetro;
    }
    if (data.Version != previousDataOutDis.Version) {
        doc["Ver"] = data.Version;
    }
    if (doc.size() > 0) {
        String jsonString;
        serializeJson(doc, jsonString);
        unsigned char checksum = calculateChecksumDis(jsonString);
        Serial2.print("[");
        Serial2.print(jsonString);
        Serial2.printf(",%02X]\n", checksum);
        Serial.println(jsonString);
    }
}

// Función para recibir datos
bool receiveDataDis(DataInDis& data) {
    static String jsonData = "";
    while (Serial2.available() > 0) {
        char c = Serial2.read();
        if (c == '[') {
            jsonData = "";
        }
        jsonData += c;
        if (c == ']') {
            int commaIndex = jsonData.lastIndexOf(',');
            if (commaIndex == -1) {
                return false;
            }
            String jsonString = jsonData.substring(1, commaIndex);
            String checksumString = jsonData.substring(commaIndex + 1, jsonData.length() - 1);
            unsigned char receivedChecksum = (unsigned char)strtol(checksumString.c_str(), NULL, 16);
            int ChkCalculado=calculateChecksumDis(jsonString);
            if (receivedChecksum != ChkCalculado) {
                Serial.println(jsonString);
                Serial.println("Bad checksum");
                Serial.printf("Recibido :%X / Calculado: %X",receivedChecksum,ChkCalculado);
                return false;
            }

            StaticJsonDocument<256> doc;
            DeserializationError error = deserializeJson(doc, jsonString);
            if (error) {
                Serial.println("Error al deserializar");
                return false;
            }

            if (doc.containsKey("Q")) {
                data.flow = doc["Q"];
            }
            if (doc.containsKey("VOL")) {
                data.volumen = doc["VOL"];
            }
            if (doc.containsKey("TEC")) {
                data.teclado = doc["TEC"];
                Tecla=(char)data.teclado;                
            }
            if (doc.containsKey("TEMP")) {
                data.temperatura = doc["TEMP"];
            }
            if (doc.containsKey("NIV")) {
                data.nivel = doc["NIV"];
            }
            if (doc.containsKey("M_A")) {
                data.manualAutomatico = doc["M_A"];
            }
            if (doc.containsKey("gprs")) {
                data.gprs = doc["gprs"];
            }
            if (doc.containsKey("lcb")) {
                data.lcb = doc["lcb"];
            }
            if (doc.containsKey("ST_I")) {
                data.statusImpresora = doc["ST_I"];
            }
            if (doc.containsKey("S_T")) {
                data.sensorTension = doc["S_T"];
            }
            if (doc.containsKey("Ver")) {
                data.Version = doc["Ver"];
            }
            return true;
        }
    }
    return false;
}
