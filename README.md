### Fab Challenge 3
# Hybrid Monitor
## Ethical Tool or artefact to Interact and Monitor Relevant Data
The challenge comprised the developement from the Duckweed Incubator from Term I to a Distributed & Independent Monitoring Sysytem.

-Miro Interests-
-Overall Plan Drawing- 

## Brief
The Aim was to design a physical module that could sit, embedd or float in a medium to monitor it's health. The data was measured in variables like Ambient Light access, Aerial Temperature, Media Temeperature, Moisture etc, and shared to an online dashboard for universal web access. The main qualities that guided every step and usage of components were the 'hybrid-ness', freedom and transparency of the data captured.

-Sensors used and Data captured diagram-

The core aim was to monitor the health for the Duckweeed plants so that athey could be grown in a healthy efficient way, to control the nutrition and strains of protiens grown, for consumption in the later stage. The same system could be used my multiple individuals for any plants or mediums be it, aquatic plants, terrestrial plants or even compost.

-Overall Plan- 

## Ideation
The ideation mainly involved exploring:

1. Simple Electronic Sensors that could be run with ~3.3V.
2. Enclosure that could  encapsulate + float + house the circuit safely & compactly.

-Sketch 1-
![First Iteration](https://user-images.githubusercontent.com/92102729/167128495-62129e46-15f4-4406-a582-c8af70b0f4cd.JPG)

-Sketch 2-
![Second Iteration](https://user-images.githubusercontent.com/92102729/167128503-4284e208-4f6a-4f80-b13d-59d298158e48.jpg)


## Process






### Circuit Evolution

-Circuit Evolution gif- -First test-

The electronics were powered by an ESP32 Huzzah microcontroller and a 5V USB input supporting the form factor and modes of connectivity. The evolution of the circuit occured in phases, with addition of one sensor at a time; starting with Temperature sensor to the Moisture sensor at last.


Version 6 circuitry setup  
![image  setup v6](https://user-images.githubusercontent.com/92102729/167100742-edb46a03-8fa4-4b46-85b6-816ac4c8e586.png)


### Data Monitoring

-Interaction Protocols-

Text explaining this comes here.

### Modelling & Fabrication
The housing was designed in parts in Fusion 360 and Rhino. The body was printed in black-filamented PLA with 0.25% resolution to maintain buoyancy and resistance to any possible wet media; while the top component was laser-cut in 2.9mm acrylic sheet to provide the sensors with access to light and air.

-Form Derivation- 
-screenshot of the model- 

## Learnings

Exploring MQTT and Data Management

Structuring and combining multiple Sketches/codes together

Controlling and distributing voltage across components through the same MC

Intra-communication accross Micro-contollers

## Trajectory

Classifying recorded data into categories like Optimum, Average and Bad for Analog Sense-making

Designing & linking a visual LED monitor for Analog sensing in times of Restricted Internet Access

Sharing the gathered Knowledge on 'Lemna' to create an incentivised ecosystem and community

Grow more Duckweed and create food-safe + healthy products

## References

Duckweed Nutrition:
https://www.sciencedirect.com/science/article/abs/pii/S0308814616313565#:~:text=Duckweeds%20contain%2020%E2%80%9335%25%20protein,10%25%20starch%20per%20dry%20weight.&text=Proteins%20constitute%204.8%25%20Lys%2C%202.7,and%207.7%25%20Phe%20%2B%20Tyr.&text=48%E2%80%9371%25%20of%20fat%20are,ratio%20is%200.5%20or%20less.&text=Mineral%20content%20can%20be%20easily,composition%20of%20the%20nutrient%20medium

Protein Production:
https://www.sciencedirect.com/science/article/abs/pii/S0960852421018411

Cultivation Setup:
https://www.sciencedirect.com/science/article/pii/S0959652621044504

ESP + Node:
https://randomnerdtutorials.com/esp8266-and-node-red-with-mqtt/
https://randomnerdtutorials.com/cloud-mqtt-mosquitto-broker-access-anywhere-digital-ocean/

Display:
https://create.arduino.cc/projecthub/Mukhin/led-architectural-machin-bb67ba?ref=search&ref_id=sensor%20to%20LED&offset=4

Plant Monitoring System © MIT:
https://create.arduino.cc/projecthub/ryanjgill2/plant-monitoring-system-88ed2b?_gl=1*1oyd8pd*_ga*NDYzODAxNTYzLjE2NDY4NDE4MjQ.*_ga_NEXN8H46L5*MTY1MTIyODYyNi4zNC4xLjE2NTEyMjg2MzYuMA..
