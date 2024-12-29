#pragma once

#include <string>
#include <list>
#include <map>
#include <functional>

#include <system/Log.h>

namespace cima {
    class Agent {
        static const system::Log LOGGER;

        std::list<std::function<void()>> mainLoopFunctions;

        bool keepRunning = true;

        uint32_t lastRfEventTime;

        public:

            static std::string FLASH_FILESYSTEM_MOUNT_PATH;

            void cat(const std::string &filename);

            //TODO move this to ::cima::system::FlashStorage
            void initFlashStorage();
            //TODO move this to ::cima::system::FlashStorage
            bool mountFlashFileSystem();

            void mainLoop();
            void registerToMainLoop(std::function<void()> function);
            void stop();
    };
}