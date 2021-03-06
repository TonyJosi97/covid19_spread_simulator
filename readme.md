## COVID 19 GRAPHICAL SPREAD SIMULATOR

COVID19 SPREAD SIMULATOR is a graphical simulator that simulates the **spread(infections), diagnosis(testing), recovery and death** among population in a city due to COVID19 along with normal deaths and births of population happening in the city.

The simulator is highly configurable with options to configure limited set of settings using the structure fields by init functions, or building more customized verion by editing private/core define files (such as city size).

The program outputs population distribution in the city as [portable pixmap format (PPM)](https://en.wikipedia.org/wiki/Netpbm) image frames. These frames are then used to generate video using media players that supports input from ppm image frames, such as [mpv](https://en.wikipedia.org/wiki/Mpv_(media_player)).

#### Basic Design

[Basic control flow](https://github.com/TonyJosi97/covid19_spread_simulator/blob/code_cleanup/docs/design_breif.md)

### WIP Sample

![Sample WIP Output](https://github.com/TonyJosi97/covid19_spread_simulator/blob/master/cvdssim_wip_sample_2.gif)

#### Pixel color coding
* **WHITE**:    White represents non infected entities
* **BLUE**:     Blue blocks represent hospitals
* **GREEN**:    Green represents COVID19 recovered entities
* **PINK**:     Entities infected and quarantined

#### Initial Stats:
```
CUR_POPL: 440, TOTAL_CVD_INF: 14, TOTAL_CVD_ACTIVE: 14, TOTAL_CVD_RECVRD: 0, 
TOTAL_CVD_DCSD: 0, NEW_BIRTHS: 0, NORML_DEATHS: 0
```

#### After 250 Days:
```
CUR_POPL: 345, TOTAL_CVD_INF: 429, TOTAL_CVD_ACTIVE: 0, TOTAL_CVD_RECVRD: 331, 
TOTAL_CVD_DCSD: 98, NEW_BIRTHS: 28, NORML_DEATHS: 25

```

### Build & Run:

#### Build

```sh
cd covid19_spread_simulator
make
```

#### Run
``` sh
./cvd19ssim | mpv --no-correct-pts --fps=5 -
```

