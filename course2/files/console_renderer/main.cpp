#include "green_renderer.h"
#include "red_renderer.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

    if ( argc != 2 ) {
        std::cerr << "Wrong argument count. usage: text_renderer --backend=\"xxx\"" << std::endl;

        return 1;
    }

    std::string arg_1;
    BaseRenderer * renderer = nullptr;

    arg_1 = argv[1];

    if ( arg_1.substr(0, 9) ==  "--backend" ) {
        if ( arg_1.find("red_renderer") != std::string::npos ) {
            renderer = new RedRenderer();
        } else if ( arg_1.find("green_renderer" ) != std::string::npos ) {
            renderer = new GreenRenderer();
        } else {
            std::cerr << "I don't know that renderer. Try red_renderer or green_renderer" << std::endl;
            return 2;
        }
    }


    renderer->RenderText("Look mom! I'm colored text!");

    return 0;
}
