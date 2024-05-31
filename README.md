# pico-stdin
A simple program to demonstrate how to process user input from `stdin`, on the Pico / RP2040.

Note that to send user input to the target in **VSCode** you have to move the cursor into the grey bar at the bottom of the serial monitor.

## Flushing `stdin` ##
The first character you read always seems to be garbage. This may be a peculiarity of PicoProbe.

Calling `fflush(stdin)` does nothing. To drain the buffer, do this:
```
while(getchar_timeout_us(0) == PICO_ERROR_TIMEOUT);
```

## Avoid `scanf()` ##
Although `scanf()` looks useful it's got some **very** annoying flaws and is best avoided.

Instead use `fgets()` followed by `sscanf()`.

## Build environment ##
The project configures VSCode to program and debug the target device via its SWD pins by using another Pico as a USB/SWD bridge (see [Picoprobe](https://github.com/raspberrypi/picoprobe)).