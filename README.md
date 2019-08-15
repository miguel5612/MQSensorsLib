# MQSensorsLib

This is a unified library to use sensors MQ: 2, 3, 4, 5, 6, 7, 8, 9, 131, 135, 303A and 309A.

## Getting Started

```
MQUnifiedsensor MQ4(pin, 4); //Example if sensor is MQ4, type = 4
float ppmCH4 = MQ4.readSensor();
```

### Prerequisites

You'll need Arduino desftop app 1.8.9 or later.

### Sensor manufacter:
| Sensor | Manufacter | URL Datasheet |
|----------|----------|----------|
| MQ-2 | Pololulu| [datasheet](https://www.pololu.com/file/0J309/MQ2.pdf) |
| MQ-3 | Sparkfun | [datasheet](https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf) |
| MQ-4 | Sparkfun | [datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-4.pdf) |
| MQ-5 | parallax | [datasheet](https://www.parallax.com/sites/default/files/downloads/605-00009-MQ-5-Datasheet.pdf) |
| MQ-6 | Sparkfun | [datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-6.pdf) |
| MQ-7 | Sparkfun | [datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-7.pdf) |
| MQ-8 | Sparkfun | [datasheet](https://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Biometric/MQ-8.pdf) |
| MQ-9 | Haoyuelectronics | [datasheet](http://www.haoyuelectronics.com/Attachment/MQ-9/MQ9.pdf) |
| MQ-131 | Sensorsportal | [datasheet](http://www.sensorsportal.com/DOWNLOADS/MQ131.pdf) |
| MQ-135 | HANWEI Electronics | [datasheet](https://www.electronicoscaldas.com/datasheet/MQ-135_Hanwei.pdf) |
| MQ-303A | HANWEI Electronics | [datasheet](http://www.kosmodrom.com.ua/pdf/MQ303A.pdf) |
| MQ-309A | HANWEI Electronics | [datasheet](http://www.sensorica.ru/pdf/MQ-309A.pdf) |

### Info of datasheets 

Review WPDigitalizer [folder](https://github.com/miguel5612/MQSensorsLib/tree/master/WPDigitalizer) [website](https://automeris.io/WebPlotDigitizer/)

### Installing

Clone this repositry into your desktop machine

```
git clone https://github.com/miguel5612/MQSensorsLib
```


## Running the tests

Use calibration systems if you have several sensors that read the same gas.

### Break down into end to end tests

These test can re-adjust values defined previously and you can contribute to improve conditions or features obtained from particular scenes.

```
Examples/MQ-3
```

### And coding style tests

These tests may generate statistics validation using descriptive tools for cuantitative variables.

```
Examples/MQ-board.ino
```

## Built With

* [Data sheets](https://github.com/miguel5612/MQSensorsLib/tree/master/Datasheets) - Curves and behavior for each sensor, using logarithmic graphs.
* [Main purpose](https://github.com/miguel5612/MQSensorsLib/blob/master/static/img/bg.jpg) - Every sensor has high sensibility for a specific gas or material.

## Contributing

Please read [CONTRIBUTING.md](https://github.com/miguel5612/MQSensorsLib/blob/NO_Functional/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

* **Miguel A. Califa U.** - [*GitHub*](https://github.com/miguel5612) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050477)
* **Ghiordy F. Contreras C.** - [*GitHub*](https://github.com/Ghiordy) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050476) 
* **Yersson R. Carrillo A.** - [*GitHub*](https://github.com/Yercar18/Dronefenix)  - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0001637655)

## Colaborators

* **Andres A. Martinez.** 
* **Juan A. Rodríguez.** - [*Github*](https://github.com/Obiot24)
* **Mario A. Rodríguez O.** - [*GitHub*](https://github.com/MarioAndresR) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000111304)

See also the list of [contributors](https://github.com/miguel5612/MQSensorsLib/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
