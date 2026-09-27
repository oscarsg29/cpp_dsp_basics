ifndef LIBDAISY_DIR
$(error Set LIBDAISY_DIR to your libDaisy checkout)
endif

TARGET = dsp_tests_daisy_seed
CPP_SOURCES = main.cpp ../../tests/test_suite.cpp
CPP_STANDARD = -std=gnu++17
C_INCLUDES += -I../../include
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core

include $(SYSTEM_FILES_DIR)/Makefile
