set(SDL_TEST OFF)
add_subdirectory(SDL SDL_image)

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE SDL3::SDL3)