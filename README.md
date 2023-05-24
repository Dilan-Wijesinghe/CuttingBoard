# CuttingBoard
The Cutting Board, A Musical Instrument


### Unexpected Maker PRO S3 Setup Guide
There's a few quirks associated with getting the Unexpected Maker Pro S3 up and running. 
1. First verify the connection in Arduino or PlatformIO \
    1. Fixes for Linux
    + a. Alternatively `ls /dev/tty*` and make sure that `/dev/ttyACM0` is connected \
    + b. You might need to edit permissions if you get an [Errno 71]. Fix this with `sudo chmod a+rw /dev/ttyACM0` \
    + c. Put the Board in __Download Mode__ by holding down 'Boot', then tapping 'Reset', and releasing 'Boot'. The RGB LED should turn off \
    + d. Now Upload code to the board, and hit the reset button after it uploads
    + e. You should not have to hit any other buttons after this
2. Some sources you can use:
    + [UMPROS3 Website](https://esp32s3.com/pros3.html) 
    + [UM Helper Library](https://github.com/UnexpectedMaker/esp32s3-arduino-helper)
    + [UM Examples](https://github.com/sukesh-ak/UM-ESP32-S3-SAMPLES)


        