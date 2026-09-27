set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(STM32_CPU "cortex-m4" CACHE STRING "ARM Cortex-M CPU for the STM32 build")
find_program(ARM_NONE_EABI_GCC arm-none-eabi-gcc REQUIRED)
find_program(ARM_NONE_EABI_GXX arm-none-eabi-g++ REQUIRED)
find_program(ARM_NONE_EABI_AR arm-none-eabi-ar REQUIRED)

set(CMAKE_C_COMPILER "${ARM_NONE_EABI_GCC}")
set(CMAKE_CXX_COMPILER "${ARM_NONE_EABI_GXX}")
set(CMAKE_AR "${ARM_NONE_EABI_AR}")
set(CMAKE_C_FLAGS_INIT "-mcpu=${STM32_CPU} -mthumb")
set(CMAKE_CXX_FLAGS_INIT "-mcpu=${STM32_CPU} -mthumb -fno-exceptions -fno-rtti")
