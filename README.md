# EEVM
In the near future, the conclusion of transactions for the supply of a certain type of products will be carried out with a flexible specification of the technological process of production. Therefore, our main business idea is to bring arbitration to small IoT devices, such as switches, sensors, which we suggest to be called “smart-sensors”.

The main task of this class of devices is to guarantee the execution of a certain smart contract, to prevent falsification, some last outpost of intellectual automation for field and small-scale productions by farm type.

The ability to rebuild the process of production, logistics and data supply by autonomous robots to reflect the changing human needs is the most important step on the way to the advent of fully automated enterprises. Humanity are facing dawn of Robonomics, or so called “Industry 4.0”, so it is urgent to develop smart-sensors, the basic building blocks for Robonomics.

[AIRA](https://aira.life) project is aimed for this goal, with focus towards ecosystem development.  We completely share their vision, but shifting attention towards small-factor - smart-sensors.

## Smart-contracts (Ethereum blockchain)
Ethereum is a single computer we can trust.

“What is more interesting about Ethereum, however, is that the Ethereum protocol moves far beyond just currency. Protocols around decentralized file storage, decentralized computation and decentralized prediction markets, among dozens of other such concepts, have the potential to substantially increase the efficiency of the computational industry, and provide a massive boost to other peer-to-peer protocols by adding for the first time an economic layer. Finally, there is also a substantial array of applications that have nothing to do with money at all”. (from Ethereum’s White Paper).

## Hardware Oracles (RFID sensors, FOAM’s Proof of Location)
Some smart contracts need information directly from the physical world, for example, a car crossing a barrier 
where movement sensors must detect the vehicle and send the data to a smart contract. Another use case is RFID 
sensors in the supply chain industry. The biggest challenge for hardware oracles is the ability to report 
readings without sacrificing data security. Oracalize proposes a two-step solution to the risks, by providing 
cryptographic evidence of the sensor’s readings and anti-tampering mechanisms rendering the device inoperable in 
the case of a breach.

FOAM provides solutions for such type of problems - [Crypto Spatial Coordinate (CSC) standard](https://blog.foam.space/crypto-spatial-coordinates-fe0527816506), [Proof of Location protocol](https://blog.foam.space/introduction-to-proof-of-location-6b4c77928022) and [The Spatial Index](https://blog.foam.space/the-spatial-index-9793f42c46c8), but also required Ethereum infrastructure, it’s a core component for FOAM’s vision.

## Internet of Things (Arduino-compatible ESP32 chip)
Besides all benefits from current IoT systems stays common problem - diversity of protocols and standards (IO-Link, MQTT, CoAP, gRPC, REST). Our concept aimed to unify devices with one medium: prototype-friendly Arduino-platform and IoT Espressif’s Hybrid Wi-Fi & Bluetooth Chip ESP32 Chip.

## EVM implementations and technology stack

| Project       | Licence     | IoT compatible |
| ------------- | ----------- | -------------- |
| go-ethereum   | LGPL-3.0    | no             |
| parity        | GPL-3.0     | no             |
| cpp-ethereum  | GPL-3.0     | no             |
| sputnikVM     | Apache 2.0  | partially      |
| pyethereum    | MIT         | no             |
| hevm          | AGPL-3.0    | no             | 

Currently there are exists lots of VM implementations, both as standalone or tightly integrated into existing ethereum nodes, but they are all lacking support for `tiny` microcontrollers. 

We define `tiny` as: 
* single or dual core System-on-Chip(SoC)
* <200 Mhz clock speed
* 1-2 Mb RAM

To implement EEVM we would use ISO C99 with some Lua configuration scripting.
Also to fit hardware restrictions some data types may require stripping, further investigation on this topic is required.

## AWS & Google IoT Platforms (Mongoose OS)
Mongoose OS is production grade embedded RTOS with out-of-box integration with all major cloud IoT platforms AWS, Google, Azure, Samsung. It’s a good choice for production ready platform with a great documentation and bunch of examples. 

## Ethereum Sharding (Casper Hardfork)
In current form Ethereum is too resource intensive to use it as medium for robonomics. Sharding proposal is a urgent step towards side chains ancored on main Ethereum blockchain and aimed for increasing of scalability and throughput, but sacrificing security, and it fits purely for low performance platforms.

µRaiden is also an interesting alternative approach how to control devices remotely via payment channels ([example for dron](https://www.youtube.com/watch?v=E6CIgJPxgpQ&t=540s)).

## Formal smart-contracts verification (K-semantics)
Especially for embedded devices it’s very important to formally verify smart-contract logic. KEVM brings for us a good basis to automate this process. For every smart-contract we will create additionally k-semantics in order to formally proof it’s internal logic.

## Unlicensed
The Unlicense is a public domain equivalent license with a focus on an anti-copyright message.

