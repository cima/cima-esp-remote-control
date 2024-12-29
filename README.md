# Cima ESP-32 Remote Control over NRF24

A general purpose input to command over the air transmitter code for ESP-32 microcontroller using NRF24. NRF24 promises up to 1 km* connectivity.

Code shall provide easy framework to send a custom command over the air based on any kind of input. Meaning you can react on input interrupt (button, motion sensor, light gate), you can sample an IR input, you can simply setup a timer. Just input...

NRF24 provides so called mesh so each input can be routed to one or many remote targets.

----
>\* with direct line of sight

# Development

Project is based on ESP's IDF framework with Cmake, ninja and C++20 to enable some real production grade software engineering.

## Prerequisities

- Python 3.9+
- [Git](https://git-scm.com/download/win)
- [CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)
  - Download v.11.1.0. Unzip. Rightclick _silabser.inf_ and select **install**. Follow instrucitons.
  - Plug-in your Daplink-enabled ESP-32 to USB. Serial port (Silicon Labs CP210x USB to UART Bridge
) should appear in device management.
- [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
  - Create serial port connection to port determined in previous step
  - Speed (baud): 115 200
  - Data bits: 8, stopbit: 1, flow control: XON/XOFF, parity: none
- [VSCode](https://code.visualstudio.com/)
  - [C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [ESP32 extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension)

- ESP 32 toolchain v5.4 (incl. gcc, cmake, ninja) – Windows
  - [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html)
    - Either Prepare directory for ESP tooling OR note down the ESP location during installation (will be needed for convenience script update)
    - Downlaods all the necesary tools for development (including COM drivers)
- [BOOST](https://www.boost.org/)
    - [Download BOOST](https://www.boost.org/users/download/) and unpack to either above mentioned ESP location or any custom location and note it down for below convenience script update.

### Project Setup
1. Checkout this project
2. Checkout https://github.com/cima/cima-esp32-components next to the folder with this project (at same level)
3. Clone https://github.com/nopnop2002/esp-idf-mirf also nex to the folder with this project
4. Update [init_cmd.bat](init_cmd.bat)
   - `SET "ESP_TOOLCHAIN_DIR=<path to your ESP directory>"` (hint: It would be named like esp-idf-v5.4 and sits next to directory *.espressif*)
   - `SET "BOOST_ROOT=%ESP_TOOLCHAIN_DIR%/boost_1_85_0"` - change boost version if necessary
5. Open this project in VS Code
6. In VS Code's terminal run the conveninece script [init_cmd.bat](init_cmd.bat)
   - If it complains aboout python virtual anvironment, just type install.bat and it prepares the python virtual env.
   - You shall be presented vith message ending:
        ```
        Go to the project directory and run:

        idf.py build
        ```

## Build

# TO DO
```bat
C:\WINDOWS\system32\cmd.exe /k ""N:\ESP\.espressif\idf_cmd_init.bat" esp-idf-e775469ddabded8dd9fd7a8607dad9e4"
```