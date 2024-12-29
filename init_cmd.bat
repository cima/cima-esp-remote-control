SET "ESP_TOOLCHAIN_DIR=n:\ESP\esp-idf-v5.4"
SET "ESP_PROJECT=%cd%"

SET "CXX=xtensa-esp32-elf-g++"
SET "BOOST_ROOT=%ESP_TOOLCHAIN_DIR%\..\boost_1_85_0"

cd /D %ESP_TOOLCHAIN_DIR%
call ../.espressif/idf_cmd_init.bat

cd /D %ESP_PROJECT%

code .