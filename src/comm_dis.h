// comm_dis.h
#ifndef COMM_DIS_H
#define COMM_DIS_H

#include <Arduino.h>
#include <ArduinoJson.h>

// Definir las estructuras de datos
struct DataOutDis {
    bool Bomba;
    bool Pulso_Tomamuestras;
    bool Sentido_Tomamuestras;
    bool Valvula;
    int GPRS;
    bool LCB_ON;
    int Impresora;
    float caudalimetro;
    int Version;
};

struct DataInDis {
    float flow;
    float volumen;
    int teclado;
    float temperatura;
    float nivel;
    bool manualAutomatico;
    bool gprs;
    bool lcb;
    bool statusImpresora;
    bool sensorTension;
    int Version;
};

// Declaraciones de las instancias de datos
extern DataOutDis currentDataOutDis, previousDataOutDis;

extern DataInDis currentDataInDis, previousDataInDis;

bool receiveDataDis(DataInDis& data);
void sendDataDis(const DataOutDis& data);

#endif // COMM_DIS_H
