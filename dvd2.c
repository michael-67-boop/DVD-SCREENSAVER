#include <tice.h>
#include <graphx.h>
#include <keypadc.h>

#include "sprite1.h"
#include "sprite2.h"
#include "sprite3.h"
#include "mypalette.h"

#define SPRITE_WIDTH 31
#define SPRITE_HEIGHT 31

int main(void) {
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(mypalette, sizeof_mypalette, 0);

    int x = 0;
    int y = 0;

    int dx = 2;
    int dy = 2;

    gfx_sprite_t *current_sprite = sprite1;

    while (!kb_IsDown(kb_KeyClear)) {
        kb_Scan();

        gfx_FillScreen(gfx_black);

        x += dx;
        y += dy;

        
        if ((x <= 0 || x + SPRITE_WIDTH >= 320) &&
            (y <= 0 || y + SPRITE_HEIGHT >= 240)) {

            dx = -dx;
            dy = -dy;
            current_sprite = sprite1;

        
        } else if (x <= 0 || x + SPRITE_WIDTH >= 320) {

            dx = -dx;
            current_sprite = sprite2;

        
        } else if (y <= 0 || y + SPRITE_HEIGHT >= 240) {

            dy = -dy;
            current_sprite = sprite3;
        }

        gfx_TransparentSprite(current_sprite, x, y);

        gfx_SwapDraw();
        delay(45);
    }

    gfx_End();
    return 0;
}