#include <ncurses.h>

int main() {
  initscr();
  raw();
  mvprintw(15, 15, "Hello fucking world");
  mvprintw(34, 34, "Why Why Why");
  getch();
  endwin();
}
