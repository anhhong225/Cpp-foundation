
add_executable(new_implementation main.cpp message.cpp message_broker.cpp message_reader.cpp)

target_compile_options(new_implementation PRIVATE -Og -Wall -Wextra -Werror -pedantic)

set_target_properties(new_implementation
        PROPERTIES
            LANGUAGE CXX
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
        )