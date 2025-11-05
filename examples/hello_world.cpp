#include <print>
#include <System.h>
#include <Audio.h>
#include <Graphics.h>

#include <cmath>

int main()
{
    std::println("Hello world");

    AllegroCPP::Display disp(800, 600, "Window test!");
    AllegroCPP::Event_queue ev_qu;

    ev_qu << disp;

    while (disp.valid()) {
        disp.clear_to_color(al_map_rgb(
            140 + static_cast<unsigned char>(cos(al_get_time() * 0.61) * 80),
            140 + static_cast<unsigned char>(cos(al_get_time() * 0.45) * 80),
            140 + static_cast<unsigned char>(cos(al_get_time() * 1.17) * 80)));
        disp.flip();

        if (auto ev = ev_qu.get_next_event(); ev) {
            if (ev.get().type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                disp.destroy();
        }
    }
    

    return 0;
}