The code has been developped for a school project.

It uses an AK68X37 solar panel (5V, 60mA) and an Adafruit Circuit playground Express to read the voltage produced by the solar panel directly connected to a 56Ohm resistive load.

The measured voltage is smoothened with an moving average filter, the measured voltage, as well as the calculated produced power and an abitrary yield are transmitted via USB to the connected computer's terminal.

The yield is also displayed using the neopixels on the Circuit Playground. The pixels on each side are lit up in parallel, each pixel corresponds to a yield of roughly 20%, 40%, 60%, etc.
