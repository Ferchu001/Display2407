// comm_dis.h
#ifndef COMM_DIS_H
#define COMM_DIS_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "struct_defines.h"



// Declaraciones de las instancias de datos
extern DataOutDis currentDataOutDis, previousDataOutDis;

extern DataInDis currentDataInDis, previousDataInDis;

bool receiveDataDis(DataInDis& data);
void sendDataDis(const DataOutDis& data);

#endif // COMM_DIS_H
