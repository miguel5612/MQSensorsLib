# MQSensorsLib

This is a unified library to use sensors MQ: 2, 3, 4, 5, 6, 7, 8, 9, and 135.

## Getting Started

```
MQsensorLib Sensor1(MQ4);
ppmMethano = Sensor1.readPPM();
```

### Prerequisites

You'll need Arduino desftop app 1.8.9 or later.

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
testMassive.ino
```

### And coding style tests

These tests may generate statistics validation using descriptive tools for cuantitative variables.

```
testStatics.ino
```

## Built With

* [Data sheets](https://github.com/miguel5612/MQSensorsLib/tree/master/Datasheets) - Curves and behavior for each sensor, using logarithmic graphs.
* [Main purpose](https://github.com/miguel5612/MQSensorsLib/blob/master/static/img/bg.jpg) - Every sensor has high sensibility for a specific gas or material.

## Contributing

Please read [CONTRIBUTING.md](https://github.com/miguel5612/MQSensorsLib/blob/NO_Functional/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

* **Miguel A. Califa U.** - [*GitHub*](https://github.com/miguel5612)
* **Ghiordy F. Contreras C.** - [*GitHub*](https://github.com/Ghiordy) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050476)
* **Mario A. Rodríguez O.** - [*GitHub*](https://github.com/MarioAndresR)

See also the list of [contributors](https://github.com/miguel5612/MQSensorsLib/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
