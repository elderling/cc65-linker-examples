#include <vic20.h>
#include <conio.h>
#include <stdlib.h>

int say_hello( int num );
void init_playfield();
void draw_playfield();

#define PLAYFIELD_X 8
#define PLAYFIELD_Y 8

char playfield[PLAYFIELD_X][PLAYFIELD_Y] ={ 
{'\\','|','{','}','[', ']', 'g', 'h'},
{0x25,'b','c','d','e', 'f', 'g', 'h'},
{'a','b','c','d','e', 'f', 'g', 'h'},
{'a','b','c','d','e', 'f', 'g', 'h'},
{'a','b','c','d','e', 'f', 'g', 'h'},
{'a','b','c','d','e', 'f', 'g', 'h'},
{'a','b','c','d','e', 'f', 'g', 'h'},
{'a','b','c','d','e', 'f', 'g', 'h'},
};

int main(void) {
  unsigned char screen_x;
  unsigned char screen_y;

  screensize( &screen_x, &screen_y);

  //say_hello( 1 );
  clrscr();
  //init_playfield();
  draw_playfield();
  //cprintf("%d, %d", screen_x, screen_y);
  return 0;
}

void init_playfield() {
  unsigned char x;
  for (x = 0; x < PLAYFIELD_X; x++) {
    unsigned char y;
    for (y = 0; y < PLAYFIELD_Y; y++) {
      playfield[x][y] = 'A';
    }
  }
}

void draw_playfield() {

  unsigned char x,y,z;
  for (z = 0; z < 23-8; z++) {
    for (x = 0; x < PLAYFIELD_X; x++) {
      for (y = 0; y < PLAYFIELD_Y; y++) {
        cputcxy(x+z,y+z, playfield[x][y]);
      }
    }
  //clrscr();
  }

  gotoxy(0,19);
  say_hello(1);
  
}

int say_hello( int num ) {
  int i;
  //clrscr();
  for( i = 0; i < num; i++ ) {
    cputs("Hello VIC-20!!!\r\n");
  }

  return 0;
}
