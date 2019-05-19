# MQSensorsLib

This is a unified library to use sensors MQ: 2, 3, 4, 5, 6, 7, 8, 9, and 135.

## Getting Started

```
MQsensorLib Sensor1(MQ4);
ppmMethano = Sensor1.readPPM();
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

### Info of datasheets (Lineal analisis of Logarithmic rects
<table>
    <thead>
        <tr>
            <th colspan="1">Sensor</th>
            <th colspan="2">H2</th>
            <th colspan="2">LPG</th>
            <th colspan="2">CH4</th>
            <th colspan="2">CO</th>
            <th colspan="2">Alcohol</th>
            <th colspan="2">Propane</th>
            <th colspan="2">Benzine</th>
            <th colspan="2">Hexane</th>
            <th colspan="2">Smoke</th>
            <th colspan="2">Nox</th>
            <th colspan="2">CL2</th>
            <th colspan="2">O3</th>
            <th colspan="2">CO2</th>
            <th colspan="2">Tolueno</th>
            <th colspan="2">NH4</th>
            <th colspan="2">Acetona</th>
            <th colspan="2">Iso-butano</th>
            <th colspan="2">Hydrogeno</th>
            <th colspan="2">Ethanol</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td></td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>
            <td>m</td>
            <td>b</td>            
            <td>m</td>
            <td>b</td>
        </tr>
         <tr>
           <td>-MQ-2 Pololulu</td>
            <td>-2.2459</td>
            <td>2.9845</td>
            <td>-2.2879</td>
            <td>2.7901</td>
            <td>-2.6208</td>
            <td>3.6075</td>
            <td>-3.1157</td>
            <td>4.5134</td>
            <td>-2.7028</td>
            <td>3.5595</td>
            <td>-2.2879</td>
            <td>2.7901</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
         <tr>
           <td>-MQ-3 Sparkfun</td>
            <td></td>
            <td></td>
            <td>-3.1851</td>
            <td>4.7048</td>
            <td>-17.531</td>
            <td>28.785</td>
            <td>-4.339</td>
            <td>6.4432</td>
            <td>-1.435</td>
            <td>0.4103</td>
            <td></td>
            <td></td>
            <td>-2.7009</td>
            <td>0.632</td>
            <td>-2.7268</td>
            <td>3.6299</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>-MQ-4 Sparkfun</td>
            <td></td>
            <td></td>
            <td>-2.5818</td>
            <td>3.6303</td>
            <td>0.9873</td>
            <td>2.6386</td>
            <td>-5.5945</td>
            <td>5.6693</td>
            <td>-11.89</td>
            <td>9.0375</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td>-11.189</td>
            <td>9.0375</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>-MQ-5 Sparkfun</td>
            <td>-4.368</td>
            <td>2.9667</td>
            <td>-2.5723</td>
            <td>1.8943</td>
            <td>-2.4438</td>
            <td>2.3044</td>
            <td>-4.8188</td>
            <td>5.2023</td>
            <td>-4.419</td>
            <td>4.8044</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>-MQ-6 Sparkfun</td>
            <td>-3.6775</td>
            <td>5.0286</td>
            <td>-1.6567</td>
            <td>2.8775</td>
            <td>-1</td>
            <td>3.301</td>
            <td>-12.791</td>
            <td>14.523</td>
            <td>-5.8057</td>
            <td>7.5292</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>-MQ-7 Sparkfun</td>
            <td>-1.329</td>
            <td>1.8864</td>
            <td>-7.8626</td>
            <td>9.1056</td>
            <td>-5.4878</td>
            <td>8.8387</td>
            <td>-1.4065</td>
            <td>2.0162</td>
            <td>-6.3219</td>
            <td>9.924</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>MQ-8 Sparkfun</td>
            <td>-0.7152</td>
            <td>2.9891</td>
            <td>-3.419</td>
            <td>7.3513</td>
            <td>-7.5609</td>
            <td>15.243</td>
            <td>-7.0753</td>
            <td>15.396</td>
            <td>-1.7459</td>
            <td>4.7575</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>MQ9 - Haoyuelectronics</td>
            <td></td>
            <td></td>
            <td>-2.2535</td>
            <td>2.9855</td>
            <td>-1.6012</td>
            <td>3.1476</td>
            <td>-1.749</td>
            <td>2.827</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
           <td>MQ131- Sensorsportal</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td>-2.7245</td>
            <td>3.3004</td>
            <td>-1.0333</td>
            <td>1.7117</td>
            <td>-1.2037</td>
            <td>1.6455</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>

        <tr>
           <td>MQ135 - HANWEI</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td>-2.7268</td>
            <td>2.301</td>
            <td>-2.8608</td>
            <td>1.8627</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td>-3.2819</td>
            <td>1.9903</td>
            <td>-5.7015</td>
            <td>1.1612</td>
            <td>-2.2119</td>
            <td>2.0473</td>
            <td>-5.9682</td>
            <td>1.0175</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
    </tbody>
</table>

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

* **Miguel A. Califa U.** - [*GitHub*](https://github.com/miguel5612) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050477)
* **Ghiordy F. Contreras C.** - [*GitHub*](https://github.com/Ghiordy) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050476) 
* **Mario A. Rodríguez O.** - [*GitHub*](https://github.com/MarioAndresR) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000111304)

See also the list of [contributors](https://github.com/miguel5612/MQSensorsLib/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
