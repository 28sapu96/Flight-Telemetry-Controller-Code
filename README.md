The plane telemetry page is only a display and doesn't have any backend coded yet.

The arduino code works.
Inputs are from a [4-channel receiver](https://www.amazon.com/Channel-Single-Transmitter-Receiver-Airplane/dp/B0BN34D7MD/), where 2 are Boolean channels (On or Off) and 2 are PWM channels (Range of values). It is meant for a car, but the code converts it into 5-channels, where 4 are PWM channels and 1 is a Boolean channel, which is sufficient to fly a plane.
