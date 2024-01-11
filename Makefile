WORK_DIR=$(PWD)
BUILD_DIR=$(WORK_DIR)/build

.PHONY: dependencies build test run_example run_tests clean 

dependencies: clean
	@conan install . --output-folder=$(BUILD_DIR) --build=missing

example: dependencies
	@cd "$(BUILD_DIR)" && \
	cmake .. -DCMAKE_TOOLCHAIN_FILE=$(BUILD_DIR)/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLE=1 -DBUILD_TESTING=0 && \
	cmake --build .

build: dependencies
	@cd "$(BUILD_DIR)" && \
	cmake .. -DCMAKE_TOOLCHAIN_FILE=$(BUILD_DIR)/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLE=0 -DBUILD_TESTING=0 && \
	cmake --build .

tests: dependencies
	@cd "$(BUILD_DIR)" && \
	cmake .. -DCMAKE_TOOLCHAIN_FILE=$(BUILD_DIR)/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLE=0 -DBUILD_TESTING=1 && \
	cmake --build . 

run_example: example
	@clear && cd $(BUILD_DIR)/example && ./example

run_tests: tests
	@clear && cd $(BUILD_DIR)/tests && ./base64url_test

clean:
	@if [ -d $(BUILD_DIR) ]; then rm -r $(BUILD_DIR); fi
	
 
	
