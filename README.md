# Booster Control Unit (BCU)

The BCU is a board with two STM32H723 MCUs that controls the LSM mounted on the
track as the vehicle goes through the booster section.

The main responsabilities are:

* Monitoring of the supercapacitor pack
* Control the electrical circuit contactors to do both the precharge and active discharge when needed
* Run the LSM control algorithm
* Accurrately measure vehicle position during the booster section
* Run protections to prevent accidents
