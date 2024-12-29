#include "Agent.h"

#include "sdkconfig.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>

#include <esp_log.h>


#include <driver/gpio.h>
#include <driver/ledc.h>


#include <cJSON.h>

#include <system/Log.h>

#include <system/ExecutionLimiter.h>
#include <system/ButtonController.h>

cima::system::Log logger("main");
cima::Agent agent;
cima::system::ButtonController buttonController(GPIO_NUM_0);
::cima::system::ExecutionLimiter limiter(std::chrono::seconds(1));

extern "C" void app_main(void) { 

    logger.init();
    logger.info("ESP32 Device");
    logger.info("Initializing...");

    agent.initFlashStorage();

    if(agent.mountFlashFileSystem()){
        agent.cat("/spiffs/sheep.txt");
    }

    agent.registerToMainLoop([&](){ 
        if( ! limiter.canExecute()) {
            return;
        }
        //TODO periodic tasks goes here
    });

    logger.info(" > Main loop");
    agent.mainLoop();
}