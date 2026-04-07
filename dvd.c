#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>

#include "sprite1.h"
#include "mypalette.h"

#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32

int main(void) {

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(mypalette, sizeof_mypalette, 0);

    srand(rtc_Time());
    
    int x = rand() % (320 - SPRITE_WIDTH);
    int y = rand() % (240 - SPRITE_HEIGHT);

    int dx = 2;
    int dy = 2;

    while (!os_GetCSC()) {
        gfx_FillScreen(0);

        gfx_TransparentSprite(sprite_data, x, y);

        gfx_SwapDraw();

        x += dx;
        y += dy;

        if (x <= 0 || x + SPRITE_WIDTH >= 320) dx = -dx;
        if (y <= 0 || y + SPRITE_HEIGHT >= 240) dy = -dy;

        delay(45);
    }

    gfx_End();
    return 0;
}