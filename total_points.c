const char *const games[10] = {"1:0", "2:0", "3:0", "4:0", "2:1",
                               "3:1", "4:1", "3:2", "4:2", "4:3"};
#include<stdlib.h>
#include<stdio.h>

int points(const char* const games[10]) {
  int counter = 0;
  for( int i = 0; i < 10; i++){
    const char * score = games[i];
    int point_x = atoi(score[0]);
    int point_y = atoi(score[2]);

    if(point_x > point_y)
      counter += 3;
    if(point_x == point_y)
      counter++;
  }

  return counter;
}

int main(){
	printf("%d\n", points(games));
}
